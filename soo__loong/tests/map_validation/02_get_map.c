/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_get_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 22:36:16 by jkhasiza          #+#    #+#             */
/*   Updated: 2024/01/28 00:45:34 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_validation.h"

int	test_file_name_dont_exist(void)
{
	char *filename;

	filename = "random_file_name.ber";
	if (get_map(filename) == NULL)
		return (0);
	else
	 	return (-1);
}

int	test_map_is_valid_4x4(void)
{
	char *filename;
	char *map;

	filename = "./maps/valid_4x4.ber";
	map = get_map(filename);
	if (map == NULL)
		return (-1);
	if (ft_strlen(map) == 16 && is_valid_line(map, -1) == TRUE)
		return (free(map), 0);
	else
	 	return (-1);
}

int	test_map_is_valid_5x5(void)
{
	char *filename;
	char *map;

	filename = "./maps/valid_5x5.ber";
	map = get_map(filename);
	if (map == NULL)
		return (-1);
	if (ft_strlen(map) == 25 && is_valid_line(map, -1) == TRUE)
		return (free(map), 0);
	else
	 	return (-1);
}

int	test_map_has_invalid_first_line(void)
{
	char *filename;
	char *map;

	filename = "./maps/invalid_first_line_5x5.ber.ber";
	map = get_map(filename);
	if (map == NULL)
		return (0);
	else
	 	return (-1);
}

int	test_map_has_invalid_body(void)
{
	char *filename;
	char *map;

	filename = "./maps/invalid_body_5x5.ber";
	map = get_map(filename);
	if (map == NULL)
		return (0);
	else
	 	return (-1);
}