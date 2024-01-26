/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_map_validation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 22:36:16 by jkhasiza          #+#    #+#             */
/*   Updated: 2024/01/26 23:14:43 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_validation.h"

int	test_has_invalid_characters(void)
{
	char *str;

	str = "10CLL111x1";
	if (is_valid_line(str, 10) == FALSE)
		return (0);
	else
	 	return (-1);
}

int	test_line_is_longer_than_expected(void)
{
	char *str;

	str = "10CLL11111";
	if (is_valid_line(str, 9) == FALSE)
		return (0);
	else
	 	return (-1);
}

int	test_line_is_valid(void)
{
	char *str;

	str = "10CPP11111";
	if (is_valid_line(str, 10) == TRUE)
		return (0);
	else
	 	return (-1);
}