/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 19:56:43 by jkhasiza          #+#    #+#             */
/*   Updated: 2023/12/16 22:12:25 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	swap(t_number **stack)
{
    t_number *tmp;

    if (!(*stack) || !((*stack)->next))
        return (0);
    tmp = (*stack)->next;
    (*stack)->next = tmp->next;
    tmp->next = *stack;
    *stack = tmp;
	return (1);
}

void swap_a(t_number **stack)
{
	char *message;

	message = "sa";
    if (swap(stack) == 1)
		ft_printf("%s\n", message);
}

void swap_b(t_number **stack)
{
	char *message;

	message = "sb";
    if (swap(stack) == 1)
		ft_printf("%s\n", message);
}