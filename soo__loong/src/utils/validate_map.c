/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 12:12:09 by jkhasiza          #+#    #+#             */
/*   Updated: 2024/03/13 20:27:45 by jkhasiza         ###   ########.fr       */
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

	if (ft_count_char(map, 'P') != 1 || ft_count_char(map, 'E') != 1
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

/*
	Flood fill doesn't consider bombs and villains as blocker
	unless they are adjacent to current cell.

	Map below is valid and it will be filled like this and it
	is invalid.

	111   ==>   111
	1P1   ==>   1-1
	1B1   ==>   1B1
	1C1   ==>   1C1
	1E1   ==>   1E1
	111   ==>   111

	However, map below is valid as player can destroy some sprites
	on horizontal line.

	1111111111   ==>   1111111111
	1PBVCE1111   ==>   1-----1111
	1111111111   ==>   1111111111
*/
void	flood(int position, int x_count, char *map, char new)
{
	if (position > (int) ft_strlen(map) || position < 0)
		return ;
	if (chr_in(map[position], "1-"))
		return ;
	map[position] = new;
	flood(position + 1, x_count, map, new);
	flood(position - 1, x_count, map, new);
	if (!chr_in(map[position + x_count], "VB"))
		flood(position + x_count, x_count, map, new);
	if (!chr_in(map[position + x_count], "VB"))
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
