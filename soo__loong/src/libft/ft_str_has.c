/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_has.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 20:42:11 by jkhasiza          #+#    #+#             */
/*   Updated: 2024/01/18 22:08:39 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool	ft_str_has(char *str, char *lookup)
{
	int	x_1;
	int	x_2;

	x_1 = -1;
	while (str[++x_1])
	{
		x_2 = -1;
		while (lookup[++x_2])
		{
			if (str[x_1 + x_2] != lookup[x_2])
			{
				break ;
			}
		}
		if (lookup[x_2] == '\0')
			return (TRUE);
	}
	return (FALSE);
}
