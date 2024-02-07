/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 20:30:10 by jkhasiza          #+#    #+#             */
/*   Updated: 2024/02/07 21:47:24 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
	 	
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
	mlx_hook(data.win, KEY_PRESS, KEY_PRESS_MASK,
		key_hook, &data);
	mlx_loop_hook(data.mlx, animate, &data);
	mlx_loop(data.mlx);
	return (0);
}
