/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 17:09:07 by jkhasiza          #+#    #+#             */
/*   Updated: 2024/03/08 20:14:11 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	update_collected_coins(t_data *data)
{
	data->collected++;
	if (data->collected == data->total_coins)
	{
		mlx_put_image_to_window(data->mlx, data->win,
			asset_get_by_type(&data->assets, 'E'),
			get_x(data->exit, data->x_count),
			get_y(data->exit, data->x_count));
	}
}

int	perform_attack(t_data *data, t_tile *next_tile, char direction)
{
	if (chr_in(next_tile->type, "1E") == 1)
		return (0);
	else if (next_tile->type == 'V')
	{
		if (direction == 'R')
			data->attack = "1VR";
		else if (direction == 'L')
			data->attack = "1VL";
		next_tile->type = '0';
	}
	else
	{
		if (direction == 'R')
			data->attack = "10R";
		else if (direction == 'L')
			data->attack = "10L";
		if (next_tile->type != '0')
		{
			if (next_tile->type == 'C')
				update_collected_coins(data);
			next_tile->type = '0';
		}
	}
	return (1);
}

int	perform_move(t_data *data, t_tile *tile)
{
	data->move_count++;
	ft_printf("Curr move count: %d\n", data->move_count);
	if (tile->type == 'C')
	{
		tile->type = '0';
		update_collected_coins(data);
	}
	else if (tile->type == 'E' && data->collected == data->total_coins)
	{
		exit_gracefully(data, END_GAME_WIN);
	}
	else if (chr_in(tile->type, "BV") == 1)
		exit_gracefully(data, END_GAME_YOU_ARE_DEAD);
	else if (tile->type == '1')
		return (0);
	return (1);
}

int	get_x(int position, int x_tile_count)
{
	int	x;

	x = (position % x_tile_count - 1) * 72;
	return (x);
}

int	get_y(int position, int x_tile_count)
{
	int	y;

	y = (position / x_tile_count) * 72 + 72;
	return (y);
}
