/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 20:23:40 by jkhasiza          #+#    #+#             */
/*   Updated: 2024/03/14 16:35:08 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	init_data(t_data *data)
{
	data->x_count = 0;
	data->y_count = 0;
	data->collected = 0;
	data->height = 0;
	data->width = 0;
	data->screen_height = 0;
	data->screen_width = 0;
	data->side_length = SIDE_LEN;
	data->player_pos = -1;
	data->exit = 1;
	data->exit_code = 0;
	data->tile = NULL;
	data->win = NULL;
	data->mlx = NULL;
	data->assets = NULL;
	data->move_count = 0;
	data->attack = "0";
	data->start = time_in_milliseconds(data);
	return ;
}

void	enhance_data_sizes(t_data *data)
{
	data->height = data->y_count * data->side_length;
	data->width = data->x_count * data->side_length;
	mlx_get_screen_size(data->mlx, &data->screen_width, &data->screen_height);
	if (data->height > data->screen_height || data->width > data->screen_width)
		exit_gracefully(data, SCREEN_SIZE_ERR);
}

void	enhance_data(t_data *data, char *map_str)
{
	int	i;

	i = -1;
	while (map_str[++i])
	{
		if (map_str[i] == 'P')
			data->player_pos = i + 1;
		if (map_str[i] == 'E')
			data->exit = i + 1;
	}
	data->total_coins = ft_count_char(map_str, 'C');
	data->mlx = mlx_init();
	if (!data->mlx)
		exit_gracefully(data, MEMORY_ERR);
	enhance_data_sizes(data);
	if (!init_assets(data))
	{
		free(map_str);
		exit_gracefully(data, ASSET_ERR);
	}
	data->win = mlx_new_window(data->mlx, data->width,
			data->height, PROGRAM_NAME);
	if (!data->win)
		exit_gracefully(data, MEMORY_ERR);
}
