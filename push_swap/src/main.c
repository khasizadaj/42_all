/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 18:57:52 by jkhasiza          #+#    #+#             */
/*   Updated: 2023/12/28 22:50:48 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(void)
{
	int     fd;
	char    *line;
	int    *raw_integers;

	fd = open("../test/push_swap/10_numbers.txt", O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error number: %d\n", errno);
		perror("Closing program");
		return (1);
	}

	line = get_next_line(fd);
	ft_printf("[main]\t[l=%d]\t'%s'\n", (int) ft_strlen_until(line, '\0'), line);
	if (line == NULL)
		return (1);
	
	raw_integers = ft_split_convert_i(line, ' ');
	print_int_array(raw_integers);
	
	free(line);
	
	// Called to free buffer inside GNL
	line = get_next_line(fd);
	free(line);
	free(raw_integers);
	if (close(fd) < 0) {
		perror("Closing program");
		exit(1);
	}
	return (0);
}
