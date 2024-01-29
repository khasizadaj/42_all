/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 18:41:45 by jkhasiza          #+#    #+#             */
/*   Updated: 2024/01/25 20:57:30 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	*asset_get_by_type(t_tile **assets, char type)
{
	t_tile	*curr_tile;

	curr_tile = *assets;
	while (curr_tile)
	{
		if (curr_tile->type == type)
			break ;
		curr_tile = curr_tile->next;
	}
	return (curr_tile->img);
}

t_tile	*asset_factory(t_data *data, char type)
{
	t_tile	*asset;
	
	asset = mlx_xpm_file_to_image(data->mlx, asset_path_factory(type), 
		&data->side_length, &data->side_length);
	if (!asset)
		return (NULL);
	return (asset);
}


char	*asset_path_factory(char type)
{
	if (type == '1')
		return (A_WALL_O);
	else if (type == 'C')
		return (A_COIN);
	else if (type == 'E')
		return (A_EXIT);
	else if (type == 'P')
		return (A_PLAYER_R);
	return (A_FLOOR);
}