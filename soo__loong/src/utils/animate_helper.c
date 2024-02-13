/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 17:47:26 by jkhasiza          #+#    #+#             */
/*   Updated: 2024/02/11 17:48:39 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

char	get_attack_frame_empty(long long diff)
{
	char	type;

	type = '0';
	if (diff % 250 < 250 / 4)
		type = 'G';
	else if (diff % 250 > 250 / 4
		&& diff % 250 < 250 / 4 * 2)
		type = 'O';
	else if (diff % 250 > 250 / 4 * 2
		&& diff % 250 < 250 / 4 * 3)
		type = 'K';
	else if (diff % 250 > 250 / 4 * 3
		&& diff % 250 < 250 - 25)
		type = 'L';
	return (type);
}

char	get_attack_frame_villain(long long diff)
{
	char	type;

	type = '0';
	if (diff % 700 < 100)
		type = 'G';
	else if (diff % 700 > 100 && diff % 700 < 300)
		type = 'H';
	else if (diff % 700 > 300 && diff % 700 < 550)
		type = 'J';
	else if (diff % 700 > 550 && diff % 700 < 640)
		type = 'K';
	else if (diff % 700 > 640 && diff % 700 < 675)
		type = 'L';
	return (type);
}

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
