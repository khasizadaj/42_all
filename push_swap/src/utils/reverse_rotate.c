/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 19:28:08 by jkhasiza          #+#    #+#             */
/*   Updated: 2023/12/27 19:43:24 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	reverse_rotate(t_list **stack)
{
	t_list	*before_last;
	t_list	*last;

	if (!(*stack) || !((*stack)->next))
		return (0);
	before_last = *stack;
	last = before_last->next;
	while (last->next)
	{
		before_last = last;
		last = before_last->next;
	}
	before_last->next = NULL;
	last->next = *stack;
	*stack = last;
	return (1);
}

void	reverse_rotate_a(t_list **stack)
{
	char	*message;

	message = "rra";
	if (reverse_rotate(stack) == 1)
		ft_printf("%s\n", message);
}

void	reverse_rotate_b(t_list **stack)
{
	char	*message;

	message = "rrb";
	if (reverse_rotate(stack) == 1)
		ft_printf("%s\n", message);
}

void reverse_rotate_both(t_list **stack_a, t_list **stack_b)
{
	char	*message;

	message = "rrr";
	if (reverse_rotate(stack_a) == 1 && reverse_rotate(stack_b) == 1)
		ft_printf("%s\n", message);
}