/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 19:30:26 by jkhasiza          #+#    #+#             */
/*   Updated: 2024/01/17 19:20:18 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALG_H
# define ALG_H

# include "../../include/push_swap.h"

void	sort_simple(t_number **stack_a, t_number **stack_b);

int		*get_cheapest(t_number *from, t_number *to, t_bool reverse);
t_lli	get_smallest(t_number *stack);
t_lli	get_largest(t_number *stack);

void	bring_smallest_to_top(t_number **stack);
void	get_steps_to_top_at_to(int lookup, int *steps, t_number *stack,
			char direction);
void	get_steps_to_top_at_from(int lookup, int *steps, t_number *stack,
			char direction);
t_lli	get_location_to_move_reverse(t_lli val, t_number *to);
t_lli	get_location_to_move(t_lli val, t_number *to);

int		*initialize_steps(int fill_value);
void	optimize(int *steps);
int		calculate_cost(int *steps);

#endif
