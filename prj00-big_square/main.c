/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abied-ch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 19:18:55 by abied-ch          #+#    #+#             */
/*   Updated: 2023/06/12 19:20:00 by abied-ch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char	*open_and_read(char *file);
int	check_validity(char *str);

int	main(int argc, char *argv[])
{
	char *str = open_and_read(argv[1]);
	if (str == NULL)
		// TODO Update it with proper error.
		return (0);
	
	if (argc != 0)
	{
		printf("%s\n\n", str);
		printf("%d", check_validity(str));
	}
	free(str);
	return (0);
}
