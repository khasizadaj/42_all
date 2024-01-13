/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 19:31:57 by jkhasiza          #+#    #+#             */
/*   Updated: 2024/01/13 21:09:49 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
#include "alg.h"

/*
	Updates `steps` array with steps rotation steps needed for integer
	at index of `lookup` in the stack to reach the top of the stack
	at the destionation.

	`direction` switch is necessary for knowing which stack should be
	rotated as `steps` array contains information for both stacks. If
	`direction` is equal to "a", that means we are moving an integer
	at index of `lookup` from `stack_b` to `stack_a`. An then,
	this function adds calculated rotation for the destination
	which is `stack_a`.
*/
void	get_steps_to_top_at_to(int lookup, int *steps, t_number *stack,
	char direction)
{
	int	size;

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

/*
	Updates `steps` array with steps rotation steps needed for integer
	at index of `lookup` in the stack to reach the top of the stack
	at the origin.

	`direction` switch is necessary for knowing which stack should be
	rotated as `steps` array contains information for both stacks. If
	`direction` is equal to "a", that means we are moving an integer
	at index of `lookup` from `stack_b` to `stack_a`. An then,
	this function adds calculated rotation for the origin which is
	`stack_b`.
*/
void	get_steps_to_top_at_from(int lookup, int *steps, t_number *stack,
	char direction)
{
	int	size_a;

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

/*
	Finds the insert position for 'val' in a circular linked list 'to', 
	which is sorted in descending order. 
	
	The function identifies the position right after the smallest value
	that is bigger than 'val'. It also handles cases where the list's
	minimum value is followed by its maximum due to its circular nature.
*/
lli	get_location_to_move_reverse(lli val, t_number *to)
{
	t_number	*tmp;
	lli			i;
	lli			location;
	lli			smallest;

	tmp = to;
	i = 0;
	smallest = get_largest(to);
	location = 0;
	if (val > smallest && smallest == tmp->number)
		return (0);
	while (tmp)
	{
		if (tmp->number <= smallest && val < tmp->number)
		{
			smallest = tmp->number;
			location = i + 1;
		}
		else if (val > smallest && tmp->next && val > tmp->number
			&& tmp->number < tmp->next->number)
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
	which is sorted in ascending order.
	
	The function identifies the position right after the largest value
	that is smaller than 'val'. It also handles cases where the list's
	maximum value is followed by its minimum due to its circular nature.
*/
lli	get_location_to_move(lli val, t_number *to)
{
	t_number	*tmp;
	lli			i;
	lli			location;
	lli			smallest;

	tmp = to;
	i = 0;
	smallest = get_smallest(to);
	location = 0;
	if (val < smallest && smallest == tmp->number)
		return (0);
	while (tmp)
	{
		if (tmp->number >= smallest && val > tmp->number)
		{
			smallest = tmp->number;
			location = i + 1;
		}
		else if (val < smallest && tmp->next && val < tmp->number
			&& tmp->number > tmp->next->number)
			return (i + 1);
		tmp = tmp->next;
		i++;
	}
	if (location == ft_stacksize(to))
		return (0);
	return (location);
}
