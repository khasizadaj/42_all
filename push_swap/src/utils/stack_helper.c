/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 21:31:21 by jkhasizada        #+#    #+#             */
/*   Updated: 2024/01/05 17:14:48 by jkhasiza         ###   ########.fr       */
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

int	get_raw_numbers(char ***raw_numbers, int argc, char **argv)
{
	int	i;
	int	size;

	size = 0;
	if (argc == 2)
	{
        *raw_numbers = ft_split(argv[1], ' ');

        // Check if *raw_numbers is NULL (not !raw_numbers)
        if (!*raw_numbers)
            return -1;

        i = -1;
        while ((*raw_numbers)[++i])
        {
            size++;
        }
	}
	else
	{
		*raw_numbers = argv;
		size = argc - 1;
	}
	return (size);
}
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
