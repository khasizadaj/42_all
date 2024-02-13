/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 12:12:09 by jkhasiza          #+#    #+#             */
/*   Updated: 2024/02/06 21:03:45 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"
#include <stdbool.h>

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

	if (data->x_count > 1920 / SIDE_LEN || data->y_count > 1080 / SIDE_LEN)
		data->exit_code = SCREEN_SIZE_ERR;
	else if (ft_count_char(map, 'P') != 1 || ft_count_char(map, 'E') != 1
		|| ft_count_char(map, 'C') < 1)
		data->exit_code = INVALID_MAP_INCORRECT_COMPONENT;
	else if ((int) ft_strlen(map) != data->x_count * data->y_count)
		data->exit_code = INVALID_MAP_NOT_RECTANGLE;
	if (data->exit_code != 0)
		return (data->exit_code);
	i = data->y_count + 1;
	while (--i > 0)
	{
		if ((i == 1 || i == data->y_count)
			&& ft_count_nchar(map, '1', data->x_count) != data->x_count)
			data->exit_code = INVALID_MAP_WRONG_WALLS;
		else if (map[0] != '1' || map[data->x_count - 1] != '1')
			data->exit_code = INVALID_MAP_WRONG_WALLS;
		if (data->exit_code != 0)
			return (data->exit_code);
		map += data->x_count;
	}
	return (data->exit_code);
}

void	flood(int position, int x_count, char *map, char new)
{
	if (position > (int) ft_strlen(map) || position < 0)
		return ;
	if (chr_in(map[position], "1-B"))
		return ;
	map[position] = new;
	flood(position + 1, x_count, map, new);
	flood(position - 1, x_count, map, new);
	flood(position + x_count, x_count, map, new);
	flood(position - x_count, x_count, map, new);
}

bool	has_valid_path(t_data *data, char *map)
{
	int		start;
	char	*temp;

	start = 0;
	while (map[start] != 'P')
		start++;
	temp = ft_strdup(map);
	if (!temp)
	{
		data->exit_code = MEMORY_ERR;
		return (false);
	}
	flood(start, data->x_count, temp, '-');
	if (chr_in('E', temp) || chr_in('C', temp))
	{
		data->exit_code = INVALID_MAP_NO_VALID_PATH;
		return (free(temp), false);
	}
	return (free(temp), true);
}
