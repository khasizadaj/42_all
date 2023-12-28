/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 18:21:07 by jkhasiza          #+#    #+#             */
/*   Updated: 2023/12/28 23:04:33 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

t_number	*ft_stacknew(int number)
{
	t_number	*node;

	node = malloc(sizeof(t_number));
	if (node == NULL)
		return (NULL);
	node->number = number;
	node->next = NULL;
	return (node);
}

t_number	*ft_stacklast(t_number *lst)
{
	t_number	*last;

	if (lst == NULL)
		return (NULL);
	last = lst;
	while (last->next != NULL)
	{
		last = last->next;
	}
	return (last);
}

void	ft_stackadd_back(t_number **lst, t_number *new_elem)
{
	t_number	*last;

	if (lst == NULL || new_elem == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new_elem;
		return ;
	}
	last = ft_stacklast(*lst);
	last->next = new_elem;
}


t_number	*generate_stack(char **raw_integers)
{
	t_number	*stack;
	t_number	*new_elem;
	int		i;
	int		val;

	i = -1;
	while (raw_integers[++i])
	{
		val = ft_atoi(raw_integers[i]);
		new_elem = ft_stacknew(val);
		if (!new_elem)
			return (/*ft_lstclear_no_content(&stack),*/ NULL);
		ft_stackadd_back(&stack, new_elem);
	}
	return stack;
}

