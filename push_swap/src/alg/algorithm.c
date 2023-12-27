/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 20:57:52 by jkhasiza          #+#    #+#             */
/*   Updated: 2023/12/27 22:07:38 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

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

void	get_steps_to_top_b(int lookup, int *steps, t_list *stack)
{
	int size;

	size = ft_lstsize(stack);
	// printf("Lookup: %d\n", lookup);

	if (lookup != 0 && size % 2 == 0 && lookup + 1 >= size / 2 + 1)
	{
		steps[7] = size - lookup;
		return ;
	}
	if (lookup != 0 && size % 2 == 1 && lookup + 1 > size / 2 + 1)
	{
		steps[7] = size - lookup;
		return ;
	}
	else if (lookup != 0)
	{
		steps[4] = lookup;
		return ;
	}
}

void	get_steps_to_top_a(int lookup, int *steps, t_list *stack)
{
	int size_a;

	size_a = ft_lstsize(stack);
	if (lookup != 0 && size_a % 2 == 0 && lookup + 1 >= size_a / 2 + 1)
	{
		steps[6] = size_a - lookup;
		return ;
	}
	if (lookup != 0 && size_a % 2 == 1 && lookup + 1 > size_a / 2 + 1)
	{
		steps[6] = size_a - lookup;
		return ;
	}
	else if (lookup != 0)
	{
		steps[3] = lookup;
		return ;
	}
}

lli get_largest(t_list *stack) {
    t_list *tmp;
    lli		i;
    lli		max;

    if (!stack)
		return (-1);
	i = 0;
    tmp = stack;
	max = (lli)tmp->content;
    while (tmp) {
        if ((lli)tmp->content >= max)
            max = (lli)tmp->content;
        tmp = tmp->next;
		i++;
    }
    return max;
}

/*
	This function return the position that moved element
	should be in. If returned value is 1, it means that
	moved element will be in that position, or it should
	be on top of current element on index 1. 
*/
lli	get_location_to_move(lli val, t_list *to)
{
	t_list	*tmp;
	lli		i;
	lli		location;
	lli		smallest;

    tmp = to;
    i = 0;
	smallest = get_largest(to);
	location = 0;
	if (val > smallest && smallest == (lli)tmp->content)
		return (0);
    while (tmp) {
        if ((lli)tmp->content<=smallest && val < (lli)tmp->content) 
		{
            smallest = (lli)tmp->content;
			location = i + 1;
		}
		if (val > smallest && val > (lli)tmp->content && val > (lli)tmp->next->content)
			return (i + 1);
        tmp = tmp->next;
        i++;
    }
	if (location == ft_lstsize(to))
		return (0);
	return (location);
}

void get_steps_to_b(int lookup, lli val, int *steps, t_list *from, t_list *to)
{
	lli location;

	// MAYBE SWAP CAN HAPPEN IF AVERAGE IS SMALL
	get_steps_to_top_a(lookup, steps, from);
	location = get_location_to_move(val, to);
	get_steps_to_top_b(location, steps, to);
	// TODO Optimisation missing
	steps[10] += 1;
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

int *get_cheapest(t_list *from, t_list *to)
{
	int 	*steps;
	int 	*cheapest;
	int		i;
	t_list	**tmp;

	if (!from || !to)
		return (NULL);
	steps = get_initial_steps(0);
	if (!steps)
		return (NULL);
	cheapest = get_initial_steps(2147483646);
	if (!cheapest)
		return (free(steps), NULL);
	i = 0;
	tmp = &from;
	while(*tmp)
	{
		get_steps_to_b(i, (lli) (*tmp)->content, steps, from, to);
		if (calculate_cost(steps) < calculate_cost(cheapest))
			ft_int_arrcpy(cheapest, steps, STEP_SIZE);
		tmp = &((*tmp)->next);
		reset_steps(steps);
		i++;
	}
	free(steps);
	return cheapest;
}
