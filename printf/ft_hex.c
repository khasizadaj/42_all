/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 18:50:16 by jkhasiza          #+#    #+#             */
/*   Updated: 2023/10/02 19:17:26 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthexlower_fd(unsigned int n, int fd)
{
	char	*hex;

	hex = u_to_hex(n, 0);
	if (!hex)
		return ;
	write(fd, hex, ft_strlen(hex));
	free(hex);
}

void	ft_puthexupper_fd(unsigned int n, int fd)
{
	char	*hex;

	hex = u_to_hex(n, 1);
	if (!hex)
		return ;
	write(fd, hex, ft_strlen(hex));
	free(hex);
}