/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 20:18:03 by jkhasiza          #+#    #+#             */
/*   Updated: 2024/02/07 21:14:43 by jkhasiza         ###   ########.fr       */
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

int	animate_attack(t_data *data)
{
	t_tile		**img;
	char		type;
	static int	counter; 

	type = '0';
	ft_printf("tile: %c\n", data->attacked_tile);
	if (data->attacked_tile == '0')
	{
		ft_printf("is attacking: %d\n", data->is_attacking);
		while (1)
		{
			if (counter % 10000 + 9000 < 2500 + 9000)
				type = '2';
			else if (counter % 10000 + 9000 > 2500 + 9000 && counter % 10000 + 9000 < 5000 + 9000)
				type = '#';
			else if (counter % 10000 + 9000 > 5000 + 9000 && counter % 10000 + 9000 < 7500 + 9000)
				type = '5';
			else if (counter % 10000 + 9000 > 7500 + 9000 && counter % 10000 + 9000 < 9500 + 9000)
				type = '6';
			else if (counter % 10000 + 9000 > 9500 + 9000 && data->is_attacking == 1)
			{
				data->is_attacking = 0;
				ft_printf("Finish animation\n");
				break ;
			}
			img = asset_get_by_type(&data->assets, type);
			mlx_put_image_to_window(data->mlx, data->win, img,
				0,
				0);
			counter++;
		}
		counter = 0;
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
		animate_attack(data);
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
