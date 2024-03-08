/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 21:31:21 by jkhasizada        #+#    #+#             */
/*   Updated: 2024/02/04 00:22:48 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	free_numbers(int size, char **numbers)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		free(numbers[i]);
	}
	free(numbers);
}

/*
	Function returns the size of the stack and sets the raw_numbers
	parameter to either argv or a split of argv[1] by spaces.

	If the function returns -1, it means there was an error. Either
	there was non integer values or there was a malloc error.

	It can also catch the time that argv[1] is empty string. As ft_split
	still returns array with 1 empty string, fucntion considers this as
	an error as well.
*/
int	get_raw_numbers(char ***raw_numbers, int argc, char **argv)
{
	int		i;
	t_bool	has_noninteger;

	has_noninteger = FALSE;
	if (argc == 2)
	{
		*raw_numbers = ft_split(argv[1], ' ');
		if (!*raw_numbers)
			return (-1);
		i = -1;
		while ((*raw_numbers)[++i])
		{
			if (ft_str_isdigit((*raw_numbers)[i]) == false)
				has_noninteger = TRUE;
		}
		if (has_noninteger == TRUE || !(*raw_numbers)[0])
			return (free_numbers(i + 1, *raw_numbers), -1);
	}
	else
	{
		*raw_numbers = argv;
		i = argc - 1;
	}
	return (i);
}

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
		{
			if (argc == 2)
				free_numbers(data->size, raw_numbers);
			return ;
		}
		ft_stackadd_back(&(data->stack_a), new_elem);
	}
	if (argc == 2)
		free_numbers(data->size, raw_numbers);
}
