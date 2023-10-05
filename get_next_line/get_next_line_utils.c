/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 17:29:54 by codespace         #+#    #+#             */
/*   Updated: 2023/10/05 20:37:47 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_fd	*ft_lstnew(int fd)
{
	t_fd	*node;

	node = malloc(sizeof(t_fd));
	if (!node)
		return (NULL);
	// node->buffer = content;
	node->fd = fd;
	node->next = NULL;
	return (node);
}

void	ft_lstadd_back(t_fd **lst, t_fd *new)
{
	t_fd	*last;

	if (lst == NULL || new == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	if (lst == NULL)
		return ;
	last = *lst;
	while (last->next != NULL)
	{
		last = last->next;
	}
	last->next = new;
}

void	ft_lstclear(t_fd **lst, void (*del)(void *))
{
	t_fd	*head;
	t_fd	*temp;

	if (lst == NULL || *lst == NULL)
		return ;
	head = *lst;
	temp = *lst;
	while (head->next != NULL)
	{
		head = temp->next;
        // del(head->buffer);
        del(NULL);
	    free(head);
		temp = head;
	}
	// del(head->buffer);
    del(NULL);
	free(head);
	*lst = NULL;
	return ;
}

t_fd *lstget(t_fd **lst, int fd)
{
	t_fd *current;

	current = *lst; 
	while (current != NULL)
	{
		if (current->fd == fd)
			return current;
		current = current->next;
	}
	return (NULL);
}