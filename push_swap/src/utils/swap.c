/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 19:56:43 by jkhasiza          #+#    #+#             */
/*   Updated: 2024/01/08 17:13:45 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	swap(t_number **stack)
{
	t_number	*tmp;

	if (!(*stack) || !((*stack)->next))
		return (0);
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	tmp->next = *stack;
	*stack = tmp;
	return (1);
}

void	swap_a(t_number **stack)
{
	char	*message;

	message = "sa";
	if (swap(stack) == 1)
		ft_printf("%s\n", message);
}

void	swap_b(t_number **stack)
{
	char	*message;

	message = "sb";
	if (swap(stack) == 1)
		ft_printf("%s\n", message);
}

void swap_both(t_number **stack_a, t_number **stack_b)
{
	char	*message;

	message = "ss";
	if (swap(stack_a) == 1 && swap(stack_b) == 1)
		ft_printf("%s\n", message);
}
