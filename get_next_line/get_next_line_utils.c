/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasizada <jkhasizada@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 17:29:54 by codespace         #+#    #+#             */
/*   Updated: 2023/10/17 21:16:06 by jkhasizada       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

t_fd	*lstget_or_create(t_fd **lst, int fd)
{
	t_fd	*current;
	int		i;

	current = *lst;
	while (current != NULL)
	{
		if (current->fd == fd)
			return (current);
		current = current->next;
	}
	current = malloc(sizeof(t_fd));
	if (!current)
		return (NULL);
	current->buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!current->buffer)
		return (free(current), NULL);
	i = -1;
	while (++i < BUFFER_SIZE)
		(current->buffer)[i] = (unsigned char) '\0';
	current->buffer[BUFFER_SIZE] = '\0';
	current->rd = 0;
	current->fd = fd;
	current->next = NULL;
	ft_lstadd_back(lst, current);
	return (current);
}

void	ft_lstremove(t_fd **lst, t_fd *to_be_removed)
{
	t_fd	*current;

	if (!lst || !*lst || !to_be_removed)
		return ;
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

char	*ft_strjoin_until(const char *s1, const char *s2, char until)
{
	int		len_1;
	int		len_2;
	char	*joined;
	int		i;

	len_1 = ft_strlen(s1, '\0');
	len_2 = ft_strlen(s2, '\n');
	joined = malloc(sizeof(char) * (len_1 + len_2 + 1));
	if (joined == NULL)
		return (NULL);
	i = -1;
	while (s1[++i] != '\0')
	{
		joined[i] = s1[i];
	}
	i = 0;
	while (s2[i] != '\0')
	{
		joined[len_1 + i] = s2[i];
		if (s2[i++] == until)
			break ;
	}
	joined[len_1 + i] = '\0';
	return (joined);
}
