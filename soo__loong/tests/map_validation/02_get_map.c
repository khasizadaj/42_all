/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_get_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 22:36:16 by jkhasiza          #+#    #+#             */
/*   Updated: 2024/01/28 01:24:01 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_validation.h"

int	test_file_name_dont_exist(void)
{
	char	*filename;
	int		x_tile_count;
	int		y_tile_count;

	filename = "random_file_name.ber";
	x_tile_count = 0;
	y_tile_count = 0;
	if (get_map(filename, &x_tile_count, &y_tile_count) == NULL
		&& x_tile_count == 0 && y_tile_count == 0)
		return (0);
	else
	 	return (-1);
}

int	test_map_is_valid_4x4(void)
{
	char *filename;
	char *map;
	int		x_tile_count;
	int		y_tile_count;

	filename = "./maps/valid_4x4.ber";
	map = get_map(filename, &x_tile_count, &y_tile_count);
	if (map == NULL)
		return (-1);
	if (ft_strlen(map) == 16 && is_valid_line(map, -1) == TRUE
		&& x_tile_count == 4 && y_tile_count == 4)
		return (free(map), 0);
	else
	 	return (-1);
}

int	test_map_is_valid_5x5(void)
{
	char *filename;
	char *map;
	int		x_tile_count;
	int		y_tile_count;

	filename = "./maps/valid_5x5.ber";
	map = get_map(filename, &x_tile_count, &y_tile_count);
	if (map == NULL)
		return (-1);
	if (ft_strlen(map) == 25 && is_valid_line(map, -1) == TRUE
		&& x_tile_count == 5 && y_tile_count == 5)
		return (free(map), 0);
	else
	 	return (-1);
}

int	test_map_has_invalid_first_line(void)
{
	char	*filename;
	char	*map;
	int		x_tile_count;
	int		y_tile_count;

	filename = "./maps/invalid_first_line_5x5.ber.ber";
	map = get_map(filename, &x_tile_count, &y_tile_count);
	if (map == NULL)
		return (0);
	else
	 	return (-1);
}

int	test_map_has_invalid_body(void)
{
	char *filename;
	char *map;
	int		x_tile_count;
	int		y_tile_count;

	filename = "./maps/invalid_body_5x5.ber";
	map = get_map(filename, &x_tile_count, &y_tile_count);
	if (map == NULL)
		return (0);
	else
	 	return (-1);
}