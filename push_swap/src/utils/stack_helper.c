/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 21:31:21 by jkhasizada        #+#    #+#             */
/*   Updated: 2024/01/14 13:35:47 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	ft_stackindex(t_number **stack, int lookup_value)
{
	int			i;
	t_bool		found;
	t_number	*tmp;

	if (!stack || !(*stack))
		return (-1);
	tmp = *stack;
	found = FALSE;
	i = 0;
	while (tmp && !found)
	{
		if (lookup_value == tmp->number)
		{
			found = TRUE;
			break ;
		}
		tmp = tmp->next;
		i++;
	}
	if (!found)
		return (-1);
	return (i);
}

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

void	ft_stackadd_back(t_number **stack, t_number *new_elem)
{
	t_number	*last;

	if (!stack || !new_elem)
		return ;
	if (!(*stack))
	{
		*stack = new_elem;
		return ;
	}
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = new_elem;
}

int	ft_stacksize(t_number *lst)
{
	int			count;
	t_number	*temp;

	if (lst == NULL)
		return (0);
	count = 1;
	temp = lst;
	while (temp->next != NULL)
	{
		temp = temp->next;
		count++;
	}
	return (count);
}

void	ft_stackclear(t_number **stack)
{
	t_number	*temp;

	if (stack == NULL || *stack == NULL)
		return ;
	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
}
