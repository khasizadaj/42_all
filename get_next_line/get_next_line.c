/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 17:08:27 by codespace         #+#    #+#             */
/*   Updated: 2023/10/05 21:41:45 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

 == GET NEXT LINE

This project is about programming a function that returns a line
read from a file descriptor.

*/

#include "get_next_line.h"

void	print_list(t_fd *list);

char	*get_next_line(int fd)
{
	static t_fd	*list = NULL;
	t_fd		*file;

	printf("\nCurr fd: %d\n", fd);
	// TODO: Add condition to free finished files but in list
	if (fd < 0)
		return (NULL);
	file = lstget(&list, fd);
	if (!file)
	{
		file = ft_lstnew(fd);
		if (!file)
			return (ft_lstclear(&list, &free), free(file), NULL);
		printf("new fd=%d\n", file->fd);
		ft_lstadd_back(&list, file);
	}
	// FIXME: Add logic to get rid of buffer when file finished
	// if (file)
	// 	ft_lstremove(&list, file);

	// TODO: DELETE THIS LATER
	// print all existing fds
	print_list(list);
	return ("");
}

void	print_list(t_fd *list)
{
	t_fd *current = list;
	if (!current)
		printf("\n========\nNO FILE LEFT\n");
	else
	{
		printf("\n========\nPRINT ALL FILES\n");
		while (current != NULL)
		{
			printf("fd=%d\n", current->fd);
			current = current->next;
		}
	}
	printf("========\n\n");
}