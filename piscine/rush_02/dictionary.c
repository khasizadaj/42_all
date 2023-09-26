/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictionary.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 12:07:20 by jkhasiza          #+#    #+#             */
/*   Updated: 2023/06/12 13:22:11 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int		ft_atoi(char *str);
int		is_space(char c);
char	*get_word(char *str);
void	get_next_line(int fd, char *line);
int		count_lines(int fd);
int		read_lines(int fd, char **dict, int count);
int		is_valid_line(char *line, int *numbers);
int		count_valid_lines(int fd, int lines_count);

int	open_and_count(char *dict_name)
{
	int		fd;
	int		count;

	count = 0;
	fd = open(dict_name, O_RDONLY);
	if (fd == -1)
		return (0);
	else
	{
		count = count_lines(fd);
		if (close(fd) == -1)
			write(1, "Dict Error\n", 11);
	}
	return (count);
}

int	open_and_read(char *dict_name, char **dict, int count)
{
	int	fd;
	int	result;

	fd = open(dict_name, O_RDONLY);
	result = 0;
	if (fd == -1)
		write(1, "Dict Error\n", 11);
	else
	{
		result = read_lines(fd, dict, count);
		if (close(fd) == -1)
			write(1, "Dict Error\n", 11);
	}
	return (result);
}

char	**get_dict(char	*dict_name, int count)
{
	char	**dict;

	dict = malloc(count * sizeof(char *));
	if (dict == NULL)
		return (0);
	if (open_and_read(dict_name, dict, count) == 0)
	{
		free(dict);
	}
	return (dict);
}

void	free_dict(char **dict, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(dict[i]);
		i++;
	}
	free(dict);
}

int	open_and_count_valid_lines(char *dict_name)
{
	int		fd;
	int		lines_count;
	int		valid_line_count;

	lines_count = open_and_count(dict_name);
	fd = open(dict_name, O_RDONLY);
	if (fd == -1 || lines_count == 0)
		return (0);
	else
	{
		valid_line_count = count_valid_lines(fd, lines_count);
		if (close(fd) == -1)
			write(1, "Dict Error\n", 11);
	}
	return (valid_line_count);
}
