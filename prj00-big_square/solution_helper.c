/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution_helper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abied-ch <abied-ch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 23:06:05 by abied-ch          #+#    #+#             */
/*   Updated: 2023/06/14 23:06:49 by abied-ch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include <stdio.h>

t_next_sol_arg	get_next_sol_arg(t_conf *conf, int size)
{
	t_next_sol_arg	next_sol_arg;

	next_sol_arg.conf = conf;
	next_sol_arg.next_size = size;
	return (next_sol_arg);
}

t_sol	init_solution(void)
{
	t_sol	solution;

	solution.start_i = -1;
	solution.start_j = -1;
	solution.size = 0;
	return (solution);
}

void	update_solution(t_sol *final_solution, t_sol *curr_solution)
{
	final_solution->start_i = curr_solution->start_i;
	final_solution->start_j = curr_solution->start_j;
	final_solution->size = curr_solution->size;
}
