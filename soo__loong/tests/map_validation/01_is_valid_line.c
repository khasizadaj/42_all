/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_is_valid_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 22:36:16 by jkhasiza          #+#    #+#             */
/*   Updated: 2024/01/27 22:40:04 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_validation.h"

int	test_has_invalid_characters(void)
{
	char *str;

	str = "10C\nLL111x1";
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

int	test_whole_line_is_valid_without_size_limit(void)
{
	char *str;

	str = "10CPP1111110CPP1111110CPP1111110CPP1111110CPP1111110CPP11111";
	if (is_valid_line(str, -1) == TRUE)
		return (0);
	else
	 	return (-1);
}

int	test_whole_line_is_invalid_without_size_limit(void)
{
	char *str;

	str = "///1111110CPP1111110CPP1111110CPP1111110CPP1111110CPP11111";
	if (is_valid_line(str, -1) == FALSE)
		return (0);
	else
	 	return (-1);
}

int	test_line_is_null(void)
{
	char *str;

	str = NULL;
	if (is_valid_line(str, 10) == FALSE)
		return (0);
	else
	 	return (-1);
}