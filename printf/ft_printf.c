/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 13:43:16 by codespace         #+#    #+#             */
/*   Updated: 2023/10/01 19:52:19 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_placeholder(char *str)
{
	char    *placeholders;

	placeholders = "scdpiuxX\%";
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
	hex = nbr_to_hex(decimal_value, 0);
	if (!hex)
		return ;
	write(1, "0x", 2);
	write(1, hex, ft_strlen(hex));
}

int	get_length(char type, void *arg)
{
	int		len;
	char	*hex;

	len = 1;
	hex = "";
	if (!arg)
		len = 6;
	{
		if (type == 's')
			len = ft_strlen((char *) arg);
		else if (chr_in(type, "diu"))
			len = ft_strlen(ft_llutoa(*((unsigned long long *) &arg)));
		else if (chr_in(type, "pxX"))
		{
			hex = nbr_to_hex((unsigned long long) arg, 0);
			if (!hex)
				return (0);
			len = ft_strlen(hex);
			if (type == 'p')
				len += 2;
		}
		else if (chr_in(type, "c%"))
			len = 1;
	}
	return (len);
}

int	dispatch(char type, void *arg)
{
	if (arg == NULL)
		ft_putstr_fd("(null)", 1);
	if (type == 's')
		ft_putstr_fd((char *) arg, 1);
	else if (type == 'c')
		ft_putchar_fd(*((char *) &arg), 1);
	else if (type == 'd' || type == 'i')
		ft_putnbr_fd(*((int *) &arg), 1);
	else if (type == 'p')
		ft_putmemory(arg);
	else if (type == 'u')
		ft_putuint(*(unsigned int *) &arg, 1);
	else if (type == 'x')
		ft_puthexlower_fd(arg, 0);
	else if (type == 'X')
		ft_puthexupper_fd(arg, 1);
	else if (type == '%')
		ft_putchar_fd('%', 1);
	return (get_length(type, arg));
}

int	ft_printf(const char *input, ...)
{
	va_list	args;
	int		i;
	void	*next_arg;
	int		written;

	if (!input)
		return (0);
	va_start(args, input);
	i = 0;
	written = 0;
	while (input[i])
	{
		if (is_placeholder((char *) &input[i]))
		{
			next_arg = va_arg(args, void *);
			written += dispatch(input[i + 1], next_arg);
			i += 2;
		}
		else
		{
			ft_putchar_fd(input[++i], 1);
			written++;
		}
	}
	va_end(args);
	return (written);
}

char    *strjoin_on_steroids(int n, ...)
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