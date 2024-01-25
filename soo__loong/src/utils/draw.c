/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 21:39:42 by jkhasiza          #+#    #+#             */
/*   Updated: 2024/01/25 20:23:25 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

t_tile	*draw_tile(t_data *data, int x, int y, char type)
{
	t_tile	*tile;

	tile = tile_new(data, type, TRUE);
	if (!tile)
		return (NULL);
	mlx_put_image_to_window(data->mlx, data->win, tile->img, x, y);
	tile_add_back(&(data->tile), tile);
	return (tile);
}
