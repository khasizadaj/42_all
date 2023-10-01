/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 18:50:16 by jkhasiza          #+#    #+#             */
/*   Updated: 2023/10/01 18:50:50 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthexlower_fd(void *arg, int fd)
{
	unsigned long long	decimal_value;
	char				*hex;

	if (arg == NULL)
		return ;
	decimal_value = (unsigned long long) arg;
	hex = nbr_to_hex(decimal_value, 0);
	if (!hex)
		return ;
	write(fd, hex, ft_strlen(hex));
}

void	ft_puthexupper_fd(void *arg, int fd)
{
	unsigned long long	decimal_value;
	char				*hex;

	if (arg == NULL)
		return ;
	decimal_value = (unsigned long long) arg;
	hex = nbr_to_hex(decimal_value, 1);
	if (!hex)
		return ;
	write(fd, hex, ft_strlen(hex));
}