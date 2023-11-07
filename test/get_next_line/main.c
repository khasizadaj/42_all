/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 17:44:53 by codespace         #+#    #+#             */
/*   Updated: 2023/11/01 14:53:00 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>

int main()
{
	int     fd;
	char    *line;

	fd = open("files/file_5.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Error number: %d\n", errno);
		perror("Program");
		return (1);
	}

	int i = -1;
	while (++i < 100)
	{
		line = get_next_line(fd);
		printf("[main]\t[l=%ld]\t'%s'\n", ft_strlen(line, '\0'), line);
		if (line == NULL)
			return (1);
		printf("\nLINES READ: %d\n\n\n", i + 1);
		free(line);
	}

	if (close(fd) < 0) {
		perror("Program");
		exit(1);
	}
	return (0);
}
