/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 18:48:25 by jkhasiza          #+#    #+#             */
/*   Updated: 2023/06/14 04:46:18 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "structs.h"

int		ft_atoi(char *str);
int		ft_strstr_pos(char *str, char *to_find);
char	*ft_strlcpy(char *dest, char *src, unsigned int n);
int		ft_str_is_numeric(char *str);
int		ft_char_is_printable(char c);
void	memory_error(void);
void	map_error(void);

int	validate_config(t_config *config)
{
	if (config->line_count < 0)
		return (0);
	if (config->empty == '\0' || config->full == '\0'
		|| config->obstacle == '\0')
		return (0);
	return (1);
}

t_config	init_config(void)
{
	t_config	config;

	config.line_count = -1;
	config.empty = '\0';
	config.full = '\0';
	config.obstacle = '\0';
	return (config);
}

t_config	*set_config(char *map_as_str, t_config *config)
{
	int				line_count;
	int				end_pos_of_first_line;
	char			*number_of_lines_as_str;

	end_pos_of_first_line = ft_strstr_pos(map_as_str, "\n");
	if (end_pos_of_first_line > 13)
		return (config);
	number_of_lines_as_str = malloc(sizeof(char) * end_pos_of_first_line - 2);
	if (number_of_lines_as_str == NULL)
		memory_error();
	ft_strlcpy(number_of_lines_as_str, map_as_str, end_pos_of_first_line - 2);
	if (ft_str_is_numeric(number_of_lines_as_str) == 1)
	{
		line_count = ft_atoi(number_of_lines_as_str);
		config->line_count = line_count;
		free(number_of_lines_as_str);
	}
	if (ft_char_is_printable(map_as_str[end_pos_of_first_line - 3]))
		config->empty = map_as_str[end_pos_of_first_line - 3];
	if (ft_char_is_printable(map_as_str[end_pos_of_first_line - 2]))
		config->obstacle = map_as_str[end_pos_of_first_line - 2];
	if (ft_char_is_printable(map_as_str[end_pos_of_first_line - 1]))
		config->full = map_as_str[end_pos_of_first_line - 1];

	printf("1 -=> Number of lines: \"%d\"\n", config->line_count);
	printf("2 -=> Empty character: \"%c\"\n", config->empty);
	printf("3 -=> Obstacle character: \"%c\"\n", config->obstacle);
	printf("4 -=> Full character: \"%c\"\n", config->full);
	return (config);
}

/*
int	main(void)
{
	char			*map_as_str;
	t_config	config;

	config = init_config();
	map_as_str = "1234567890.x\n\n....ox\n";
	if (validate_config(set_config(map_as_str, &config)) == 0)
		map_error();
	else
	{
		printf("Number of lines: \"%d\"\n", config.line_count);
		printf("Empty character: \"%c\"\n", config.empty);
		printf("Obstacle character: \"%c\"\n", config.obstacle);
		printf("Full character: \"%c\"\n", config.full);
	}
}
*/