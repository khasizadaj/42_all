/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 19:56:43 by jkhasiza          #+#    #+#             */
/*   Updated: 2023/12/17 20:15:56 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	rotate(t_number **stack)
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

void rotate_a(t_number **stack)
{
	char *message;

	message = "ra";
    if (rotate(stack) == 1)
		ft_printf("%s\n", message);
}

void rotate_b(t_number **stack)
{
	char *message;

	message = "rb";
    if (rotate(stack) == 1)
		ft_printf("%s\n", message);
}