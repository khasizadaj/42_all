/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 16:49:56 by codespace         #+#    #+#             */
/*   Updated: 2024/01/08 17:45:13 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/*

sort (data)
push first two to stack_b
move to stack_b with logic until 3 elements in stack_a
sort stack_a
move to stack_a with logic until stack_b is empty

*/

void	sort(t_data *data)
{
	int	*steps;

	push_b(&data->stack_a, &data->stack_b);
	push_b(&data->stack_a, &data->stack_b);
	print_stack(data->stack_a);
	print_stack(data->stack_b);
	
	while (ft_stacksize(data->stack_a) > 3)
	{
		steps = get_cheapest(data->stack_a, data->stack_b);
		if (!steps)
			return ;
		apply(steps, &data->stack_a, &data->stack_b);
		print_steps(steps, 11);
		print_stack(data->stack_a);
		print_stack(data->stack_b);
		free(steps);
	}
	// sort 3 items in stack_a
	while (ft_stacksize(data->stack_b) > 0)
	{
		// TODO get_cheapest orders biggest to smallest. How to reverse it?
		// it gives steps for left to right, even though order of stacks changed
		steps = get_cheapest(data->stack_b, data->stack_a);
		if (!steps)
			return ;
		apply(steps, &data->stack_b, &data->stack_a);
		print_steps(steps, 11);
		print_stack(data->stack_a);
		print_stack(data->stack_b);
		free(steps);
	}

}