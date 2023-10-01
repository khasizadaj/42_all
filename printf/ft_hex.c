/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 18:50:16 by jkhasiza          #+#    #+#             */
/*   Updated: 2023/10/01 23:29:59 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthexlower_fd(void *arg, int fd)
{
	unsigned long long	decimal_value;
	char				*hex;

	decimal_value = (unsigned long long) arg;
	hex = nbr_to_hex(decimal_value, 0);
	// printf("HELLO");
	// printf("\nlen=%zu; s=%s\n", ft_strlen(hex), hex);
	if (!hex)
		return ;
	write(fd, hex, ft_strlen(hex));
	free(hex);
}

void	ft_puthexupper_fd(void *arg, int fd)
{
	unsigned long long	decimal_value;
	char				*hex;

	if (arg == NULL)
		return ;
	decimal_value = (unsigned long long) arg;
	hex = nbr_to_hex(decimal_value, 1);
	printf("\nd=%llu; s=%s\n", decimal_value, hex);
	if (!hex)
		return ;
	write(fd, hex, ft_strlen(hex));
	free(hex);
}