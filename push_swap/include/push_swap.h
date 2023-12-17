/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 18:54:35 by jkhasiza          #+#    #+#             */
/*   Updated: 2023/12/17 20:17:08 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../src/libft/libft.h"

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
int		reverse_rotate(t_number **stack);
void	reverse_rotate_a(t_number **stack);
void	reverse_rotate_b(t_number **stack);

#endif