/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 04:46:47 by jkhasiza          #+#    #+#             */
/*   Updated: 2023/06/14 12:47:20 by jkhasiza         ###   ########.fr       */
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
	printf("==find_next_solution\n");
	// printf("--find_next_solution: config->line_count: %d\n", config->line_count);
	// printf("map[%d][%d] = \"%c\"\n", i, j, map[i][j]);
	curr_row = i;
	if (i + size > config->line_count)
		return (solution);
	while ( curr_row < i + size)
	{
		// printf("First Loop\n");
		curr_col = j;
		printf("  curr_col: %d, curr_row: %d, j: %d, i: %d\n", curr_col, curr_row, j, i);
		if (j + size > 6)
			return (solution);
		while (curr_col < j + size) // TODO save width as well
		{
			// printf("Second Loop\n");
			if (map[curr_row][curr_col] == config->obstacle)
			{
				// printf("HEELEL\n");
				return (solution);
			}
			curr_col++;
		}
		curr_row++;
	}
	solution.start_i = i;
	solution.start_j = j;
	solution.size = size;
	printf("FOUND NEXT SOLTiON\n");
	return (solution);
}

void	find_solution(char **map, t_config conf)
{
	int			i;
	int			j;
	t_solution	final_solution;
	t_solution	current;

	i = 0;
	final_solution = init_solution();
	printf("BEFORE: final_solution.start_i: %d\n", final_solution.start_i);
	while (map[i][0] != '\0')
	{
		j = 0;
		// printf("map[%d][%d] = \"%c\"\n", i, 0, map[i][0]);
		while (map[i][j] != '\0')
		{
			// printf("map[%d][%d] = \"%c\"\n", i, j, map[i][j]);
			current = find_next_solution(i, j, map, final_solution.size + 1, &conf);
			while (current.start_i != -1 && final_solution.size < current.size)
			{
				// printf("Cont. Logic: cond1: %d, cond2: %d\n", current.start_i != -1, final_solution.size < current.size );
				// printf("==find_solution: current.start_i: %d\n", current.start_i);
				// printf("==find_solution: current.start_j: %d\n", current.start_j);
				// printf("==find_solution: current.size: %d\n", current.size);
				update_solution(&final_solution, &current);
				printf("\t==find_solution: final_solution.start_i: %d\n", final_solution.start_i);
				printf("\t==find_solution: final_solution.start_j: %d\n", final_solution.start_j);
				printf("\t==find_solution: final_solution.size: %d\n", final_solution.size);
				current = find_next_solution(i, j, map, final_solution.size + 1, &conf);
			}
			j++;
		}
		i++;
	}
}
