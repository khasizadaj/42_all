/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 19:30:26 by jkhasiza          #+#    #+#             */
/*   Updated: 2024/01/14 13:34:13 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALG_H
# define ALG_H

# include "../../include/push_swap.h"

int		*get_cheapest(t_number *from, t_number *to, t_bool reverse);
lli		get_smallest(t_number *stack);
lli		get_largest(t_number *stack);

void	get_steps_to_top_at_to(int lookup, int *steps, t_number *stack,
			char direction);
void	get_steps_to_top_at_from(int lookup, int *steps, t_number *stack,
			char direction);
lli		get_location_to_move_reverse(lli val, t_number *to);
lli		get_location_to_move(lli val, t_number *to);

int		*initialize_steps(int fill_value);
void	optimize(int *steps);
int		calculate_cost(int *steps);

#endif