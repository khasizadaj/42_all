/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 21:31:21 by jkhasizada        #+#    #+#             */
/*   Updated: 2024/01/08 16:56:05 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/*
	TODO Check if we can get rid of data->size and make it temporary.
*/
void	generate_stack(t_data *data, int argc, char **argv)
{
	char		**raw_numbers;
	int			i;
	t_number	*new_elem;

	i = 0;
	raw_numbers = NULL;
	data->size = get_raw_numbers(&raw_numbers, argc, argv);
	if (data->size == -1)
		return ;
	if (argc == 2)
		i = -1;
	while (raw_numbers[++i])
	{
		new_elem = ft_stacknew(ft_atoi(raw_numbers[i]));
		if (!new_elem)
			return ;
		ft_stackadd_back(&(data->stack_a), new_elem);
	}
	if (argc == 2)
		free_numbers(data->size, raw_numbers);
}
