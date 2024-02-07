/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:22:09 by jkhasiza          #+#    #+#             */
/*   Updated: 2024/02/07 17:21:05 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Checks if a string contains only digits.
 *
 * @param str The string to be checked.
 * @return TRUE if the string contains only digits, FALSE otherwise.
 */
bool	ft_str_isdigit(char *str)
{
	int		i;

	if (!str)
		return (FALSE);
	if (ft_strlen(str) == 0)
		return (FALSE);
	i = 0;
	while (ft_isspace(str[i]) == true)
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			return (false);
		i++;
	}
	if (ft_strlen(str) == 1 && ft_isdigit(str[0]) == 0)
		return (false);
	return (true);
}
