/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 22:25:21 by jkhasiza          #+#    #+#             */
/*   Updated: 2024/03/11 18:14:41 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	go_to_new_row(int *x, int *y)
{
	*x = 0;
	*y += 72;
}

void	init_map(t_data *data, char *map_str)
{
	t_tile	*tile;
	int		i;
	int		x;
	int		y;

	i = -1;
	x = 0;
	y = 0;
	while (map_str[++i])
	{
		if (i % data->x_count == 0 && i != 0)
			go_to_new_row(&x, &y);
		tile = draw(data, x, y, map_str[i]);
		if (!tile)
			return (free(map_str), exit_gracefully(data, MEMORY_ERR));
		x += 72;
	}
	free(map_str);
}

static void	transfer_map(int fd, int *x_tile_count, char **result, char **line)
{
	char	*temp;

	if (!*result || !*line)
		return ;
	temp = *result;
	*result = ft_strjoin(temp, *line);
	if (!*result || !is_valid_line(*line, *x_tile_count))
	{
		if (*result)
		{
			free(*result);
			*result = NULL;
		}
		return (close(fd), free_get_next_line(fd, line), free(temp));
	}
	free(temp);
}

char	*get_map_content(int fd, int *x_tile_count, int *y_tile_count)
{
	char	*line;
	char	*result;

	*x_tile_count = get_next_line(fd, &line, false);
	if ((*x_tile_count <= 0) || (line && !is_valid_line(line, -1)))
		return (close(fd), free_get_next_line(fd, &line), NULL);
	result = ft_strdup(line);
	if (!result)
		return (close(fd), free_get_next_line(fd, &line), NULL);
	while (line)
	{
		free(line);
		if (get_next_line(fd, &line, false) == -1)
			return (close(fd), free(result), free(line), NULL);
		if (!line)
			break ;
		transfer_map(fd, x_tile_count, &result, &line);
		if (!result)
			return (close(fd), NULL);
	}
	*y_tile_count = ft_strlen(result) / *x_tile_count;
	return (close(fd), result);
}

char	*get_map(t_data *data, char *filename, int *x_tile_count,
	int *y_tile_count)
{
	int		fd;
	char	*result;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		data->exit_code = INVALID_MAP_NO_MAP;
		return (NULL);
	}
	result = get_map_content(fd, x_tile_count, y_tile_count);
	if (!result)
	{
		data->exit_code = INVALID_MAP;
		return (close(fd), NULL);
	}
	close(fd);
	return (result);
}
