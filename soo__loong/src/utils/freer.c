/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 21:37:54 by jkhasiza          #+#    #+#             */
/*   Updated: 2024/02/04 23:01:49 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	free_get_next_line(int fd, char **line)
{
	while (*line)
	{
		free(*line);
		get_next_line(fd, line, false);
	}
}

void	free_tile(t_data *data)
{
	t_tile	*current;
	t_tile	*next;

	if (!data || !data->tile)
		return ;
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
	t_tile	*current;
	t_tile	*next;

	if (!data || !data->assets)
		return ;
	current = data->assets;
	while (current)
	{
		next = current->next;
		mlx_destroy_image(data->mlx, current->img);
		free(current);
		current = next;
	}
}
