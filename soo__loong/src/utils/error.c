/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 21:01:31 by jkhasiza          #+#    #+#             */
/*   Updated: 2024/02/11 19:42:26 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	exit_gracefully(t_data *data, int reason)
{
	if (data->tile)
		free_tile(data);
	if (data->assets)
		free_assets(data);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
	{
		mlx_loop_end(data->mlx);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	exit_for(reason);
}

void	exit_for(int reason)
{
	if (reason == INVALID_MAP_NO_VALID_PATH)
		ft_printf(INVALID_MAP_MSG_NO_VALID_PATH);
	else if (reason == INVALID_MAP_NOT_RECTANGLE)
		ft_printf(INVALID_MAP_MSG_NOT_RECTANGLE);
	else if (reason == INVALID_MAP_WRONG_WALLS)
		ft_printf(INVALID_MAP_MSG_WRONG_WALLS);
	else if (reason == INVALID_MAP_WRONG_FILE_TYPE)
		ft_printf(INVALID_MAP_MSG_WRONG_FILE_TYPE);
	else if (reason == PROGRAM_HALTED_WITH_ESCAPE)
		ft_printf(PROGRAM_HALTED_MSG_WITH_ESCAPE);
	else if (reason == MEMORY_ERR)
		ft_printf(MEMORY_ERR_MSG);
	else if (reason == INVALID_MAP)
		ft_printf(INVALID_MAP_MSG);
	else if (reason == INVALID_MAP_INCORRECT_COMPONENT)
		ft_printf(INVALID_MAP_MSG_INCORRECT_COMPONENT);
	else if (reason == SCREEN_SIZE_ERR)
		ft_printf(SCREEN_SIZE_MSG);
	else if (reason == END_GAME_YOU_ARE_DEAD)
		ft_printf(END_GAME_MSG_YOU_ARE_DEAD);
	else if (reason == UNKNOWN_ERR)
		ft_printf(UNKNOWN_ERR_MSG);
	exit(reason);
}
