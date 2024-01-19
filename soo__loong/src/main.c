/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 20:30:10 by jkhasiza          #+#    #+#             */
/*   Updated: 2024/01/19 23:20:40 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_data	*init_data(int width, int height)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	data->mlx = mlx_init();
	if (!data->mlx)
		return (free(data), NULL);
	data->win = mlx_new_window(data->mlx, width, height, "DND");
	if (!data->win)
		return (free(data->mlx), free(data), NULL);
	data->height = HEIGHT;
	data->width = WIDTH;
	return (data);
}

int	main(int argc, char **argv)
{
	int		width;
	int		height;
	t_data	*data;

	if (argc != 2)
		exit_for(INVALID_MAP_NO_MAP);
	if (!ft_str_endswith(argv[1], MAP_EXTENSION))
		exit_for(INVALID_MAP_WRONG_FILE_TYPE);
	width = 600;
	height = 600;
	data = init_data(width, height);
	if (!data)
		exit_for(MEMORY_ERR);
	if (!draw_board_border(data, 50, 10))
		exit_for(UNKNOWN_ERR);
	mlx_loop(data->mlx);
	ft_printf("ALL GOOHUDEE");
	return (1);
}
