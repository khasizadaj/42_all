/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 21:01:31 by jkhasiza          #+#    #+#             */
/*   Updated: 2024/03/13 17:53:32 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"
#include <unistd.h>

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

void	print_map_reasons(int reason)
{
	if (reason == INVALID_MAP_NO_VALID_PATH)
		ft_putstr_fd(INVALID_MAP_MSG_NO_VALID_PATH, STDERR_FILENO);
	else if (reason == INVALID_MAP_NOT_RECTANGLE)
		ft_putstr_fd(INVALID_MAP_MSG_NOT_RECTANGLE, STDERR_FILENO);
	else if (reason == INVALID_MAP_WRONG_WALLS)
		ft_putstr_fd(INVALID_MAP_MSG_WRONG_WALLS, STDERR_FILENO);
	else if (reason == INVALID_MAP_WRONG_FILE_TYPE)
		ft_putstr_fd(INVALID_MAP_MSG_WRONG_FILE_TYPE, STDERR_FILENO);
	else if (reason == INVALID_MAP)
		ft_putstr_fd(INVALID_MAP_MSG, STDERR_FILENO);
	else if (reason == INVALID_MAP_NO_MAP)
		ft_putstr_fd(INVALID_MAP_MSG_NO_MAP, STDERR_FILENO);
	else if (reason == INVALID_MAP_INCORRECT_COMPONENT)
		ft_putstr_fd(INVALID_MAP_MSG_INCORRECT_COMPONENT, STDERR_FILENO);
}

void	print_other_reasons(int reason)
{
	if (reason == PROGRAM_HALTED_WITH_ESCAPE)
		ft_putstr_fd(PROGRAM_HALTED_MSG_WITH_ESCAPE, STDERR_FILENO);
	else if (reason == ASSET_ERR)
		ft_putstr_fd(ASSET_ERR_MSG, STDERR_FILENO);
	else if (reason == PROGRAM_HALTED_WITH_X_ICON)
		ft_putstr_fd(PROGRAM_HALTED_MSG_X_ICON, STDERR_FILENO);
	else if (reason == SCREEN_SIZE_ERR)
		ft_putstr_fd(SCREEN_SIZE_MSG, STDERR_FILENO);
	else if (reason == END_GAME_YOU_ARE_DEAD)
		ft_putstr_fd(END_GAME_MSG_YOU_ARE_DEAD, STDERR_FILENO);
	else if (reason == MEMORY_ERR)
		ft_putstr_fd(MEMORY_ERR_MSG, STDERR_FILENO);
	else if (reason == UNKNOWN_ERR)
		ft_putstr_fd(UNKNOWN_ERR_MSG, STDERR_FILENO);
}

void	exit_for(int reason)
{
	print_map_reasons(reason);
	print_other_reasons(reason);
	exit(reason);
}
