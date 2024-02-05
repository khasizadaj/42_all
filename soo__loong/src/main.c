/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 20:30:10 by jkhasiza          #+#    #+#             */
/*   Updated: 2024/02/05 21:46:48 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
	 	
long long timeInMilliseconds(void) {
    struct timeval tv;

    gettimeofday(&tv,NULL);
    return (((long long) tv.tv_sec) * 1000) + (tv.tv_usec / 1000);
}

void	init_data(t_data *data)
{
	data->x_count = 0;
	data->y_count = 0;
	data->collected = 0;
	data->height = 0;
	data->width = 0;
	data->side_length = SIDE_LEN;
	data->player_pos = -1;
	data->exit = 1;
	data->exit_code = 0;
	data->tile = NULL;
	data->win = NULL;
	data->mlx = NULL;
	data->assets = NULL;
	data->move_count = 0;
	data->start = timeInMilliseconds();
	return ;
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
	data->height = data->y_count * data->side_length + 72;
	data->width = data->x_count * data->side_length;
	data->total_coins = ft_count_char(map_str, 'C');
	data->mlx = mlx_init();
	if (!data->mlx)
		exit_gracefully(data, MEMORY_ERR);
	data->win = mlx_new_window(data->mlx, data->width,
			data->height, PROGRAM_NAME);
	if (!data->win)
		exit_gracefully(data, MEMORY_ERR);
	if (!init_assets(data))
	{
		free(map_str);
		exit_gracefully(data, MEMORY_ERR);
	}
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

int	draw_random(t_data *data)
{
	long long	now;
	long long	diff;
	t_tile		**curr_tile;

	now = timeInMilliseconds();
	curr_tile = &data->tile;
	diff = now - data->start;
	if (diff % 500 < 250)
	{
		while (*curr_tile)
		{
			while ((*curr_tile)->next && !chr_in((*curr_tile)->type, "PC"))
				curr_tile = &(*curr_tile)->next;
			if ((*curr_tile)->state != 0)
				change_state(data, *curr_tile);
			curr_tile = &(*curr_tile)->next;
		}
	}
	else if (diff % 500 > 250)
	{
		while (*curr_tile)
		{
			while ((*curr_tile)->next && !chr_in((*curr_tile)->type, "PC"))
				curr_tile = &(*curr_tile)->next;
			if ((*curr_tile)->state != 1)
				change_state(data, *curr_tile);
			ft_printf("REDRAW; %c\n", (*curr_tile)->type);
			curr_tile = &(*curr_tile)->next;
		}
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	data;
	char	*map_str;

	if (argc != 2)
		exit_for(INVALID_MAP_NO_MAP);
	if (!ft_str_endswith(argv[1], MAP_EXTENSION))
		exit_for(INVALID_MAP_WRONG_FILE_TYPE);
	init_data(&data);
	map_str = get_map(&data, argv[1], &data.x_count, &data.y_count);
	if (!map_str || is_valid_map(&data, map_str) != 0
		|| has_valid_path(&data, map_str) == false)
	{
		free(map_str);
		exit_gracefully(&data, data.exit_code);
	}
	enhance_data(&data, map_str);
	init_map(&data, map_str);
	mlx_hook(data.win, 2, 1L,
		key_hook, &data);
	mlx_loop_hook(data.mlx, draw_random, &data);
	mlx_loop(data.mlx);
	return (0);
}
