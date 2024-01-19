/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 21:39:42 by jkhasiza          #+#    #+#             */
/*   Updated: 2024/01/19 23:19:26 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

t_bool	draw_board_border(t_data *data, int padding, int border_width)
{
	int	x;
	int	y;
	int weight;

	if (!data)
		return (FALSE);
	x = data->width - padding + border_width;
	y = data->height - padding + border_width;
	while (x >= padding - border_width) 
	{
		weight = 0;
		while (++weight <= border_width)
			mlx_pixel_put(data->mlx, data->win, x, y - weight, WHITE);
		weight = 0;
		while (++weight <= border_width)
			mlx_pixel_put(data->mlx, data->win, x, padding - weight, WHITE);
		x--;
	}
	x = data->width - padding + border_width;
	y = data->height - padding + border_width;
	ft_printf("(%d,%d)", x, y);
	while (--y >= padding - border_width) 
	{
		weight = 0;
		while (++weight <= border_width)
			mlx_pixel_put(data->mlx, data->win, x + weight, y, WHITE);
		weight = 0;
		while (++weight <= border_width)
			mlx_pixel_put(data->mlx, data->win, padding - weight, y, WHITE);
	}
	ft_printf("(%d,%d)", x, y);
	return (TRUE);
}
