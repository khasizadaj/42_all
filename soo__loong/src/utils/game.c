/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:51:52 by jkhasiza          #+#    #+#             */
/*   Updated: 2024/02/07 21:46:52 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"
#include <unistd.h>

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

int	perform_move(t_data *data, t_tile *tile)
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

void	animate_attack(t_data *data)
{
	t_tile		**img;
	char		type;
	static int	counter = 0; 

	type = '0';
	ft_printf("tile: %c\n", data->attacked_tile);
	if (data->attacked_tile == '0')
	{
		ft_printf("is attacking: %d\n", data->is_attacking);
		while (1)
		{
			if (counter % 20000 < 5000)
				type = '2';
			else if (counter % 20000 > 5000 && counter % 20000 < 10000)
				type = '#';
			else if (counter % 20000 > 10000 && counter % 20000 < 15000)
				type = '5';
			else if (counter % 20000 > 15000 && counter % 20000 < 19000)
				type = '6';
			else if (counter % 20000 > 19000 && data->is_attacking == 1)
			{
				data->is_attacking = 0;
				ft_printf("Finish animation\n");
				counter = 0;
				break ;
			}
			img = asset_get_by_type(&data->assets, type);
			mlx_put_image_to_window(data->mlx, data->win, img,
				get_x(data->player_pos, data->x_count),
				get_y(data->player_pos, data->x_count));
			counter += 2;
		}
	}
}

int	perform_attack(t_data *data, t_tile *next_tile)
{
	void	*img;

	img = NULL;
	if (chr_in(next_tile->type, "1BCE") == 1)
		return (0);
	else
	{
		data->is_attacking = 1;
		data->attacked_tile = '0';
		animate_attack(data);
	}
	ft_printf("Attacked: %d\n", next_tile->id);
	return (1);
}

void	attack(t_data *data, int keycode)
{
	t_tile	*next_tile;

	next_tile = NULL;
	if (keycode == K_E)
		next_tile = get_next_tile(data, K_RIGHT);
	else if (keycode == K_Q)
		next_tile = get_next_tile(data, K_LEFT);
	perform_attack(data, next_tile);
	ft_printf("Attacked: %d\n", data->move_count);
}
