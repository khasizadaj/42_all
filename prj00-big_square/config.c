/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 18:48:25 by jkhasiza          #+#    #+#             */
/*   Updated: 2023/06/12 22:08:26 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int		ft_atoi(char *str);
int		ft_strstr_pos(char *str, char *to_find);
char	*ft_strncpy(char *dest, char *src, unsigned int n);

struct s_config
{
	int		line_count;
	char	empty;
	char	full;
	char	obstacle;
};

int	validate_config(struct s_config *config)
{
	if (config->line_count < 0)
		return (0);
	if (config->empty == '\0' || config->full == '\0'
		|| config->obstacle == '\0')
		return (0);
	return (1);
}

struct s_config	init_config(void)
{
	struct s_config	config;

	config.line_count = -1;
	config.empty = '\0';
	config.full = '\0';
	config.obstacle = '\0';
	return (config);
}

struct s_config	*set_config(char *map_as_str, struct s_config *config)
{
	int				line_count;
	int				pos_of_newline;
	char			*number_of_lines_as_str;

	pos_of_newline = ft_strstr_pos(map_as_str, "\n");
	if (pos_of_newline > 13)
		return (config);
	number_of_lines_as_str = malloc(sizeof(char) * pos_of_newline - 2);
	ft_strncpy(number_of_lines_as_str, map_as_str, pos_of_newline - 2);
	number_of_lines_as_str[pos_of_newline - 2] = '\0';
	line_count = ft_atoi(number_of_lines_as_str); // TODO Validate input
	config->line_count = line_count;
	config->empty = map_as_str[pos_of_newline - 3]; // TODO Validate input
	config->obstacle = map_as_str[pos_of_newline - 2]; // TODO Validate input
	config->full = map_as_str[pos_of_newline - 1]; // TODO Validate input
	return (config);
}

void	map_error(void)
{
	write(1, "map error\n", 10);
	exit(0);
}

/*
int	main(void)
{
	char			*map_as_str;
	struct s_config	config;

	config = init_config();
	map_as_str = "1234567890.ox\n....ox\n";
	if (validate_config(set_config(map_as_str, &config)) == 0)
		map_error();
	printf("Number of lines: \"%d\"\n", config.line_count);
	printf("Empty character: \"%c\"\n", config.empty);
}
*/