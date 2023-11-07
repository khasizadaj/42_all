/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 21:23:34 by jkhasiza          #+#    #+#             */
/*   Updated: 2023/10/02 21:30:32 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_length_di(int n)
{
	char	*num_as_str;
	int		len;

	num_as_str = ft_dtoa(n);
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
