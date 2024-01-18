/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 20:57:52 by jkhasiza          #+#    #+#             */
/*   Updated: 2024/01/17 19:19:50 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
#include "alg.h"

/*
	Function returns largest number in the stack.

	Note: It doesn't handle NULL values, you should protect this function
	in outer scope.
*/
t_lli	get_largest(t_number *stack)
{
	t_number		*tmp;
	t_lli			i;
	t_lli			max;

	i = 0;
	tmp = stack;
	max = tmp->number;
	while (tmp)
	{
		if (tmp->number >= max)
			max = tmp->number;
		tmp = tmp->next;
		i++;
	}
	return (max);
}

/*
	Function returns smallest number in the stack.

	Note: It doesn't handle NULL values, you should protect this function
	in outer scope.
*/
t_lli	get_smallest(t_number *stack)
{
	t_number		*tmp;
	t_lli			i;
	t_lli			min;

	i = 0;
	tmp = stack;
	min = tmp->number;
	while (tmp)
	{
		if (tmp->number <= min)
			min = tmp->number;
		tmp = tmp->next;
		i++;
	}
	return (min);
}

/*
	Function calculates the needed steps for given number to be moved
	to the correct position from given stack `from` to given stack `to`.  
*/
int	*get_steps_to_move(t_lli val, t_number *from, t_number *to, t_bool reverse)
{
	t_lli	location;
	int		*steps;
	int		index_of_val;

	steps = initialize_steps(0);
	if (!steps)
		return (NULL);
	index_of_val = ft_stackindex(&from, val);
	if (reverse)
	{
		get_steps_to_top_at_from(index_of_val, steps, from, 'b');
		location = get_location_to_move_reverse(val, to);
		get_steps_to_top_at_to(location, steps, to, 'b');
		steps[PUSH_B] += 1;
	}
	else
	{
		get_steps_to_top_at_from(index_of_val, steps, from, 'a');
		location = get_location_to_move(val, to);
		get_steps_to_top_at_to(location, steps, to, 'a');
		steps[PUSH_A] += 1;
	}
	optimize(steps);
	return (steps);
}

int	*get_cheapest(t_number *from, t_number *to, t_bool reverse)
{
	int			*steps;
	int			*cheapest;
	int			i;
	t_number	**tmp;

	if (!from || !to)
		return (NULL);
	cheapest = initialize_steps(2147483646);
	if (!cheapest)
		return (NULL);
	i = 0;
	tmp = &from;
	while (*tmp)
	{
		steps = get_steps_to_move((*tmp)->number, from, to, reverse);
		if (!steps)
			return (NULL);
		if (calculate_cost(steps) < calculate_cost(cheapest))
			ft_int_arrcpy(cheapest, steps, STEP_SIZE);
		tmp = &((*tmp)->next);
		i++;
		free(steps);
	}
	return (cheapest);
}
