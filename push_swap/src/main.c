/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 18:57:52 by jkhasiza          #+#    #+#             */
/*   Updated: 2024/01/06 13:16:41 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_data *data = malloc(sizeof(t_data));
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
	ft_stackclear(&data->stack_a);
	free(data);
	return (0);
}
