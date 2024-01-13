/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   steps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 19:42:15 by jkhasiza          #+#    #+#             */
/*   Updated: 2024/01/13 20:10:14 by jkhasiza         ###   ########.fr       */
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

int	*initialize_steps(int fill_value)
{
	int	*steps;
	int	i;	

	steps = ft_calloc(STEP_SIZE, sizeof(int));
	if (!steps)
		return (NULL);
	i = -1;
	while (++i < STEP_SIZE)
		steps[i] = fill_value;
	return (steps);
}

void	optimize(int *steps)
{
	int	min_count;

	if (steps[SWAP_A] < steps[SWAP_B])
		min_count = steps[SWAP_A];
	else
		min_count = steps[SWAP_B];
	steps[SWAP_A] -= min_count;
	steps[SWAP_B] -= min_count;
	steps[SWAP_BOTH] += min_count;
	if (steps[ROTATE_A] < steps[ROTATE_B])
		min_count = steps[ROTATE_A];
	else
		min_count = steps[ROTATE_B];
	steps[ROTATE_A] -= min_count;
	steps[ROTATE_B] -= min_count;
	steps[ROTATE_BOTH] += min_count;
	if (steps[REVROT_A] < steps[REVROT_B])
		min_count = steps[REVROT_A];
	else
		min_count = steps[REVROT_B];
	steps[REVROT_A] -= min_count;
	steps[REVROT_B] -= min_count;
	steps[REVROT_BOTH] += min_count;
}

int	calculate_cost(int *steps)
{
	int	result;
	int	i;

	i = -1;
	result = 0;
	while (++i < STEP_SIZE)
		result += steps[i];
	return (result);
}
