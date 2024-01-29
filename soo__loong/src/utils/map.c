/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 22:25:21 by jkhasiza          #+#    #+#             */
/*   Updated: 2024/01/28 03:57:00 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

/**
 * Checks if a line has allowed characters in the expected length.
 *
 * @param line           The line to be checked.
 * @param expected_size  The expected size of the line. If -1, size doesn't
 *							matter.
 *
 * @return               Returns TRUE if the line is valid, FALSE otherwise.
 */
int	is_valid_line(char *line, int expected_size)
{
	int	i;

	if (!line)
		return (FALSE);
	if (expected_size != -1 && (int) ft_strlen(line) != expected_size)
		return (FALSE);
	i = -1;
	while (line[++i])
	{
		if (chr_in(line[i], ALLOWED_CHARACTERS) == 0)
			return (FALSE);
	}
	return (TRUE);
}

int	is_valid_map(t_data *data, char *map)
{
	int	i;

	if (data->x_count > 1920 / SIDE_LENGTH
		|| data->y_count > 1080 / SIDE_LENGTH)
		return (SCREEN_SIZE_ERR);
	if (ft_count_char(map, 'P') != 1 || ft_count_char(map, 'E') != 1)
		return (INVALID_MAP_INCORRECT_COMPONENT);
	i = data->y_count;
	while (i > 0)
	{
		ft_printf("Started loop\n");
		if ((i == 1 || i == data->y_count)
			&& ft_count_nchar(map, '1', data->x_count) != data->x_count)
			return (INVALID_MAP_WRONG_WALLS);
		else if (ft_count_char(map, '1') >= 2
			&& map[0] != '1' && map[data->x_count - 1] != '1')
			return (INVALID_MAP_WRONG_WALLS);
		map += data->x_count;
		i--;
	}
	return (0);
}

char	*get_map_content(int fd, int *x_tile_count, int *y_tile_count)
{
	char	*line;
	char	*result;
	char	*temp;

	*x_tile_count = get_next_line(fd, &line, false);
	if ((*x_tile_count <= 0) || (line && !is_valid_line(line, -1)))
		return (close(fd), NULL);
	result = ft_strdup(line);
	if (!result)
		return (close(fd), free(line), NULL);
	while (line)
	{
		free(line);
		if (get_next_line(fd, &line, false) == -1)
			return (close(fd), free(result), NULL);
		if (!line)
			break ;
		temp = result;
		result = ft_strjoin(temp, line);
		if (!result || !is_valid_line(line, *x_tile_count))
			return (close(fd), free(temp), free(result), free(line), NULL);
	}
	*y_tile_count = ft_strlen(result) / *x_tile_count;
	return (result);
}

char	*get_map(char *filename, int *x_tile_count, int *y_tile_count)
{
	int		fd;
	char	*result;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (NULL);
	result = get_map_content(fd, x_tile_count, y_tile_count);
	if (!result)
		return (close(fd), NULL);
	close(fd);
	return (result);
}
