/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 19:18:55 by abied-ch          #+#    #+#             */
/*   Updated: 2023/06/13 20:31:48 by jkhasiza         ###   ########.fr       */
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

int	main(int argc, char *argv[])
{
	char		*map_as_str;
	t_config	config;

	if (argc == 1)
		argument_error();
	map_as_str = open_and_read(argv[1]);
	if (map_as_str == NULL)
		memory_error();
	config = init_config();
	if (validate_config(set_config(map_as_str, &config)) == 0)
		map_error();

	printf("\n%s\n\n", map_as_str);
	printf("%d", check_validity(map_as_str, &config));

	free(map_as_str);
	return (0);
}
