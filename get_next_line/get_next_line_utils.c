/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasizada <jkhasizada@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 17:29:54 by codespace         #+#    #+#             */
/*   Updated: 2023/10/17 19:24:07 by jkhasizada       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_fd	*ft_lstnew(int fd)
{
	t_fd	*node;
	int		i;

	node = malloc(sizeof(t_fd));
	if (!node)
		return (NULL);
	node->buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if(!node->buffer)
		return (free(node), NULL);
	i = -1;
	while(++i < BUFFER_SIZE)
		(node->buffer)[i] = (unsigned char) '\0';
	node->buffer[BUFFER_SIZE] = '\0';
	node->rd = 0;
	node->start = 0;
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
		temp = head->next;
        del(head->buffer);
	    free(head);
		head = temp;
	}
	del(head->buffer);
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

void ft_lstremove(t_fd **lst, t_fd *to_be_removed)
{
	t_fd	*current;

    if (!lst || !*lst || !to_be_removed)
        return;
    if (*lst == to_be_removed)
    {
        *lst = to_be_removed->next;
        free(to_be_removed->buffer);
		free(to_be_removed);
        return ;
    }

    current = *lst;
    while (current->next && current->next != to_be_removed)
        current = current->next;
    if (current->next)
    {
        current->next = current->next->next;
        free(to_be_removed->buffer);
		free(to_be_removed);
    }
}