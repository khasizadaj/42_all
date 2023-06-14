/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abied-ch <abied-ch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 19:18:55 by abied-ch          #+#    #+#             */
/*   Updated: 2023/06/14 20:15:56 by abied-ch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "structs.h"

char	*open_and_read(char *file);
int		check_validity(char *str, t_conf *config);
void	memory_error(void);
void	map_error(void);
void	argument_error(void);
t_conf	init_config(void);
int		validate_config(t_conf *config);
t_conf	*set_config(char *map_as_str, t_conf *config);
void	ft_putstr(char *str);
t_sol	find_solution(char **map, t_conf conf);
int		compare_length(char *str, int lines_count);
int		count_lines(char *str);
char	*get_numbers_of_lines(char *map_as_str, int size);
void	print_map(char **map);
int		ft_strlen(char *str);
int		ft_strstr_pos(char *str, char *to_find);

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
		j = -1;
		while (map_as_str[k] != '\n' && map_as_str[k] != '\0')
			map [i][++j] = map_as_str[k++];
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
	ft_putstr("\n==== MAP START \n\n");
	while (map[++i][0] != '\0')
	{
		ft_putstr(map[i]);
		ft_putstr("\n");
	}
	ft_putstr("\n==== MAP END \n\n");
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

int	main(int argc, char *argv[])
{
	char	*map_as_str;
	t_conf	config;
	char	**map;
	t_sol	solution;

	if (argc == 1)
		argument_error();
	map_as_str = open_and_read(argv[1]);
	if (map_as_str == NULL)
		memory_error();
	config = init_config();
	if (validate_config(set_config(map_as_str, &config)) == 0)
		map_error();

	// printf("\n%s\n\n", map_as_str);
	// printf("\nValidity: %d\n", check_validity(map_as_str, &config));

	map = generate_map_array(map_as_str, &config);
	print_map(map);
	solution = find_solution(map, config);

	printf("solution.start_i: %d\n", solution.start_i);
	printf("solution.start_j: %d\n", solution.start_j);
	printf("solution.size: %d\n", solution.size);
	free_us(map);
	free(map_as_str);
	return (0);
}
