/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 18:54:35 by jkhasiza          #+#    #+#             */
/*   Updated: 2024/01/13 22:25:52 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../src/libft/libft.h"

# define INVALID_INPUT 1

# define STEP_SIZE 11
# define SWAP_A 0
# define SWAP_B 1
# define SWAP_BOTH 2

# define ROTATE_A 3
# define ROTATE_B 4
# define ROTATE_BOTH 5

# define REVROT_A 6
# define REVROT_B 7
# define REVROT_BOTH 8

# define PUSH_A 9
# define PUSH_B 10

typedef struct s_number
{
	int				number;
	struct s_number	*next;	
}	t_number;

typedef struct s_data
{
	int			size;
	t_number	*stack_a;	
	t_number	*stack_b;	
}	t_data;

typedef long long int lli;

void	generate_stack(t_data *data, int argc, char **argv);
void	apply(int *steps, t_number **stack_a, t_number **stack_b);
int		swap(t_number **stack);
void	swap_a(t_number **stack);
void	swap_b(t_number **stack);
void	swap_both(t_number **stack_a, t_number **stack_b);
int		rotate(t_number **stack);
void	rotate_a(t_number **stack);
void	rotate_b(t_number **stack);
void	rotate_both(t_number **stack_a, t_number **stack_b);
int		reverse_rotate(t_number **stack);
void	reverse_rotate_a(t_number **stack);
void	reverse_rotate_b(t_number **stack);
void	reverse_rotate_both(t_number **stack_a, t_number **stack_b);
void	push_a(t_number **stack_a, t_number **stack_b);
void	push_b(t_number **stack_a, t_number **stack_b);

/* ALGORITHM */
void	sort(t_data *data);

/* UTILS */
int		validate_input(int argc, char **argv);
void	print_steps(int *steps, int size);
void	print_stack(t_number *stack);
void	print_raw_numbers(char **raw_numbers);
int		get_raw_numbers(char ***raw_numbers, int argc, char **argv);
void	free_numbers(int size, char **numbers);

/* STACK UTILS */
t_number	*ft_stacknew(int number);
void		ft_stackadd_back(t_number **stack, t_number *new_elem);
void		ft_stackclear(t_number **stack);
int			ft_stacksize(t_number *lst);
int			ft_stackindex(t_number **stack, int lookup_value);

void	exit_for(int reason);

#endif