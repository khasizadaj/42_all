/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 21:39:42 by jkhasiza          #+#    #+#             */
/*   Updated: 2024/02/04 21:37:07 by jkhasiza         ###   ########.fr       */
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

/*
	In order to have hidden exit, exit is added to list of tiles,
	however floor is registered to hide it.
*/
t_tile	*draw_exit(t_data *data, int x, int y)
{
	t_tile	*tile;

	tile = tile_new(data, 'E', TRUE);
	if (!tile)
		return (NULL);
	mlx_put_image_to_window(data->mlx, data->win,
		asset_get_by_type(&data->assets, '0'), x, y);
	tile_add_back(&data->tile, tile);
	return (tile);
}

t_tile	*draw(t_data *data, int x, int y, char type)
{
	t_tile	*tile;

	if (type == 'E')
	{
		tile = draw_exit(data, x, y);
		if (!tile)
			return (NULL);
	}
	else
	{
		tile = draw_tile(data, x, y, type);
		if (!tile)
			return (NULL);
	}
	return (tile);
}
