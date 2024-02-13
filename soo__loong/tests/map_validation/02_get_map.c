/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_get_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 22:36:16 by jkhasiza          #+#    #+#             */
/*   Updated: 2024/02/03 12:41:02 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_validation.h"

int	test_file_name_dont_exist(void)
{
	char	*filename;
	int		x_tile_count;
	int		y_tile_count;
	t_data	data;

	data.exit_code = 0;
	filename = "random_file_name.ber";
	x_tile_count = 0;
	y_tile_count = 0;
	if (get_map(&data, filename, &x_tile_count, &y_tile_count) == NULL
		&& x_tile_count == 0 && y_tile_count == 0)
		return (0);
	else
	 	return (-1);
}

int	test_map_has_valid_lines_4x4(void)
{
	char *filename;
	char *map;
	int		x_tile_count;
	int		y_tile_count;
	t_data	data;

	data.exit_code = 0;
	filename = "./maps/valid_4x4.ber";
	map = get_map(&data, filename, &x_tile_count, &y_tile_count);
	if (map == NULL)
		return (-1);
	if (ft_strlen(map) == 16 && is_valid_line(map, -1) == TRUE
		&& x_tile_count == 4 && y_tile_count == 4)
		return (free(map), 0);
	else
	 	return (-1);
}

int	test_map_has_valid_lines_5x5(void)
{
	char	*filename;
	char	*map;
	int		x_tile_count;
	int		y_tile_count;
	t_data	data;

	data.exit_code = 0;
	filename = "./maps/valid_5x5.ber";
	map = get_map(&data, filename, &x_tile_count, &y_tile_count);
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
	t_data	data;

	data.exit_code = 0;
	filename = "./maps/invalid_first_line_5x5.ber.ber";
	map = get_map(&data, filename, &x_tile_count, &y_tile_count);
	if (map == NULL)
		return (0);
	else
	 	return (-1);
}

int	test_map_has_invalid_body(void)
{
	char	*filename;
	char	*map;
	int		x_tile_count;
	int		y_tile_count;
	t_data	data;

	data.exit_code = 0;
	filename = "./maps/invalid_body_5x5.ber";
	map = get_map(&data, filename, &x_tile_count, &y_tile_count);
	if (map == NULL)
		return (0);
	else
	 	return (-1);
}

int	test_map_has_missing_wall(void)
{
	char	*filename;
	char	*map;
	t_data	data;

	filename = "./maps/invalid_missing_wall.ber";
	data.x_count = 0;
	data.y_count = 0;
	map = get_map(&data, filename, &data.x_count, &data.y_count);
	if (is_valid_map(&data , map) == INVALID_MAP_WRONG_WALLS)
	{
		free(map);
		return (0);
	}
	else
	 	return (-1);
}

int	test_map_has_missing_wall_on_sides(void)
{
	char	*filename;
	char	*map;
	t_data	data;

	filename = "./maps/invalid_missing_wall_2.ber";
	data.x_count = 0;
	data.y_count = 0;
	map = get_map(&data, filename, &data.x_count, &data.y_count);
	if (is_valid_map(&data , map) == INVALID_MAP_WRONG_WALLS)
	{
		free(map);
		return (0);
	}
	else
	 	return (-1);
}

int	test_map_has_many_exits(void)
{
	char	*filename;
	char	*map;
	t_data	data;

	filename = "./maps/invalid_many_exits.ber";
	data.x_count = 0;
	data.y_count = 0;
	map = get_map(&data, filename, &data.x_count, &data.y_count);
	if (is_valid_map(&data , map) == INVALID_MAP_INCORRECT_COMPONENT)
	{
		free(map);
		return (0);
	}
	else
	 	return (-1);
}

int	test_map_has_many_players(void)
{
	char	*filename;
	char	*map;
	t_data	data;

	filename = "./maps/invalid_many_players.ber";
	data.x_count = 0;
	data.y_count = 0;
	map = get_map(&data, filename, &data.x_count, &data.y_count);
	if (is_valid_map(&data , map) == INVALID_MAP_INCORRECT_COMPONENT)
	{
		free(map);
		return (0);
	}
	else
	 	return (-1);
}
/*
	At this point this is already handled, but this function can handle
	or invalidate if map is not rectangular.
*/
int	test_map_is_not_rectangle(void)
{
	char	*map;
	t_data	data;

	data.x_count = 3;
	data.y_count = 5;
	map = "1111C1E11P1111";
	if (is_valid_map(&data , map) == INVALID_MAP_NOT_RECTANGLE)
	{
		return (0);
	}
	else
	 	return (-1);
}

int	test_map_has_no_valid_path(void)
{
	char	*filename;
	char	*map;
	t_data	data;


	data.x_count = 3;
	data.y_count = 6;
	data.player_pos = 5;
	filename = "./maps/invalid_exit_not_reachable.ber";
	map = get_map(&data, filename, &data.x_count, &data.y_count);
	if (has_valid_path(&data, map) != TRUE)
		return (0);
	else
	 	return (-1);
}

int	test_map_has_no_valid_path_cannot_collect_all(void)
{
	char	*filename;
	char	*map;
	t_data	data;


	data.x_count = 3;
	data.y_count = 6;
	data.player_pos = 5;
	filename = "./maps/invalid_cannot_collect_all.ber";
	map = get_map(&data, filename, &data.x_count, &data.y_count);
	if (has_valid_path(&data, map) != TRUE)
		return (0);
	else
	 	return (-1);
}

int	test_map_has_no_valid_path_complex(void)
{
	char	*filename;
	char	*map;
	t_data	data;


	data.x_count = 8;
	data.y_count = 8;
	data.player_pos = 27;
	filename = "./maps/invalid_path_complex.ber";
	map = get_map(&data, filename, &data.x_count, &data.y_count);
	if (has_valid_path(&data, map) != TRUE)
		return (0);
	else
	 	return (-1);
}

int	test_map_has_valid_path_simple(void)
{
	char	*filename;
	char	*map;
	t_data	data;


	data.x_count = 5;
	data.y_count = 5;
	data.player_pos = 12;
	filename = "./maps/valid_path_simple.ber";
	map = get_map(&data, filename, &data.x_count, &data.y_count);
	if (has_valid_path(&data, map) == TRUE)
		return (0);
	else
	 	return (-1);
}

int	test_map_has_valid_path_complex(void)
{
	char	*filename;
	char	*map;
	t_data	data;


	data.x_count = 8;
	data.y_count = 8;
	data.player_pos = 27;
	filename = "./maps/valid_path_complex.ber";
	map = get_map(&data, filename, &data.x_count, &data.y_count);
	if (has_valid_path(&data, map) == TRUE)
		return (0);
	else
	 	return (-1);
}
