/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 19:18:55 by abied-ch          #+#    #+#             */
/*   Updated: 2023/06/14 04:40:18 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "structs.h"

char		*open_and_read(char *file);
int			check_validity(char *str, t_config *config);
void		memory_error(void);
void		map_error(void);
void		argument_error(void);
t_config	init_config(void);
int			validate_config(t_config *config);
t_config	*set_config(char *map_as_str, t_config *config);
void		ft_putstr(char *str);

char	**generate_map_array(char *map_as_str)
{
	char	**map;

	// TODO update sizeof() later on
	map = malloc((8 + 1) * sizeof(map_as_str));
	map[0] = "......";
	map[1] = "..o...";
	map[2] = "..o...";
	map[3] = "..oo..";
	map[4] = "oo....";
	map[5] = "...o..";
	map[6] = "......";
	map[7] = "......";
	map[8] = "\0";

	return (map);
}

void	print_map(char **map)
{
	int	i;

	i = -1;

	ft_putstr("\n==== MAP START \n\n");
	while (map[++i][0])
	{
		ft_putstr(map[i]);
		ft_putstr("\n");
	}
	ft_putstr("\n==== MAP END \n\n");
}

int	main(int argc, char *argv[])
{
	char		*map_as_str;
	t_config	config;
	char **map;

	if (argc == 1)
		argument_error();
	map_as_str = open_and_read(argv[1]);
	if (map_as_str == NULL)
		memory_error();
	config = init_config();
	if (validate_config(set_config(map_as_str, &config)) == 0)
		map_error();


	// printf("\n%s\n\n", map_as_str);
	printf("\nValidity: %d\n", check_validity(map_as_str, &config));

	map = generate_map_array("");
	print_map(map);

	free(map_as_str);
	return (0);
}
