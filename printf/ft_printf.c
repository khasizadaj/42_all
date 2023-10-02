/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 13:43:16 by codespace         #+#    #+#             */
/*   Updated: 2023/10/02 21:18:11 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_placeholder(char *str)
{
	char    *placeholders;

	placeholders = "scdpiuxX%";
	if (str[0] == '%' && chr_in(str[1], placeholders))
		return (1);
	return (0);
}

void	ft_putuint(unsigned int n, int fd)
{
	char	c;

	if (n >= 10)
	{
		ft_putuint(n / 10, fd);
		ft_putuint(n % 10, fd);
	}
	else
	{
		c = n + '0';
		write(fd, &c, 1);
	}
}

void    ft_putmemory(void *arg)
{
	unsigned long long  decimal_value;
	char				*hex;

	if (arg == NULL)
		return ;
	decimal_value = (unsigned long long) arg;
	hex = llu_to_hex(decimal_value, 0);
	if (!hex)
		return ;
	write(1, "0x", 2);
	write(1, hex, ft_strlen(hex));
	free(hex);
}

int	get_length_di(int n)
{
	char	*num_as_str;
	int		len;

	num_as_str = ft_lldtoa(n);
	if (!num_as_str)
		return (0);
	len = ft_strlen(num_as_str);
	return (free(num_as_str), len);
}

int	get_length_u(unsigned int n)
{
	char	*num_as_str;
	int		len;

	num_as_str = ft_utoa(n);
	if (!num_as_str)
		return (0);
	len = ft_strlen(num_as_str);
	return (free(num_as_str), len);
}

int	get_length_p(unsigned long long n)
{
	char	*hex;
	int		len;

	hex = llu_to_hex(n, 0);
	if (!hex)
		return (0);
	len = ft_strlen(hex);
	return (free(hex), len + 2);
}


int	get_length(char type, void *arg)
{
	char	*hex;
	int		len;

	len = 1;
	if (type == 's')
		return (ft_strlen((char *) arg));
	else if (type == 'u')
		return (get_length_u(*((unsigned int *) &arg)));
	else if (chr_in(type, "di"))
		return (get_length_di(*((int *) &arg)));
	else if (chr_in(type, "xX"))
	{
		hex = u_to_hex(*((unsigned int *) &arg), 0);
		if (!hex)
			return (0);
		len = ft_strlen(hex);
		return (free(hex), len);
	}
	else if (type == 'p')
		return (get_length_p(*((unsigned long long *) &arg)));
	return (len);
}

int	dispatch(char type, void *arg)
{
	if (type == 's')
	{
		if (arg == NULL)
			return (ft_putstr_fd("(null)", 1), 6);
		ft_putstr_fd((char *) arg, 1);
	}
	else if (type == 'c')
		ft_putchar_fd(*((char *) &arg), 1);
	else if (type == 'd' || type == 'i')
		ft_putnbr_fd(*((int *) &arg), 1);
	else if (type == 'p')
	{
		if (arg == NULL)
			return (ft_putstr_fd("(nil)", 1), 5);
		ft_putmemory(arg);
	}
	else if (type == 'u')
		ft_putuint(*(unsigned int *) &arg, 1);
	else if (type == 'x')
		ft_puthexlower_fd(*(unsigned int *) &arg, 1);
	else if (type == 'X')
		ft_puthexupper_fd(*(unsigned int *) &arg, 1);
	return (get_length(type, arg));
}

void	format(va_list args, const char *input, int *count)
{
	int	i;
	
	i = 0;
	while (input[i])
	{
		if (is_placeholder((char *) &input[i]))
		{
			if (input[i + 1] != '%')
				*count += dispatch(input[i + 1], va_arg(args, void *));
			else
			{
				ft_putchar_fd('%', 1);
				*count = (*count + 1);
			}
			i += 2;
		}
		else
		{
			ft_putchar_fd(input[i++], 1);
			*count = (*count + 1);
		}
	}
}

int	ft_printf(const char *input, ...)
{
	va_list	args;
	int		written;

	if (!input)
		return (0);
	va_start(args, input);
	written = 0; 
	format(args, input, &written);
	va_end(args);
	return (written);
}

char    *ft_strjoin_on_steroids(int n, ...)
{
	va_list list;
	char    *result;
	char    *prov;

	va_start(list, n);

	result = "";
	int i = 0;
	while (i < n)
	{
		prov = va_arg(list, char *);
		result = ft_strjoin(result, prov);
		if (result == NULL)
			return (NULL);
		i++;
	}
	va_end(list);
	return (result);
}