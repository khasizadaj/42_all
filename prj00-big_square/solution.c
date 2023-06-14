/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 04:46:47 by jkhasiza          #+#    #+#             */
/*   Updated: 2023/06/14 16:10:46 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include <stdio.h>

t_solution	init_solution(void)
{
	t_solution	solution;


	solution.start_i = -1;
	solution.start_j = -1;
	solution.size = 0;
	return (solution);
}

void	update_solution(t_solution *final_solution, t_solution *current)
{
	final_solution->start_i = current->start_i;
	final_solution->start_j = current->start_j;
	final_solution->size = current->size;
}

t_solution	find_next_solution(int i, int j, char **map, int size, t_config *config)
{
	t_solution	solution;
	int			curr_row;
	int			curr_col;

	solution = init_solution();
	curr_row = i;
	if (i + size > config->line_count)
		return (solution);
	while (curr_row < i + size)
	{
		curr_col = j;
		if (j + size > 6) // TODO save width as well
			return (solution);
		while (curr_col < j + size) 
		{
			if (map[curr_row][curr_col] == config->obstacle)
			{
				return (solution);
			}
			curr_col++;
		}
		curr_row++;
	}
	solution.start_i = i;
	solution.start_j = j;
	solution.size = size;
	return (solution);
}

t_solution	find_solution(char **map, t_config conf)
{
	int			i;
	int			j;
	t_solution	final_solution;
	t_solution	current;

	i = 0;
	final_solution = init_solution();
	while (map[i][0] != '\0')
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			current = find_next_solution(i, j, map, final_solution.size + 1, &conf);
			while (current.start_i != -1 && final_solution.size < current.size)
			{
				update_solution(&final_solution, &current);
				current = find_next_solution(i, j, map, final_solution.size + 1, &conf);
			}
			j++;
		}
		i++;
	}
	return (final_solution);
}
