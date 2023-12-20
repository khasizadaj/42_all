/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 18:54:35 by jkhasiza          #+#    #+#             */
/*   Updated: 2023/12/20 22:40:16 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../src/libft/libft.h"

typedef long long int lli;

typedef struct s_number
{
	int				number;
	struct s_number	*next;
}	t_number;

int		swap(t_number **stack);
void	swap_a(t_number **stack);
void	swap_b(t_number **stack);
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
int		*get_cheapest(t_list *from, t_list *to);

#endif