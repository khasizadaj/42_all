/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 19:56:43 by jkhasiza          #+#    #+#             */
/*   Updated: 2023/12/27 20:54:40 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	swap(t_list **stack)
{
	t_list	*tmp;

	if (!(*stack) || !((*stack)->next))
		return (0);
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	tmp->next = *stack;
	*stack = tmp;
	return (1);
}

void	swap_a(t_list **stack)
{
	char	*message;

	message = "sa";
	if (swap(stack) == 1)
		ft_printf("%s\n", message);
}

void	swap_b(t_list **stack)
{
	char	*message;

	message = "sb";
	if (swap(stack) == 1)
		ft_printf("%s\n", message);
}

void swap_both(t_list **stack_a, t_list **stack_b)
{
	char	*message;

	message = "ss";
	if (swap(stack_a) == 1 && swap(stack_b) == 1)
		ft_printf("%s\n", message);
}
