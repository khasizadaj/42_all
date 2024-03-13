/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 18:41:45 by jkhasiza          #+#    #+#             */
/*   Updated: 2024/03/13 18:07:24 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

/*
	`init_assets` function makes sure that all assets are present.
	that's why edge case for missing type in assets is not protected.
*/
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
	char	*pathes[255];

	pathes[FLOOR] = A_FLOOR;
	pathes[WALL] = A_WALL_O;
	pathes[COIN_L] = A_COIN_L;
	pathes[COIN_R] = A_COIN_R;
	pathes[PLAYER_R] = A_PLAYER_R;
	pathes[PLAYER_L] = A_PLAYER_L;
	pathes[EXIT] = A_EXIT;
	pathes[BOMB_U] = A_BOMB_U;
	pathes[BOMB_D] = A_BOMB_D;
	pathes[ATTACK_0] = A_ATTACK_0;
	pathes[ATTACK_0_L] = A_ATTACK_0_L;
	pathes[ATTACK_1] = A_ATTACK_1;
	pathes[ATTACK_1_L] = A_ATTACK_1_L;
	pathes[ATTACK_1_E] = A_ATTACK_1_E;
	pathes[ATTACK_1_E_L] = A_ATTACK_1_E_L;
	pathes[ATTACK_2] = A_ATTACK_2;
	pathes[ATTACK_2_L] = A_ATTACK_2_L;
	pathes[ATTACK_3] = A_ATTACK_3;
	pathes[ATTACK_3_L] = A_ATTACK_3_L;
	pathes[ATTACK_4] = A_ATTACK_4;
	pathes[ATTACK_4_L] = A_ATTACK_4_L;
	pathes[VILLAIN_R] = A_VILLAIN_R;
	return (pathes[(int) type]);
}

bool	init_assets(t_data *data)
{
	char	*str_map;
	int		i;
	t_tile	*tile;

	i = -1;
	str_map = ASSETS_TO_LOAD;
	while (str_map[++i])
	{
		tile = tile_new(data, str_map[i], FALSE);
		if (!tile)
			return (false);
		tile_add_back(&data->assets, tile);
	}
	return (true);
}
