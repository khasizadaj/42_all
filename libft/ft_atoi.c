/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 18:17:35 by codespace         #+#    #+#             */
/*   Updated: 2023/09/22 17:07:33 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isspace(int c)
{
	if ((char) c != '\f' && (char) c != '\n' && (char) c != '\r'
		&& (char) c != '\t' && (char) c != '\v' && (char) c != 32
		&& (char) c != ' ')
		return (0);
	return (1);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	n;

	i = 0;
	sign = 1;
	while (ft_isspace(nptr[i]))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	n = 0;
	while (ft_isdigit(nptr[i]) > 0)
	{
		n = n * 10 + (nptr[i] - '0');
		i++;
	}
	return (n * sign);
}
