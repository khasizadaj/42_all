/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 18:57:52 by jkhasiza          #+#    #+#             */
/*   Updated: 2024/01/07 14:30:31 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*

sort (data)
push first two to stack_b
move to stack_b with logic until 3 elements in stack_a
sort stack_a
move to stack_a with logic until stack_b is empty

*/

int	main(int argc, char **argv)
{
	t_data	*data = malloc(sizeof(t_data));

	if (!data)
		return (1);
	data->size = 5;
	data->stack_a = NULL;	
	data->stack_b = NULL;
	if (!validate_input(argc, argv))
	{
		free(data);
		exit_for(INVALID_INPUT);
	}
	generate_stack(data, argc, argv);
	print_stack(data->stack_a);
	// sort
	ft_stackclear(&data->stack_a);
	free(data);
	return (0);
}
