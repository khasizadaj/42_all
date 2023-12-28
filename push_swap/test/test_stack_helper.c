/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_stack_helper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 20:24:28 by jkhasiza          #+#    #+#             */
/*   Updated: 2023/12/28 23:01:47 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
#include <stdlib.h>

void print_stack(t_number *stack)
{
    while (stack != NULL)
    {
        printf("%d -> ", stack->number);
        stack = stack->next;
    }
    printf("NULL\n");
}

void test_generate_stack()
{
	t_number	*stack_A;
	char	*input;
	char	**raw_integers;

	input = "1  2 3 4 5 6 7 8 9 10";

	raw_integers = ft_split(input, ' ');
	stack_A = generate_stack(raw_integers);
	if (!stack_A)
	{
		free(raw_integers);
	}
	print_stack(stack_A);

	if (stack_A->number == 1 && stack_A->next->number == 2
		&& stack_A->next->next->number == 3)
	{
		printf("PASS: generate_stack test passed!\n\n");
	}
	else
	{
		printf("FAIL: generate_stack test failed!\n\n");
	}

	free(raw_integers);
}

/* void test_generate_stack_empty()
{
	t_list	*stack_A;
	char	*input;
	char	*raw_integers;

	input = "";

	raw_integers = ft_split_convert_i(input, ' ');
	stack_A = generate_stack(raw_integers, 0);
	if (!stack_A)
	{
		free(raw_integers);
	}
	print_stack(stack_A);

	if (stack_A->content == 1 && stack_A->next->content == 2
		&& stack_A->next->next->content == 3 && ft_lstlast(stack_A)->content == 11)
	{
		printf("PASS: generate_stack test passed!\n\n");
	}
	else
	{
		printf("FAIL: generate_stack test failed!\n\n");
	}

	free(raw_integers);
	ft_lstclear_no_content(&stack_A);
} */

void test_stack_helper(void)
{
	test_generate_stack();
	// test_generate_stack_empty();
}