/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 20:30:10 by jkhasiza          #+#    #+#             */
/*   Updated: 2024/01/25 04:42:16 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "libft/libft.h"

void	init_assets(t_data *data)
{
	char	*str_map;
	int		i;
	t_tile	*tile;

	i = -1;
	str_map = "1E0CP";
	while (str_map[++i])
	{
		tile = tile_new(data, str_map[i]);
		ft_printf("%c type\n", tile->type);
		if (!tile)
			exit_gracefully(data, MEMORY_ERR);
		tile_add_back(&data->assets, tile);
	}
}

void	init_data(t_data *data)
{
	data->x_tile_count = 5;
	data->y_tile_count = 4;
	data->collected = 0;
	data->total_coins = 2;
	data->height = HEIGHT;
	data->width = WIDTH;
	data->side_length = SIDE_LENGTH;
	data->player_pos = 0;
	data->tile = NULL;
	data->win = NULL;
	data->mlx = NULL;
	data->assets = NULL;
	data->mlx = mlx_init();
	if (!data->mlx)
		exit_gracefully(data, MEMORY_ERR);
	init_assets(data);
	data->win = mlx_new_window(data->mlx, data->width, 
		data->height, PROGRAM_NAME);
	if (!data->win)
		exit_gracefully(data, MEMORY_ERR);
}

void	init_map(t_data *data, char *filename)
{
	t_tile	*tile;
	char	*str_map;
	int		i;
	int		x;
	int		y;

	ft_printf("%s\n", filename);
	str_map = "111111C0P11C0E111111";
	i = 0;
	x = 0;
	y = 0;
	while (str_map[i])
	{
		if (i % 5 == 0 && i != 0)
		{
			x = 0;
			y += 72;
		}
		if (str_map[i] == 'P')
			data->player_pos = i + 1;
		tile = draw_tile(data, x, y, str_map[i]);
		if (!tile)
			exit_gracefully(data, MEMORY_ERR);
		i++;
		x += 72;
	}
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		exit_for(INVALID_MAP_NO_MAP);
	if (!ft_str_endswith(argv[1], MAP_EXTENSION))
		exit_for(INVALID_MAP_WRONG_FILE_TYPE);
	init_data(&data);
	// TODO REad from file and pass string to `init_map` instead.
	init_map(&data, argv[1]);
	if (!data.tile)
		exit_gracefully(&data, MEMORY_ERR);
	mlx_hook(data.win, 2, 1L, 
		key_hook, &data);
	mlx_loop(data.mlx);
	return (0);
}
