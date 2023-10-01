/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_to_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 14:40:30 by codespace         #+#    #+#             */
/*   Updated: 2023/10/01 23:30:09 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*build_hex_string(char reversed_result[17], int size)
{
	char	*final_result;
	int		i;

	final_result = (char *) malloc(size + 1);
	if (!final_result)
		return (NULL);
	i = 0;
	while (i < size)
	{
		final_result[i] = reversed_result[size - 1 - i];
		i++;
	}
	final_result[size] = '\0';
	return (final_result);
}

char	*nbr_to_hex(unsigned long long n, int lowercase)
{
	char	*hex_string;
	char	result[17];
	int		index;
	char	*final_result;

	hex_string = "0123456789abcdef";
	index = 0;
	if (n == 0)
		result[index++] = '0';
	while (n)
	{
		if (lowercase == 0)
			result[index++] = ft_tolower(hex_string[n % 16]);
		else if (lowercase == 1)
			result[index++] = ft_toupper(hex_string[n % 16]);
		n /= 16;
	}
	result[index] = '\0';
	final_result = build_hex_string(result, index);
	if (!final_result)
		return (NULL);
	return (final_result);
}
