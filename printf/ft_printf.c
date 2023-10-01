/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 13:43:16 by codespace         #+#    #+#             */
/*   Updated: 2023/10/01 23:26:20 by jkhasiza         ###   ########.fr       */
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
	free(hex);
}

int	get_length(char type, void *arg)
{
	char	*hex;
	char	*num_as_str;
	int		len;

	len = 1;
	if (type == 's')
		return (ft_strlen((char *) arg));
	else if (chr_in(type, "diu"))
	{
		num_as_str = ft_lldtoa(*((int *) &arg));
		if (!num_as_str)
			return (0);
		len = ft_strlen(num_as_str);
		return (free(num_as_str), len);
	}
	else if (chr_in(type, "pxX"))
	{
		hex = nbr_to_hex((unsigned long long) arg, 0);
		if (!hex)
			return (0);
		len = ft_strlen(hex);
		if (type == 'p')
			return (free(hex), len + 2);
		return (free(hex), len);
	}
	return (1);
}

int	dispatch(char type, void *arg)
{
	if (type == 's')
	{
		if (arg == NULL && type == 's')
			return (ft_putstr_fd("(null)", 1), 6);
		ft_putstr_fd((char *) arg, 1);
	}
	else if (type == 'c')
		ft_putchar_fd(*((char *) &arg), 1);
	else if (type == 'd' || type == 'i')
		ft_putnbr_fd(*((int *) &arg), 1);
	else if (type == 'p')
	{
		if (arg == NULL && type == 'p')
			return (ft_putstr_fd("(nil)", 1), 5);
		ft_putmemory(arg);
	}
	else if (type == 'u')
		ft_putuint(*(unsigned int *) &arg, 1);
	else if (type == 'x')
		ft_puthexlower_fd(arg, 1);
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
			written += dispatch(input[i + 1], va_arg(args, void *));
			i += 2;
		}
		else
		{
			ft_putchar_fd(input[i++], 1);
			written++;
		}
	}
	va_end(args);
	return (written);
}

// void	dispatch_2(char type, va_list args, int *count)
// {
// 	if (type == 's')
// 	{
// 		ft_putstr_count(va_arg(args, char *), count);
// 	}
// 	else if (type == 'c')
// 		ft_putchar_fd(*((char *) &arg), 1);
// 	else if (type == 'd' || type == 'i')
// 		ft_putnbr_fd(*((int *) &arg), 1);
// 	else if (type == 'p')
// 		ft_putmemory(arg);
// 	else if (type == 'u')
// 		ft_putuint(*(unsigned int *) &arg, 1);
// 	else if (type == 'x')
// 		ft_puthexlower_fd(arg, 0);
// 	else if (type == 'X')
// 		ft_puthexupper_fd(arg, 1);
// 	else if (type == '%')
// 		ft_putchar_fd('%', 1);
// 	return (get_length(type, arg));
// }

// int	ft_printf(const char *input, ...)
// {
// 	va_list	args;
// 	int		i;
// 	int		written;

// 	if (!input)
// 		return (0);
// 	va_start(args, input);
// 	i = 0;
// 	written = 0;
// 	while (input[i])
// 	{
// 		if (is_placeholder((char *) &input[i]))
// 		{
// 			written += dispatch_2(input[i + 1], args, &written);
// 			i += 2;
// 		}
// 		else
// 		{
// 			ft_putchar_fd(input[i++], 1);
// 			written++;
// 		}
// 	}
// 	va_end(args);
// 	return (written);
// }

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