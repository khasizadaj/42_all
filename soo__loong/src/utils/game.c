/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:51:52 by jkhasiza          #+#    #+#             */
/*   Updated: 2024/02/11 16:53:02 by jkhasiza         ###   ########.fr       */
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
	return (x);
}

int	get_y(int position, int x_tile_count)
{
	int	y;

	y = (position / x_tile_count) * 72 + 72;
	return (y);
}

void update_collected_coins(t_data *data)
{
	if (tile->type == 'C')
	{
		tile->type = '0';
	data->collected++;
	if (data->collected == data->total_coins)
	{
		mlx_put_image_to_window(data->mlx, data->win,
			asset_get_by_type(&data->assets, 'E'),
			get_x(data->exit, data->x_count),
			get_y(data->exit, data->x_count));
	}
}


int	perform_move(t_data *data, t_tile *tile)
{
	if (tile->type == 'C')
	{
		tile->type = '0';
		update_collected_coins(data);
	}
	else if (tile->type == 'E' && data->collected == data->total_coins)
	{
		exit_gracefully(data, END_GAME_WIN);
	}
	else if (tile->type == 'B')
		exit_gracefully(data, END_GAME_YOU_ARE_DEAD);
	else if (tile->type == '1')
		return (0);
	data->move_count++;
	ft_printf("Curr move count: %d\n", data->move_count);
	return (1);
}

void	move(t_data *data, int keycode)
{
	t_tile	*next_tile;
	void	*img;

	next_tile = get_next_tile(data, keycode);
	if (!perform_move(data, next_tile))
		return ;
	img = asset_get_by_type(&data->assets, '0');
	mlx_put_image_to_window(data->mlx, data->win, img,
		get_x(data->player_pos, data->x_count),
		get_y(data->player_pos, data->x_count));
	data->player_pos = next_tile->id;
	img = asset_get_by_type(&data->assets, 'P');
	mlx_put_image_to_window(data->mlx, data->win, img,
		get_x(data->player_pos, data->x_count),
		get_y(data->player_pos, data->x_count));
}

int	perform_attack(t_data *data, t_tile *next_tile, char direction)
{
	ft_printf("Start the attack on: %d\n", next_tile->id);
	if (chr_in(next_tile->type, "1BCE") == 1)
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
	}
	ft_printf("Attacked: %d\n", next_tile->id);
	return (1);
}

void	attack(t_data *data, int keycode)
{
	t_tile	*next_tile;
	char 	direction;

	next_tile = NULL;
	direction = 'R';
	if (keycode == K_E)
	{
		next_tile = get_next_tile(data, K_RIGHT);
		direction = 'R';
	}
	else if (keycode == K_Q)
	{
		next_tile = get_next_tile(data, K_LEFT);
		direction = 'L';
	}
	perform_attack(data, next_tile, direction);
	ft_printf("Attacked: %d\n", data->move_count);
}
