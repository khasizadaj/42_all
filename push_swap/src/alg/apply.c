/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 20:20:44 by jkhasiza          #+#    #+#             */
/*   Updated: 2024/01/08 17:35:05 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
#include <stdio.h>

void	apply_push(int *steps, t_number **stack_a, t_number **stack_b)
{
	int	i;

	i = -1;
	while (++i < steps[PUSH_A])
		push_a(stack_a, stack_b);
	i = -1;
	while (++i < steps[PUSH_B])
		push_b(stack_a, stack_b);
	i = -1;
}

void	apply_swap(int *steps, t_number **stack_a, t_number **stack_b)
{
	int	i;

	i = -1;
	while (++i < steps[SWAP_A])
		swap_a(stack_a);
	i = -1;
	while (++i < steps[SWAP_B])
		swap_b(stack_b);
	i = -1;
	while (++i < steps[SWAP_BOTH])
		swap_both(stack_a, stack_b);
}

void	apply_rotate(int *steps, t_number **stack_a, t_number **stack_b)
{
	int	i;

	i = -1;
	while (++i < steps[ROTATE_A])
		rotate_a(stack_a);
	i = -1;
	while (++i < steps[ROTATE_B])
		rotate_b(stack_b);
	i = -1;
	while (++i < steps[ROTATE_BOTH])
		rotate_both(stack_a, stack_b);
}

void	apply_reverse_rotate(int *steps, t_number **stack_a, t_number **stack_b)
{
	int	i;

	i = -1;
	while (++i < steps[REVROT_A])
		reverse_rotate_a(stack_a);
	i = -1;
	while (++i < steps[REVROT_B])
		reverse_rotate_b(stack_b);
	i = -1;
	while (++i < steps[REVROT_BOTH])
		reverse_rotate_both(stack_a, stack_b);
}

void	apply(int *steps, t_number **stack_a, t_number **stack_b)
{
	apply_swap(steps, stack_a, stack_b);
	apply_rotate(steps, stack_a, stack_b);
	apply_reverse_rotate(steps, stack_a, stack_b);
	apply_push(steps, stack_a, stack_b);
}