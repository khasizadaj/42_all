/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 20:30:10 by jkhasiza          #+#    #+#             */
/*   Updated: 2024/02/04 19:50:41 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

bool	init_assets(t_data *data)
{
	char	*str_map;
	int		i;
	t_tile	*tile;

	i = -1;
	str_map = ALLOWED_CHARACTERS;
	while (str_map[++i])
	{
		tile = tile_new(data, str_map[i], FALSE);
		if (!tile)
			return false;
		tile_add_back(&data->assets, tile);
	}
	return (true);
}

void	init_data(t_data *data)
{
	data->x_count = 0;
	data->y_count = 0;
	data->collected = 0;
	data->height = 0;
	data->width = 0;
	data->side_length = SIDE_LEN;
	data->player_pos = -1;
	data->exit = 1;
	data->exit_code = 0;
	data->tile = NULL;
	data->win = NULL;
	data->mlx = NULL;
	data->assets = NULL;
}

void	enhance_data(t_data *data, char *map_str)
{
	data->height = data->y_count * data->side_length + 72;
	data->width = data->x_count * data->side_length;
	data->total_coins = ft_count_char(map_str, 'C');
	data->mlx = mlx_init();
	if (!data->mlx)
		exit_gracefully(data, MEMORY_ERR);
	data->win = mlx_new_window(data->mlx, data->width, 
		data->height, PROGRAM_NAME);
	if (!data->win)
		exit_gracefully(data, MEMORY_ERR);
	if (!init_assets(data))
	{
		free(map_str);
		exit_gracefully(data, MEMORY_ERR);
	}
}

void	init_map(t_data *data, char *map_str)
{
	t_tile	*tile;
	int		i;
	int		x;
	int		y;

	i = 0;
	x = 0;
	y = 72;
	while (map_str[i])
	{
		if (i % data->x_count == 0 && i != 0)
		{
			x = 0;
			y += 72;
		}
		if (map_str[i] == 'P')
			data->player_pos = i + 1;
		else if (map_str[i] == 'E')
		{
			tile = tile_new(data, 'E', TRUE);
			if (!tile)
				exit_gracefully(data, MEMORY_ERR);
			tile_add_back(&data->tile, tile);
			data->exit = tile->id;
			mlx_put_image_to_window(data->mlx, data->win,
				asset_get_by_type(&data->assets, '0'), x, y);
			i++;
			x += 72;
			continue ;
		}
		tile = draw_tile(data, x, y, map_str[i]);		
		if (!tile)
			exit_gracefully(data, MEMORY_ERR);

		i++;
		x += 72;
	}
}

int	main(int argc, char **argv)
{
	t_data	data;
	char	*map_str;

	if (argc != 2)
		exit_for(INVALID_MAP_NO_MAP);
	if (!ft_str_endswith(argv[1], MAP_EXTENSION))
		exit_for(INVALID_MAP_WRONG_FILE_TYPE);
	init_data(&data);
	map_str = get_map(&data, argv[1], &data.x_count, &data.y_count);
	if (!map_str || is_valid_map(&data, map_str) != 0
		|| has_valid_path(&data, map_str) == false)
	{
		free(map_str);	
		exit_gracefully(&data, data.exit_code);
	}
	enhance_data(&data, map_str);
	init_map(&data, map_str);
	if (!data.tile)
		exit_gracefully(&data, MEMORY_ERR);
	mlx_hook(data.win, 2, 1L, 
		key_hook, &data);
	mlx_loop(data.mlx);
	return (0);
}
