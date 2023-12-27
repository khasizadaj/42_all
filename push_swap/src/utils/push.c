/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 18:53:38 by jkhasiza          #+#    #+#             */
/*   Updated: 2023/12/27 19:29:19 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	push_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*first_b;

	first_b = (*stack_b);
	*stack_b = first_b->next;
	first_b->next = (*stack_a);
	*stack_a = first_b;
	ft_printf("pa\n");
}

void	push_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*first_a;

	first_a = (*stack_a);
	*stack_a = first_a->next;
	first_a->next = (*stack_b);
	*stack_b = first_a;
	ft_printf("pb\n");
}
