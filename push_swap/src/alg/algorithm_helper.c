/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 22:34:28 by jkhasiza          #+#    #+#             */
/*   Updated: 2024/01/13 22:35:27 by jkhasiza         ###   ########.fr       */
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
	if (lookup <= 0)
		return ;
	if (direction == 'a')
	{
		if ((size % 2 == 0 && lookup + 1 >= size / 2 + 1)
			|| (size % 2 == 1 && lookup + 1 > size / 2 + 1))
			steps[REVROT_A] = size - lookup;
		else
			steps[ROTATE_A] = lookup;
	}
	else if (direction == 'b')
	{
		if ((size % 2 == 0 && lookup + 1 >= size / 2 + 1)
			|| (size % 2 == 1 && lookup + 1 > size / 2 + 1))
			steps[REVROT_B] = size - lookup;
		else
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
	int	size;

	size = ft_stacksize(stack);
	if (lookup <= 0)
		return ;
	if (direction == 'a')
	{
		if ((size % 2 == 0 && lookup + 1 >= size / 2 + 1)
			|| (size % 2 == 1 && lookup + 1 > size / 2 + 1))
			steps[REVROT_B] = size - lookup;
		else
			steps[ROTATE_B] = lookup;
	}
	else if (direction == 'b')
	{
		if ((size % 2 == 0 && lookup + 1 >= size / 2 + 1)
			|| (size % 2 == 1 && lookup + 1 > size / 2 + 1))
			steps[REVROT_A] = size - lookup;
		else
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
lli	get_location_to_move_reverse(lli val, t_number *stack)
{
	lli			i;
	lli			location;
	lli			smallest;

	i = 0;
	smallest = get_largest(stack);
	location = 0;
	if (val > smallest && smallest == stack->number)
		return (0);
	while (stack)
	{
		if (stack->number <= smallest && val < stack->number)
		{
			smallest = stack->number;
			location = i + 1;
		}
		else if (val > smallest && stack->next && val > stack->number
			&& stack->number < stack->next->number)
			return (i + 1);
		stack = stack->next;
		i++;
	}
	if (location == ft_stacksize(stack))
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
	lli			i;
	lli			location;
	lli			largest;

	i = 0;
	largest = get_smallest(to);
	location = 0;
	if (val < largest && largest == to->number)
		return (0);
	while (to)
	{
		if (to->number >= largest && val > to->number)
		{
			largest = to->number;
			location = i + 1;
		}
		else if (val < largest && to->next && val < to->number
			&& to->number > to->next->number)
			return (i + 1);
		to = to->next;
		i++;
	}
	if (location == ft_stacksize(to))
		return (0);
	return (location);
}
