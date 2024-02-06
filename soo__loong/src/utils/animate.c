/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 20:18:03 by jkhasiza          #+#    #+#             */
/*   Updated: 2024/02/06 23:29:05 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

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

int	animate_attack(t_data *data, int diff)
{
	t_tile		**img;
	char		type;

	type = '0';
	if (data->attacked_tile == '0')
	{
		if (diff % 500 < 125)
			type = '2';
		else if (diff % 500 > 125 && diff % 500 < 250)
			type = '#';
		else if (diff % 500 > 250 && diff % 500 < 375)
			type = '5';
		else if (diff % 500 > 375)
			type = '6';
		img = asset_get_by_type(&data->assets, type);
		mlx_put_image_to_window(data->mlx, data->win, img,
			0,
			0);
	}
	return (1);
}

int	animate(t_data *data)
{
	long long	now;
	long long	diff;
	t_tile		**curr_tile;
	int			state;

	now = time_in_milliseconds();
	curr_tile = &data->tile;
	diff = now - data->start;
	if (data->is_attacking)
		animate_attack(data, diff);
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
