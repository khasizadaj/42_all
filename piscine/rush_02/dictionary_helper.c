/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictionary_helper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 12:46:57 by apashkov          #+#    #+#             */
/*   Updated: 2023/06/12 13:29:04 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h> // TODO DELETE
#include <stdio.h> // TODO DELETE

int		ft_atoi(char *str);
int		ft_strlen(char *str);
int		open_and_count(char *dict_name);
int		*get_expected_numbers(void);
int		is_exist(int number, int *expected_numbers);
int		is_space(char c);
int		has_valid_number(char *line);
int		has_valid_value(char *line);
int		free_count_valid_lines_memory(char *line, int *numbers);
char	*ft_reallocate(char *old, int old_size, int new_size);

void	get_next_line(int fd, char *line)
{
	char	curr;
	int		i;
	int		read_attempt;

	read_attempt = read(fd, &curr, 1);
	i = 0;
	while (read_attempt != 0 && curr != '\n')
	{
		line[i] = curr;
		read_attempt = read(fd, &curr, 1);
		i++;
		if (i % 20 == 0)
			line = ft_reallocate(line, i, i + 20);
		if (line == 0)
			return ;
	}
	line[i] = '\0';
}

int	count_lines(int fd)
{
	char	curr;
	int		i;
	int		read_attempt;
	int		count;

	count = 0;
	read_attempt = read(fd, &curr, 1);
	i = 0;
	while (read_attempt > 0)
	{
		if (curr == '\n')
			count++;
		read_attempt = read(fd, &curr, 1);
		i++;
	}
	return (count);
}

int	read_lines(int fd, char **dict, int count)
{
	char	*line;
	int		i;

	i = 0;
	while (i < count)
	{
		line = malloc(sizeof(char) * 20);
		if (line == NULL)
			return (0);
		get_next_line(fd, line);
		dict[i] = line;
		if (i % 20 == 0)
		{
			printf("ALLOCATING BITCH, %s", line);
			line = ft_reallocate(line, i, i + 20);
		}
		i++;
	}
	return (1);
}

int	is_valid_line(char *line, int *numbers)
{
	int	number;
	int	exists;

	if (has_valid_number(line) == 0)
		return (0);
	number = ft_atoi(line);
	exists = is_exist(number, numbers);
	if (exists == 1)
	{
		if (has_valid_value(line) == 0)
			return (0);
		return (1);
	}
	else if (exists == -1)
		return (-1);
	return (0);
}

int	count_valid_lines(int fd, int lines_count)
{
	char	*line;
	int		*numbers;
	int		valid_lines_count;
	int		i;
	int		line_is_valid;

	numbers = get_expected_numbers();
	valid_lines_count = 0;
	i = 0;
	while (i < lines_count)
	{
		line = malloc(sizeof(char) * 20);
		if (line == NULL)
			break ;
		get_next_line(fd, line);
		if (line != 0)
		{
			line_is_valid = is_valid_line(line, numbers);
			if (line_is_valid == -1)
				return (free_count_valid_lines_memory(line, numbers));
			else if (line_is_valid == 1)
				valid_lines_count++ ;
			i++;
		}
		free(line);
	}
	free(numbers);
	return (valid_lines_count);
}
