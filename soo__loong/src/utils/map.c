/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 22:25:21 by jkhasiza          #+#    #+#             */
/*   Updated: 2024/01/28 00:58:48 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

/**
 * Checks if a line has allowed characters in the expected length.
 *
 * @param line           The line to be checked.
 * @param expected_size  The expected size of the line. If -1, size doesn't matter.
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

char *get_map_content(int fd)
{
	char	*line;
	char	*result;
	int		expected_size;
	char	*temp;
	
	expected_size = get_next_line(fd, &line, false);
	if (expected_size == -1 || (line && !is_valid_line(line, -1)))
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
		if (!result || !is_valid_line(line, expected_size))
			return (close(fd), free(temp), free(result), free(line), NULL);
	}
	return (result);
}

char	*get_map(char *filename)
{
	int		fd;
	char	*result;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (NULL);
	result = get_map_content(fd);
	if (!result)
		return (close(fd), NULL);
	close(fd);
	return (result);
}
