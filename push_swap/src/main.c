/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 18:57:52 by jkhasiza          #+#    #+#             */
/*   Updated: 2024/02/07 16:26:14 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdlib.h>

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc < 2)
		exit_for(NO_INPUT);
	if (!validate_input(argc, argv))
		exit_for(INVALID_INPUT);
	data.stack_a = NULL;
	data.stack_b = NULL;
	generate_stack(&data, argc, argv);
	if (!data.stack_a)
		return (1);
	if (!validate_stack_4_duplicates(&data.stack_a))
		return (ft_stackclear(&data.stack_a), exit_for(INVALID_INPUT), 1);
	if (is_already_sorted(&data.stack_a))
		return (ft_stackclear(&data.stack_a), 0);
	sort(&data);
	ft_stackclear(&data.stack_a);
	ft_stackclear(&data.stack_b);
	return (0);
}
