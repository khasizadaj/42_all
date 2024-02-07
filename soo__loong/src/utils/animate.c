/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 20:18:03 by jkhasiza          #+#    #+#             */
/*   Updated: 2024/02/07 21:44:01 by jkhasiza         ###   ########.fr       */
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

int	animate(t_data *data)
{
	long long	now;
	long long	diff;
	t_tile		**curr_tile;
	int			state;

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
