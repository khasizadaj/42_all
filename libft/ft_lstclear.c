/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 20:14:48 by codespace         #+#    #+#             */
/*   Updated: 2023/09/24 07:54:41 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*head;
	t_list	*temp;

	if (lst == NULL || *lst == NULL)
		return ;
	head = *lst;
	temp = *lst;
	while (head->next != NULL)
	{
		head = temp->next;
		del(temp->content);
		free(temp);
		temp = head;
	}
	del(head->content);
	free(head);
	*lst = NULL;
	return ;
}
