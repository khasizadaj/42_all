/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 20:18:03 by jkhasiza          #+#    #+#             */
/*   Updated: 2024/02/10 14:02:33 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"
#include <unistd.h>

void	change_state(t_data *data, t_tile *tile)
{
	int	pos;

	if (tile->type == 'P')
		pos = data->player_pos;
	else
		pos = tile->id;
	if (tile->state == 0)
	{
		mlx_put_image_to_window(data->mlx, data->win,
			asset_get_by_type(&data->assets, ft_tolower(tile->type)),
			get_x(pos, data->x_count),
			get_y(pos, data->x_count));
		tile->state = 1;
	}
	else if (tile->state == 1)
	{
		mlx_put_image_to_window(data->mlx, data->win,
			tile->img,
			get_x(pos, data->x_count),
			get_y(pos, data->x_count));
		tile->state = 0;
	}
}

static void	animate_attack_empty(t_data *data, long long *start, char direction)
{
	t_tile		**img;
	long long	diff;
	long long	now;
	char		type;
	static char	last = '0';

	now = time_in_milliseconds();
	diff = now - *start;
	type = '0';
	if (diff % ATTACK_DURATION < ATTACK_DURATION / 4)
		type = 'G';
	else if (diff % ATTACK_DURATION > ATTACK_DURATION / 4 && diff % ATTACK_DURATION < ATTACK_DURATION / 4 * 2)
		type = 'O';
	else if (diff % ATTACK_DURATION > ATTACK_DURATION / 4 * 2 && diff % ATTACK_DURATION < ATTACK_DURATION / 4 * 3)
		type = 'K';
	else if (diff % ATTACK_DURATION > ATTACK_DURATION / 4 * 3 && diff % ATTACK_DURATION < ATTACK_DURATION - 25)
		type = 'L';
	else if (diff % ATTACK_DURATION > ATTACK_DURATION - 25)
	{
		data->attack = "0";
		last = '0';
		*start = -1;
		return;
	}
	if (type != '0' && last != type)
	{
		last = type;
		if (direction == 'L')
		{
			type = ft_tolower(type);
			img = asset_get_by_type(&data->assets, type);
			mlx_put_image_to_window(data->mlx, data->win, img,
				get_x(data->player_pos - 1, data->x_count),
				get_y(data->player_pos - 1, data->x_count));
		}
		else
		{
			img = asset_get_by_type(&data->assets, type);
			mlx_put_image_to_window(data->mlx, data->win, img,
				get_x(data->player_pos, data->x_count),
				get_y(data->player_pos, data->x_count));
		}
	}
}

static void	animate_attack_villain(t_data *data, long long *start, char direction)
{
	t_tile		**img;
	long long	diff;
	long long	now;
	char		type;
	static char	last = '0';

	now = time_in_milliseconds();
	diff = now - *start;
	type = '0';
	if (data->attack[1] == 'V')
	{
		if (diff % 700 < 100)
			type = 'G';
		else if (diff % 700 > 100 && diff % 700 < 300)
			type = 'H';
		else if (diff % 700 > 300 && diff % 700 < 550)
			type = 'J';
		else if (diff % 700 > 550 && diff % 700 < 650)
			type = 'K';
		else if (diff % 700 > 650 && diff % 700 < 690)
			type = 'L';
		else if (diff % 700 > 690)
		{
			data->attack = "0";
			last = '0';
			*start = -1;
			return;
		}
	}
	if (type != '0' && last != type)
	{
		last = type;
		if (direction == 'L')
		{
			type = ft_tolower(type);
			img = asset_get_by_type(&data->assets, type);
			mlx_put_image_to_window(data->mlx, data->win, img,
				get_x(data->player_pos - 1, data->x_count),
				get_y(data->player_pos - 1, data->x_count));
				return ;
		}
		else
		{
			img = asset_get_by_type(&data->assets, type);
			mlx_put_image_to_window(data->mlx, data->win, img,
				get_x(data->player_pos, data->x_count),
				get_y(data->player_pos, data->x_count));
		}
	}
}

int	animate(t_data *data)
{
	static long long attack_start = -1;
	long long	now;
	long long	diff;
	t_tile		**curr_tile;
	int			state;

	if (data->attack[0] != '0')
	{
		if (attack_start == -1)
			attack_start = time_in_milliseconds(); 
		if (data->attack[1] == '0')
			animate_attack_empty(data, &attack_start, data->attack[2]);
		else if (data->attack[1] == 'V')
			animate_attack_villain(data, &attack_start, data->attack[2]);
	}
	now = time_in_milliseconds();
	curr_tile = &data->tile;
	diff = now - data->start;
	if (diff % 500 < 250)
		state = 0;
	else
		state = 1;
	while (*curr_tile)
	{
		if (((*curr_tile)->next && chr_in((*curr_tile)->type, ANIMATED_CHARACTERS))
			&& (*curr_tile)->state != state)
			change_state(data, *curr_tile);
		curr_tile = &(*curr_tile)->next;
	}
	return (1);
}
