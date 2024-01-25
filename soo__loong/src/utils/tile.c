/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tile.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 18:20:44 by jkhasiza          #+#    #+#             */
/*   Updated: 2024/01/25 04:44:02 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

t_tile	*tile_new(t_data *data, char type)
{
	t_tile	*tile;
	void	*img;

	tile = ft_calloc(sizeof(t_tile), 1);
	if (!tile)
		return (NULL);
	tile->type = type;
	img = mlx_xpm_file_to_image(data->mlx, asset_factory(type), 
		&data->side_length, &data->side_length);
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
        mlx_destroy_image(data->mlx, current->img);
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
