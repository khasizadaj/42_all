/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 18:53:38 by jkhasiza          #+#    #+#             */
/*   Updated: 2024/01/08 17:13:40 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	push_a(t_number **stack_a, t_number **stack_b)
{
	t_number	*first_b;

	first_b = (*stack_b);
	*stack_b = first_b->next;
	first_b->next = (*stack_a);
	*stack_a = first_b;
	ft_printf("pa\n");
}

void	push_b(t_number **stack_a, t_number **stack_b)
{
	t_number	*first_a;

	first_a = (*stack_a);
	*stack_a = first_a->next;
	first_a->next = (*stack_b);
	*stack_b = first_a;
	ft_printf("pb\n");
}
