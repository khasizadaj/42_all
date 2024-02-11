/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:51:52 by jkhasiza          #+#    #+#             */
/*   Updated: 2024/02/11 19:42:02 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

t_tile	*get_next_tile(t_data *data, int keycode)
{
	int		curr_pos;
	t_tile	*tile;

	curr_pos = 0;
	if (keycode == K_DOWN)
		curr_pos = data->player_pos + data->x_count;
	else if (keycode == K_UP)
		curr_pos = data->player_pos - data->x_count;
	else if (keycode == K_LEFT || keycode == K_Q)
		curr_pos = data->player_pos - 1;
	else if (keycode == K_RIGHT || keycode == K_E)
		curr_pos = data->player_pos + 1;
	tile = tile_get(&data->tile, curr_pos);
	if (!tile)
		exit_gracefully(data, UNKNOWN_ERR);
	return (tile);
}

void	move(t_data *data, int keycode)
{
	t_tile	*next_tile;
	void	*img;
	char	type;

	next_tile = get_next_tile(data, keycode);
	if (!perform_move(data, next_tile))
		return ;
	img = asset_get_by_type(&data->assets, '0');
	mlx_put_image_to_window(data->mlx, data->win, img,
		get_x(data->player_pos, data->x_count),
		get_y(data->player_pos, data->x_count));
	data->player_pos = next_tile->id;
	type = 'P';
	if (keycode == K_LEFT)
		type = 'p';
	img = asset_get_by_type(&data->assets, type);
	mlx_put_image_to_window(data->mlx, data->win, img,
		get_x(data->player_pos, data->x_count),
		get_y(data->player_pos, data->x_count));
}

void	attack(t_data *data, int keycode)
{
	t_tile	*next_tile;
	char	direction;

	direction = 'R';
	next_tile = get_next_tile(data, keycode);
	if (keycode == K_E)
		direction = 'R';
	else if (keycode == K_Q)
		direction = 'L';
	if (!perform_attack(data, next_tile, direction))
		return ;
}
