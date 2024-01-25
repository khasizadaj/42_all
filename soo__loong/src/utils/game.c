/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:51:52 by jkhasiza          #+#    #+#             */
/*   Updated: 2024/01/25 03:38:45 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

t_tile	*get_next_tile(t_data *data, int keycode)
{
	int		curr_pos;
	t_tile	*tile;

	curr_pos = 0;
	if (keycode == K_DOWN)
		curr_pos = data->player_pos + data->x_tile_count;
	else if (keycode == K_UP)
		curr_pos = data->player_pos - data->x_tile_count;
	else if (keycode == K_LEFT)
		curr_pos = data->player_pos - 1;
	else if (keycode == K_RIGHT)
		curr_pos = data->player_pos + 1;
	tile = tile_get(&data->tile, curr_pos);
	if (!tile)
		exit_gracefully(data, UNKNOWN_ERR);
	return (tile);
}

int	get_x(t_data *data)
{
	int	x;

	x = (data->player_pos % data->x_tile_count - 1) * 72 + 1;
	return x;
}

int		get_y(t_data *data)
{
	int	x;

	x = (data->player_pos / data->x_tile_count) * 72 + 1;
	return x;
}

int	perform_action(t_data *data, t_tile *tile)
{
	if (tile->type == '1')
		return (0);
	else if (tile->type == 'C')
	{
		tile->type = '0';
		data->collected++;
		ft_printf("Collected money!!! I have %d coins.\n", data->collected);
	}
	else if (tile->type == 'E')
	{
		ft_printf("I am on exit!\n");
		if (data->collected == data->total_coins)
			ft_printf("I can exit.\n");
	} 
	return 1;
}

void	move(t_data *data, int keycode)
{
	t_tile	*next_tile;
	t_tile	*tile;

	next_tile = get_next_tile(data, keycode);
	if (!perform_action(data, next_tile))
		return ;

	tile = tile_new(data, '0');
	if (!tile)
		exit_gracefully(data, MEMORY_ERR);
	mlx_put_image_to_window(data->mlx, data->win, tile->img, get_x(data), get_y(data));
	mlx_destroy_image(data->mlx, tile->img);
	free(tile);

	data->player_pos = next_tile->id;
	tile = tile_new(data, 'P');
	if (!tile)
		exit_gracefully(data, MEMORY_ERR);
	mlx_put_image_to_window(data->mlx, data->win, tile->img, get_x(data), get_y(data));
	mlx_destroy_image(data->mlx, tile->img);
	free(tile);
}