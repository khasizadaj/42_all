/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_instructions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 19:56:43 by jkhasiza          #+#    #+#             */
/*   Updated: 2023/12/16 22:30:22 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
#include <stdio.h>

int	reverse(t_number **stack)
{
    t_number	*tmp;
	t_number	*head;

    if (!(*stack) || !((*stack)->next))
        return (0);
    tmp = (*stack)->next;
    head = (*stack);
	while ((*stack)->next)
	{
		*stack = (*stack)->next;
	}
	(*stack)->next = head;
    (*stack)->next->next = NULL;
    *stack = tmp;
	return (1);
}

void reverse_a(t_number **stack)
{
	char *message;

	message = "ra";
    if (reverse(stack) == 1)
		ft_printf("%s\n", message);
}

void reverse_b(t_number **stack)
{
	char *message;

	message = "rb";
    if (reverse(stack) == 1)
		ft_printf("%s\n", message);
}