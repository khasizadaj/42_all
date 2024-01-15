/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 16:49:56 by codespace         #+#    #+#             */
/*   Updated: 2024/01/15 20:39:36 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
#include "alg.h"


void	bring_smallest_to_top(t_number **stack)
{
	int			val;
	int			*steps;
	int			i;

	val = get_smallest(*stack);
	i = ft_stackindex(stack, val);
	if (i == 0 || i == -1)
		return ;
	steps = initialize_steps(0);
	if (!steps)
		return ;
	get_steps_to_top_at_to(i, steps, *stack, 'a');
	apply(steps, stack, stack);
	free(steps);
}

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
void sort_3_stack(t_number **stack_a)
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

void sort_4_stack(t_number **stack_a, t_number **stack_b)
{
	int i;

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
	if (ft_stacksize(*stack_a) == 2 && (*stack_a)->number > (*stack_a)->next->number)
		swap_a(stack_a);
	else if (ft_stacksize(*stack_a) == 4)
		sort_4_stack(stack_a, stack_b);
	bring_smallest_to_top(stack_a);
}

int	sort_to_b(t_data *data)
{
	int	*steps;

	while (ft_stacksize(data->stack_a) > 3)
	{
		steps = get_cheapest(data->stack_a, data->stack_b, TRUE);
		if (!steps)
			return (SORT_FAILURE);
		apply(steps, &data->stack_a, &data->stack_b);
		free(steps);
	}
	return (SORT_SUCCESS);
}

int	sort_to_a(t_data *data)
{
	int	*steps;

	while (ft_stacksize(data->stack_b) > 0)
	{
		steps = get_cheapest(data->stack_b, data->stack_a, FALSE);
		if (!steps)
			return (SORT_FAILURE);
		apply(steps, &data->stack_a, &data->stack_b);
		free(steps);
	}
	return (SORT_SUCCESS);
}

void	sort(t_data *data)
{
	if (!data)
		return ;
	if (ft_stacksize(data->stack_a) <= 4)
	{
		sort_simple(&data->stack_a, &data->stack_b);
		return ;
	}
	push_b(&data->stack_a, &data->stack_b);
	push_b(&data->stack_a, &data->stack_b);
	if (sort_to_b(data) == SORT_FAILURE)
		return ;
	sort_simple(&data->stack_a, &data->stack_b);
	if (sort_to_a(data) == SORT_FAILURE)
		return ;
	bring_smallest_to_top(&data->stack_a);
}
