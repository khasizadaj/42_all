/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tile.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 18:20:44 by jkhasiza          #+#    #+#             */
/*   Updated: 2024/02/04 19:16:28 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

t_tile	*tile_new(t_data *data, char type, t_bool is_loaded)
{
	t_tile	*tile;
	void	*img;

	if (!is_loaded)
	{
		img = asset_factory(data, type);
		if (!img)
			return (NULL);
	}
	else
	{
	 	img = asset_get_by_type(&data->assets, type);	
	}
	tile = malloc(sizeof(t_tile));
	if (!tile)
		return (NULL);
	tile->type = type;
	if (!img)
		return (free(tile), NULL);
	tile->img = img;
	tile->id = 0;
	tile->next = NULL;
	return (tile);
}

void	tile_add_back(t_tile **tile_list, t_tile *new_tile)
{
	t_tile	*last;

	if (!tile_list || !new_tile)
		return ;
	if (!(*tile_list))
	{
		*tile_list = new_tile;
		new_tile->id = 1; 
		return ;
	}
	last = *tile_list;
	while (last->next)
		last = last->next;
	last->next = new_tile;
	new_tile->id = last->id + 1;
}

t_tile	*tile_get(t_tile **tile, int index)
{
	t_tile	**curr_tile;

	curr_tile = tile;
	while (*curr_tile)
	{
		if ((*curr_tile)->id == index)
			break ;
		curr_tile = &(*curr_tile)->next;
	}
	return (*curr_tile);
}

void	*tile_get_by_type(t_tile **tile, char type)
{
	t_tile	*curr_tile;

	curr_tile = *tile;
	while (curr_tile)
	{
		if (curr_tile->type == type)
			break ;
		curr_tile = curr_tile->next;
	}
	return (curr_tile->img);
}

void	free_tile(t_data *data)
{
    t_tile *current;
    t_tile *next;

    if (!data || !data->tile)
        return;
    current = data->tile;
    while (current)
    {
        next = current->next;
        free(current);
        current = next;
    }
}

void	free_assets(t_data *data)
{
    t_tile *current;
    t_tile *next;

    if (!data || !data->assets)
		return;

	current = data->assets;
    while (current)
    {
        next = current->next;
        mlx_destroy_image(data->mlx, current->img);
        free(current);
        current = next;
    }
}
