/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 18:25:10 by jkhasiza          #+#    #+#             */
/*   Updated: 2024/01/16 18:27:12 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
#include "alg.h"

/* 
Handles stack with 3 three items.
=> 2 - 1 - 3
=> 1 - 3 - 2
=> 3 - 2 - 1

These are already sorted (no action needed):
=> 3 - 1 - 2
=> 1 - 2 - 3
=> 2 - 3 - 1
*/
void	sort_3_stack(t_number **stack_a)
{
	int	first;
	int	second;
	int	third;

	first = (*stack_a)->number;
	second = (*stack_a)->next->number;
	third = (*stack_a)->next->next->number;
	if (first > second && second < third && first < third)
		swap_a(stack_a);
	else if (first < second && second > third && first < third)
		swap_a(stack_a);
	else if (first > second && second > third && first > third)
		swap_a(stack_a);
}

void	sort_4_stack(t_number **stack_a, t_number **stack_b)
{
	int	i;

	i = ft_stackindex(stack_a, get_smallest(*stack_a));
	if (i == -1)
		return ;
	if (i == 1)
		rotate_a(stack_a);
	else if (i == 2)
	{
		rotate_a(stack_a);
		rotate_a(stack_a);
	}
	else if (i == 3)
		reverse_rotate_a(stack_a);
	push_b(stack_a, stack_b);
	sort_3_stack(stack_a);
	bring_smallest_to_top(stack_a);
	push_a(stack_a, stack_b);
}

void	sort_simple(t_number **stack_a, t_number **stack_b)
{
	if (ft_stacksize(*stack_a) == 1)
		return ;
	if (ft_stacksize(*stack_a) == 3)
		sort_3_stack(stack_a);
	if (ft_stacksize(*stack_a) == 2
		&& (*stack_a)->number > (*stack_a)->next->number)
		swap_a(stack_a);
	else if (ft_stacksize(*stack_a) == 4)
		sort_4_stack(stack_a, stack_b);
	bring_smallest_to_top(stack_a);
}
