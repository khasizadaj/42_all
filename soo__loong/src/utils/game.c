/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:51:52 by jkhasiza          #+#    #+#             */
/*   Updated: 2024/01/25 21:25:02 by jkhasiza         ###   ########.fr       */
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

int	get_x(int position, int x_tile_count)
{
	int	x;

	x = (position % x_tile_count - 1) * 72;
	return x;
}

int		get_y(int position, int x_tile_count)
{
	int	x;

	x = (position / x_tile_count) * 72;
	return x;
}

int	perform_action(t_data *data, t_tile *tile)
{
	if (tile->type == 'C')
	{
		tile->type = '0';
		data->collected++;
		ft_printf("Collected money!!! I have %d coins.\n", data->collected);
		if (data->collected == data->total_coins)
		{
			ft_printf("Exit is open @ %d!\n", data->exit);
			mlx_put_image_to_window(data->mlx, data->win,
				asset_get_by_type(&data->assets, 'E'), get_x(data->exit, data->x_tile_count), get_y(data->exit, data->x_tile_count));
		}	
	}
	else if (tile->type == 'E' && data->collected == data->total_coins)
	{
		exit_gracefully(data, UNKNOWN_ERR);
	}
	else if (tile->type == '1' || tile->type == 'E')
		return (0);
	return 1;
}

void	move(t_data *data, int keycode)
{
	t_tile	*next_tile;
	void	*img;

	next_tile = get_next_tile(data, keycode);
	if (!perform_action(data, next_tile))
		return ;
	img = asset_get_by_type(&data->assets, '0');
	mlx_put_image_to_window(data->mlx, data->win, img, get_x(data->player_pos, data->x_tile_count), get_y(data->player_pos, data->x_tile_count));
	data->player_pos = next_tile->id;
	img = asset_get_by_type(&data->assets, 'P');
	mlx_put_image_to_window(data->mlx, data->win, img, get_x(data->player_pos, data->x_tile_count), get_y(data->player_pos, data->x_tile_count));
}