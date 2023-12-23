#ifndef TEST_H
# define TEST_H

#include "../include/push_swap.h"

void	print_list(t_list *stack);
void	print_lists(t_list *stack_a, t_list *stack_b);
void	print_steps(int *steps, int size);
void	test_swap(void);
void	test_push(void);
void	test_rotate(void);
void	test_reverse_rotate(void);
void	test_algorithm(void);

#endif