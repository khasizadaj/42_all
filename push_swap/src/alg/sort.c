/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 16:49:56 by codespace         #+#    #+#             */
/*   Updated: 2024/01/16 18:26:46 by jkhasiza         ###   ########.fr       */
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
