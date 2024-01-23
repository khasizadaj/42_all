/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 18:41:45 by jkhasiza          #+#    #+#             */
/*   Updated: 2024/01/23 18:54:50 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

char	*asset_factory(char type)
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