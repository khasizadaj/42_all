/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 20:57:52 by jkhasiza          #+#    #+#             */
/*   Updated: 2024/01/12 21:48:40 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
#include <iso646.h>

/* 

	STEP MAPPING

	- 0 : sa
	- 1 : sb
	- 2 : ss
	- 3 : ra
	- 4 : rb
	- 5 : rr
	- 6 : rra
	- 7 : rrb
	- 8 : rrr
	- 9 : pa
	- 10 : pb

	We'll represent potential steps to reach destination using
	array. Every spot refers to certain step and whenever that
	step is taken, spot value will be Updated to '1' from its
	initial value of '0'.

	steps = [ 0 0 0 0 0 0 1 1 0 0 1]
              sa    ra    rra   pa
	It would take 4 steps for given number to reach 
	its destination.

*/

int *get_initial_steps(int fill_value)
{
	int	*steps;
	int	i;	

	steps = ft_calloc(STEP_SIZE, sizeof(int));
	if (!steps)
		return (NULL);
	i = -1;
	while (++i < STEP_SIZE)
		steps[i] = fill_value;
	return steps;
}

void optimize(int *steps)
{
    int	minCount;

    if (steps[SWAP_A] < steps[SWAP_B])
        minCount = steps[SWAP_A];
    else
        minCount = steps[SWAP_B];
    steps[SWAP_A] -= minCount;
    steps[SWAP_B] -= minCount;
    steps[SWAP_BOTH] += minCount;
    if (steps[ROTATE_A] < steps[ROTATE_B])
        minCount = steps[ROTATE_A];
    else
        minCount = steps[ROTATE_B];
    steps[ROTATE_A] -= minCount;
    steps[ROTATE_B] -= minCount;
    steps[ROTATE_BOTH] += minCount;
    if (steps[REVROT_A] < steps[REVROT_B])
        minCount = steps[REVROT_A];
    else
        minCount = steps[REVROT_B];
    steps[REVROT_A] -= minCount;
    steps[REVROT_B] -= minCount;
    steps[REVROT_BOTH] += minCount;
}

void	get_steps_to_top_at_to(int lookup, int *steps, t_number *stack, char direction)
{
	int size;

	size = ft_stacksize(stack);
	if (lookup != 0 && size % 2 == 0 && lookup + 1 >= size / 2 + 1)
	{
		if (direction == 'a')
			steps[REVROT_A] = size - lookup;
		else if (direction == 'b')
			steps[REVROT_B] = size - lookup;
	}
	else if (lookup != 0 && size % 2 == 1 && lookup + 1 > size / 2 + 1)
	{
		if (direction == 'a')
			steps[REVROT_A] = size - lookup;
		else if (direction == 'b')
			steps[REVROT_B] = size - lookup;
	}
	else if (lookup != 0)
	{
	
		if (direction == 'a')
			steps[ROTATE_A] = lookup;
		else if (direction == 'b')
			steps[ROTATE_B] = lookup;
	}
}

void	get_steps_to_top_at_from(int lookup, int *steps, t_number *stack, char direction)
{
	int size_a;

	size_a = ft_stacksize(stack);
	if (lookup != 0 && size_a % 2 == 0 && lookup + 1 >= size_a / 2 + 1)
	{
		if (direction == 'a')
			steps[REVROT_B] = size_a - lookup;
		else if (direction == 'b')
			steps[REVROT_A] = size_a - lookup;
	}
	else if (lookup != 0 && size_a % 2 == 1 && lookup + 1 > size_a / 2 + 1)
	{
		if (direction == 'a')
			steps[REVROT_B] = size_a - lookup;
		else if (direction == 'b')
			steps[REVROT_A] = size_a - lookup;
	}
	else if (lookup != 0)
	{
		if (direction == 'a')
			steps[ROTATE_B] = lookup;
		else if (direction == 'b')
			steps[ROTATE_A] = lookup;
	}
}

lli get_largest(t_number *stack) {
    t_number *tmp;
    lli		i;
    lli		max;

    if (!stack)
		return (-1);
	i = 0;
    tmp = stack;
	max = tmp->number;
    while (tmp) {
        if (tmp->number >= max)
            max = tmp->number;
        tmp = tmp->next;
		i++;
    }
    return max;
}

lli	get_smallest(t_number *stack) {
    t_number *tmp;
    lli		i;
    lli		min;

	// TODO Fix return value... it shouldn't be -1
    if (!stack)
		return (-1);
	i = 0;
    tmp = stack;
	min = tmp->number;
    while (tmp) {
        if (tmp->number <= min)
            min = tmp->number;
        tmp = tmp->next;
		i++;
    }
    return min;
}

/*
	Finds the insert position for 'val' in a circular linked list 'to', 
	which is sorted in descending order. The function identifies the 
	position right after the smallest value that is bigger than 'val'. 
	It also handles cases where the list's minimum value is followed by 
	its maximum due to its circular nature.
*/
lli	get_location_to_move_reverse(lli val, t_number *to)
{
	t_number	*tmp;
	lli		i;
	lli		location;
	lli		smallest;

    tmp = to;
    i = 0;
	smallest = get_largest(to);
	location = 0;
	if (val > smallest && smallest == tmp->number)
		return (0);
    while (tmp)
	{
		if (tmp->number<=smallest && val < tmp->number) 
		{
            smallest = tmp->number;
			location = i + 1;
		}
		else if (val > smallest && tmp->next && val > tmp->number &&
			tmp->number < tmp->next->number)
			return (i + 1);
        tmp = tmp->next;
        i++;
    }
	if (location == ft_stacksize(to))
		return (0);
	return (location);
}

/*
	Finds the insert position for 'val' in a circular linked list 'to', 
	which is sorted in ascending order. The function identifies the 
	position right after the largest value that is smaller than 'val'. 
	It also handles cases where the list's maximum value is followed by 
	its minimum due to its circular nature.
*/
lli	get_location_to_move(lli val, t_number *to)
{
	t_number	*tmp;
	lli		i;
	lli		location;
	lli		smallest;

    tmp = to;
    i = 0;
	smallest = get_smallest(to);
	location = 0;
	if (val < smallest && smallest == tmp->number)
		return (0);
    while (tmp)
	{
		if (tmp->number>=smallest && val > tmp->number) 
		{
            smallest = tmp->number;
			location = i + 1;
		}
		else if (val < smallest && tmp->next && val < tmp->number && tmp->number > tmp->next->number)
			return (i + 1);
        tmp = tmp->next;
        i++;
    }
	if (location == ft_stacksize(to))
		return (0);
	return (location);
}

int	*get_steps_to_move(int lookup, lli val, t_number *from, t_number *to, bool reverse)
{
	lli location;
	int	*steps;

	steps = get_initial_steps(0);
	if (!steps)
		return (NULL);
	// MAYBE SWAP CAN HAPPEN IF AVERAGE IS SMALL
	if (reverse)
	{
		get_steps_to_top_at_from(lookup, steps, from, 'b');
		location = get_location_to_move_reverse(val, to);
		get_steps_to_top_at_to(location, steps, to, 'b');
		steps[PUSH_B] += 1;
	}
	else
	{
		get_steps_to_top_at_from(lookup, steps, from, 'a');
	 	location = get_location_to_move(val, to);
		get_steps_to_top_at_to(location, steps, to, 'a');
		steps[PUSH_A] += 1;
	}
	optimize(steps);
	return (steps);
}

void	reset_steps(int *steps)
{
	int	i;

	i = 0;
	while (i < STEP_SIZE) {
		steps[i] = 0; 
		i++;
	}
}


int	calculate_cost(int *steps)
{
	int	result;
	int	i;

	i = -1;
	result = 0;
	while (++i < STEP_SIZE)
		result += steps[i];

	return result;
}

int *get_cheapest(t_number *from, t_number *to, bool reverse)
{
	int 	*steps;
	int 	*cheapest;
	int		i;
	t_number	**tmp;

	if (!from || !to)
		return (NULL);
	cheapest = get_initial_steps(2147483646);
	if (!cheapest)
		return (NULL);
	i = 0;
	tmp = &from;
	while(*tmp)
	{
		steps = get_steps_to_move(i,  (*tmp)->number, from, to, reverse);
		if (!steps)
			return (NULL);
		if (calculate_cost(steps) < calculate_cost(cheapest))
			ft_int_arrcpy(cheapest, steps, STEP_SIZE);
		tmp = &((*tmp)->next);
		// reset_steps(steps);
		i++;
		free(steps);
	}
	return cheapest;
}
