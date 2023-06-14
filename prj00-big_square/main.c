/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abied-ch <abied-ch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 23:09:35 by abied-ch          #+#    #+#             */
/*   Updated: 2023/06/14 23:12:10 by abied-ch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "structs.h"
#include "sample_header.h"

char	**generate_map_array(char *map_as_str, t_conf *conf)
{
	char	**map;
	int		i;
	int		j;
	int		k;

	i = 0;
	k = ft_strstr_pos(map_as_str, "\n") + 1;
	map = malloc((conf->line_count + 1) * sizeof(char *));
	while (i < conf->line_count)
	{
		map[i] = malloc((conf->width + 1) * sizeof(char));
		j = 0;
		while (map_as_str[k] != '\n' && map_as_str[k] != '\0')
		{
			map [i][j] = map_as_str[k++];
			j++;
		}
		map[i][j] = '\0';
		k++;
		i++;
	}
	map[i] = malloc(sizeof(char));
	map[i][0] = '\0';
	return (map);
}

void	print_map(char **map)
{
	int	i;

	i = -1;
	while (map[++i][0] != '\0')
	{
		ft_putstr(map[i]);
		ft_putstr("\n");
	}
	ft_putstr("\n");
}

void	free_us(char **map)
{
	int	i;

	i = 0;
	while (map[i][0] != 0)
	{
		free(map[i]);
		i++;
	}
	free(map[i]);
	free(map);
}

void	std_in(void)
{
	char		*map_as_str;
	t_conf		config;
	char		**map;
	t_sol		solution;

	map_as_str = read_file(0);
	if (map_as_str == NULL)
		memory_error();
	config = init_config();
	if (validate_config(set_config(map_as_str, &config)) == 0)
		map_error();
	map = generate_map_array(map_as_str, &config);
	solution = find_solution(map, config);
	map = fill_up_solution(&config, solution, map);
	ft_putstr("\n");
	print_map(map);
	free_us(map);
	free(map_as_str);
}

int	main(int argc, char *argv[])
{
	char		*map_as_str;
	t_conf		config;
	char		**map;
	t_sol		solution;
	int			i;

	i = 0;
	if (argc == 1)
		std_in();
	while (++i < argc)
	{
		map_as_str = open_and_read(argv[i]);
		if (map_as_str == NULL)
			memory_error();
		config = init_config();
		if (validate_config(set_config(map_as_str, &config)) == 0)
			map_error();
		map = generate_map_array(map_as_str, &config);
		solution = find_solution(map, config);
		map = fill_up_solution(&config, solution, map);
		print_map(map);
		free_us(map);
		free(map_as_str);
	}
	return (0);
}
