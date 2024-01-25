/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:51:52 by jkhasiza          #+#    #+#             */
/*   Updated: 2024/01/25 03:17:25 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	is_wall(t_data *data, int curr_pos)
{
	t_tile	*curr_tile;
	
	curr_tile = tile_get(&data->tile, curr_pos);
	if (!curr_tile)
		exit_gracefully(data, UNKNOWN_ERR);
	if (curr_tile->type == '1')
		return (TRUE);
	return FALSE;
}

int	calculate_next_position(t_data *data, int keycode)
{
	int	curr_pos;

	curr_pos = 0;
	if (keycode == K_DOWN)
		curr_pos = data->player_pos + data->x_tile_count;
	else if (keycode == K_UP)
		curr_pos = data->player_pos - data->x_tile_count;
	else if (keycode == K_LEFT)
		curr_pos = data->player_pos - 1;
	else if (keycode == K_RIGHT)
		curr_pos = data->player_pos + 1;
	if (is_wall(data, curr_pos))
		return 0;
	return (curr_pos);
}

int	get_x(t_data *data)
{
	int	x;

	x = (data->player_pos % data->x_tile_count - 1) * 72 + 1;
	ft_printf("X:%d\n", x);
	return x;
}

int		get_y(t_data *data)
{
	int	x;

	x = (data->player_pos / data->x_tile_count) * 72 + 1;
	ft_printf("Y:%d\n", x);
	return x;
}

void	move(t_data *data, int keycode)
{
	int		next_pos;
	t_tile	*tile;

	next_pos = calculate_next_position(data, keycode);
	if (!next_pos)
		return ;
	tile = tile_new(data, '0');
	if (!tile)
		exit_gracefully(data, MEMORY_ERR);
	mlx_put_image_to_window(data->mlx, data->win, tile->img, get_x(data), get_y(data));
	mlx_destroy_image(data->mlx, tile->img);
	free(tile);

	data->player_pos = next_pos;
	ft_printf("player_pos %d\n", data->player_pos);
	tile = tile_new(data, 'P');
	if (!tile)
		exit_gracefully(data, MEMORY_ERR);
	mlx_put_image_to_window(data->mlx, data->win, tile->img, get_x(data), get_y(data));
	mlx_destroy_image(data->mlx, tile->img);
	free(tile);
}