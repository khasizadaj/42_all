/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 16:49:56 by codespace         #+#    #+#             */
/*   Updated: 2024/01/12 21:49:55 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

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
void	sort_simple(t_number **stack) {
    int	first;
	int	second;
	int	third;

    first = (*stack)->number;
    second = (*stack)->next->number;
    third = (*stack)->next->next->number;
    if (first > second && second < third && first < third)
        swap_a(stack);
    else if (first < second && second > third && first < third) 
        swap_a(stack);
    else if (first > second && second > third && first > third)
	    swap_a(stack);
}

// TODO What to do if sort steps fail
void	bring_smallest_to_top(t_number **stack)
{
	int	val;
	int			*steps;
	t_number	*tmp;
	int			i;

	steps = get_initial_steps(0);
	if (!steps)
		return ;
	val = get_smallest(*stack);
	tmp = *stack;
	i = 0;
    while (tmp) {
        if (tmp->number == val)
			break ;
        tmp = tmp->next;
		i++;
    }
	if (i == 0)
		return ;
	get_steps_to_top_at_to(i, steps, *stack, 'a');
	apply(steps, stack, stack);
	free(steps);
}

void	sort(t_data *data)
{
	int	*steps;

	push_b(&data->stack_a, &data->stack_b);
	push_b(&data->stack_a, &data->stack_b);	
	while (ft_stacksize(data->stack_a) > 3)
	{
		steps = get_cheapest(data->stack_a, data->stack_b, true);
		if (!steps)
			return ;
		apply(steps, &data->stack_a, &data->stack_b);
		free(steps);
	}
	sort_simple(&data->stack_a);
	while (ft_stacksize(data->stack_b) > 0)
	{
		steps = get_cheapest(data->stack_b, data->stack_a, false);
		if (!steps)
			return ;
		apply(steps, &data->stack_a, &data->stack_b);
		free(steps);
	}
	bring_smallest_to_top(&data->stack_a);
}
