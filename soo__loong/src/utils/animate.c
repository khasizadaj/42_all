/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 20:18:03 by jkhasiza          #+#    #+#             */
/*   Updated: 2024/03/13 18:25:16 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"
#include <unistd.h>

void	animate_attack_empty(t_data *data, char *last,
	int diff, char direction)
{
	t_tile		**img;
	char		type;

	type = get_attack_frame_empty(diff);
	if (type == '0' || *last == type)
		return ;
	*last = type;
	if (direction == 'L')
		type = ft_tolower(type);
	img = asset_get_by_type(&data->assets, type);
	if (direction == 'L')
		mlx_put_image_to_window(data->mlx, data->win, img,
			get_x(data->player_pos - 1, data->x_count),
			get_y(data->player_pos - 1, data->x_count));
	else
		mlx_put_image_to_window(data->mlx, data->win, img,
			get_x(data->player_pos, data->x_count),
			get_y(data->player_pos, data->x_count));
}

void	animate_attack_villain(t_data *data, char *last,
	int diff, char direction)
{
	t_tile		**img;
	char		type;

	type = get_attack_frame_villain(diff);
	if (type == '0' || *last == type)
		return ;
	*last = type;
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

void	animate_nonmoving_sprites(t_data *data)
{
	long long	now;
	long long	diff;
	t_tile		**curr_tile;
	int			state;

	now = time_in_milliseconds(data);
	curr_tile = &data->tile;
	diff = now - data->start;
	if (diff % 500 < 250)
		state = 0;
	else
		state = 1;
	while (*curr_tile)
	{
		if (((*curr_tile)->next
				&& chr_in((*curr_tile)->type, ANIMATED_CHARACTERS))
			&& (*curr_tile)->state != state)
			change_state(data, *curr_tile);
		curr_tile = &(*curr_tile)->next;
	}
}

void	animate_attack(t_data *data)
{
	static long long	attack_start = -1;
	long long			diff;
	static char			last;

	if (data->attack[0] != '0')
	{
		if (attack_start == -1)
			attack_start = time_in_milliseconds(data);
		diff = time_in_milliseconds(data) - attack_start;
		if ((diff % 250 > 225 && data->attack[1] == '0')
			|| (diff % 700 > 675 && data->attack[1] == 'V'))
		{
			data->attack = "0";
			last = '0';
			attack_start = -1;
			return ;
		}
		if (data->attack[1] == '0')
			animate_attack_empty(data, &last, diff, data->attack[2]);
		else if (data->attack[1] == 'V')
			animate_attack_villain(data, &last, diff, data->attack[2]);
	}
}

int	animate(t_data *data)
{
	animate_attack(data);
	animate_nonmoving_sprites(data);
	return (1);
}
