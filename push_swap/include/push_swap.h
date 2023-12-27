/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 18:54:35 by jkhasiza          #+#    #+#             */
/*   Updated: 2023/12/27 22:00:53 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../src/libft/libft.h"

#define STEP_SIZE 11
#define SWAP_A 0
#define SWAP_B 1
#define SWAP_BOTH 2

#define ROTATE_A 3
#define ROTATE_B 4
#define ROTATE_BOTH 5

#define REVROT_A 6
#define REVROT_B 7
#define REVROT_BOTH 8

#define PUSH_A 9
#define PUSH_B 10

typedef long long int lli;

void	apply(int *steps, t_list **stack_a, t_list **stack_b);
int		swap(t_list **stack);
void	swap_a(t_list **stack);
void	swap_b(t_list **stack);
void	swap_both(t_list **stack_a, t_list **stack_b);
int		rotate(t_list **stack);
void	rotate_a(t_list **stack);
void	rotate_b(t_list **stack);
void	rotate_both(t_list **stack_a, t_list **stack_b);
int		reverse_rotate(t_list **stack);
void	reverse_rotate_a(t_list **stack);
void	reverse_rotate_b(t_list **stack);
void	reverse_rotate_both(t_list **stack_a, t_list **stack_b);
void	push_a(t_list **stack_a, t_list **stack_b);
void	push_b(t_list **stack_a, t_list **stack_b);
int		*get_cheapest(t_list *from, t_list *to);
lli		get_location_to_move(lli val, t_list *to);
void	print_steps(int *steps, int size);

#endif