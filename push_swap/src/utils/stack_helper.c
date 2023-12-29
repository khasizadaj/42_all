/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasizada <jkhasizada@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 21:31:21 by jkhasizada        #+#    #+#             */
/*   Updated: 2023/12/29 22:55:49 by jkhasizada       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

t_number	*ft_stacknew(int number)
{
	t_number	*node;

	node = malloc(sizeof(t_number));
	if (node == NULL)
		return (NULL);
	node->number = number;
	node->next = NULL;
	return (node);
}

void	ft_stackadd_back(t_number **stack, t_number *new_elem)
{
	t_number *last;

	if (!stack || !new_elem)
		return ;
	if (!(*stack))
	{
		*stack = new_elem;
		return ;
	}
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = new_elem;
}

void	ft_stackclear(t_number **stack)
{
	t_number	*temp;

	if (stack == NULL || *stack == NULL)
		return ;
	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
}

void	free_numbers(t_data *data, char **numbers)
{
	int	i;

	i = -1;
	while (++i < data->size)
	{
		free(numbers[i]);
	}
	free(numbers);
}

void	generate_stack(t_data *data, int argc, char **argv)
{
	char	**raw_numbers;
	int		i;
	t_number	*new_elem;

	i = 0;
	if (argc == 2)
	{
		raw_numbers = ft_split(argv[1], ' ');
		i = -1;
		if (!raw_numbers)
			return ;
	}
	else
		raw_numbers = argv;
	while (++i <= data->size)
	{
		new_elem = ft_stacknew(ft_atoi(raw_numbers[i]));
		if (!new_elem)
			return ;
		ft_stackadd_back(&(data->stack_a), new_elem);
	}
	if (argc == 2)
		free_numbers(data, raw_numbers);
}
