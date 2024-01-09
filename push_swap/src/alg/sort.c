/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 16:49:56 by codespace         #+#    #+#             */
/*   Updated: 2024/01/09 17:42:48 by jkhasiza         ###   ########.fr       */
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

// void	sort_simple(t_data *data)
// {
	// 1 < 2 && 2 < 3
	// 1 < 2 && 2!<3 ->>>> ra,
// }

void	sort(t_data *data)
{
	int	*steps;

	push_b(&data->stack_a, &data->stack_b);
	push_b(&data->stack_a, &data->stack_b);
	// print_stack(data->stack_a);
	// print_stack(data->stack_b);
	
	while (ft_stacksize(data->stack_a) > 3)
	{
		steps = get_cheapest(data->stack_a, data->stack_b, true);
		if (!steps)
			return ;
		apply(steps, &data->stack_a, &data->stack_b);
		print_steps(steps, 11);
		print_stack(data->stack_a);
		print_stack(data->stack_b);
		free(steps);
	}
	// sort 3-5 items in stack_a
	// bring biggest to top in stack_b
	while (ft_stacksize(data->stack_b) > 0)
	{
		steps = get_cheapest(data->stack_b, data->stack_a, false);
		if (!steps)
			return ;
		apply(steps, &data->stack_a, &data->stack_b);
		print_steps(steps, 11);
		print_stack(data->stack_a);
		print_stack(data->stack_b);
		free(steps);
	}
	// bring biggest to top in stack_a
}