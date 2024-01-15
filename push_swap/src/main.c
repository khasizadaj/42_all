/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 18:57:52 by jkhasiza          #+#    #+#             */
/*   Updated: 2024/01/15 20:26:29 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc < 2)
		exit_for(NO_INPUT);
	if (!validate_input(argc, argv))
		exit_for(INVALID_INPUT);
	data = malloc(sizeof(t_data));
	if (!data)
		return (1);
	data->stack_a = NULL;
	data->stack_b = NULL;
	generate_stack(data, argc, argv);
	sort(data);
	ft_stackclear(&data->stack_a);
	ft_stackclear(&data->stack_b);
	free(data);
	return (0);
}
