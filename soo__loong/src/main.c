/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 20:30:10 by jkhasiza          #+#    #+#             */
/*   Updated: 2024/01/22 22:55:10 by jkhasiza         ###   ########.fr       */
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
	data->win = mlx_new_window(data->mlx, width, 
		height, "DND");
	if (!data->win)
		return (free(data->mlx), free(data), NULL);
	data->height = HEIGHT;
	data->width = WIDTH;
	data->side_length = 36;
	return (data);
}

char	*asset_factory(char type)
{
	if (type == 'b')
		return "assets/bomb.xpm";
	return ("assets/floor.xpm");
}

// void	free_tile(t_data *data, t_tile *tile)
void	free_tile(t_tile *tile)
{
	t_tile	*temp;

	temp = tile;
	while (temp)
	{
		temp = temp->next;
		free(tile->img);
		// mlx_destroy_image(data->mlx, tile->img);
		free(tile);
	}
}

t_tile	*init_map(t_data *data, char *filename)
{
	t_tile	*tile;
	void	*img;

	ft_printf("%s\n", filename);
	tile = ft_calloc(sizeof(t_tile), 1);
	if (!tile)
		return (NULL);
	tile->type = 'c';
	img = mlx_xpm_file_to_image(data->mlx, "./src/assets/bomb.xpm", &data->side_length, &data->side_length);
	if (!img)
		return (free_tile(tile), NULL);
	tile->img = img;
	mlx_put_image_to_window(data->mlx, data->win, tile->img, 45, 45);
	mlx_put_image_to_window(data->mlx, data->win, tile->img, 81, 45);
	return (tile);
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		exit_for(PROGRAM_HALTED_WITH_ESCAPE);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int		width;
	int		height;
	t_data	*data;
	t_tile	*tile;

	if (argc != 2)
		exit_for(INVALID_MAP_NO_MAP);
	if (!ft_str_endswith(argv[1], MAP_EXTENSION))
		exit_for(INVALID_MAP_WRONG_FILE_TYPE);
	width = 600;
	height = 600;
	data = init_data(width, height);
	if (!data)
		exit_for(MEMORY_ERR);
	if (!draw_board_border(data, 30, 5))
		exit_for(UNKNOWN_ERR);
	tile = init_map(data, argv[1]);
	// if (!tile)
	// 	exit_for(MEMORY_ERR);
	mlx_key_hook(data->win, key_hook, &data);
	mlx_loop(data->mlx);
	ft_printf("ALL GOOHUDEE");
	return (1);
}
