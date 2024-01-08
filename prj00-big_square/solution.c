/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abied-ch <abied-ch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 04:46:47 by jkhasiza          #+#    #+#             */
/*   Updated: 2023/06/14 23:09:08 by abied-ch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include <stdio.h>

t_next_sol_arg	get_next_sol_arg(t_conf *conf, int size);
t_sol			init_solution(void);
void			update_solution(t_sol *final_solution, t_sol *curr_solution);

t_sol	find_next_solution(int i, int j, char **map, t_next_sol_arg *args)
{
	t_sol	solution;
	int		curr_row;
	int		curr_col;

	solution = init_solution();
	curr_row = i;
	if (i + args->next_size > args->conf->line_count)
		return (solution);
	while (curr_row < i + args->next_size)
	{
		curr_col = j;
		if (j + args->next_size > args->conf->width)
			return (solution);
		while (curr_col < j + args->next_size)
		{
			if (map[curr_row][curr_col] == args->conf->obstacle)
				return (solution);
			curr_col++;
		}
		curr_row++;
	}
	solution.start_i = i;
	solution.start_j = j;
	solution.size = args->next_size;
	return (solution);
}

t_sol	find_solution(char **map, t_conf conf)
{
	int				i;
	int				j;
	t_sol			f_sol;
	t_sol			curr_sol;
	t_next_sol_arg	next_sol_arg;

	i = -1;
	f_sol = init_solution();
	while (map[++i][0] != '\0')
	{
		j = -1;
		while (map[i][++j] != '\0')
		{
			next_sol_arg = get_next_sol_arg(&conf, f_sol.size + 1);
			curr_sol = find_next_solution(i, j, map, &next_sol_arg);
			while (curr_sol.start_i != -1 && f_sol.size < curr_sol.size)
			{
				update_solution(&f_sol, &curr_sol);
				next_sol_arg.next_size = f_sol.size + 1;
				curr_sol = find_next_solution(i, j, map, &next_sol_arg);
			}
		}
	}
	return (f_sol);
}

char	**fill_up_solution(t_conf *config, t_sol solution, char **map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	x = solution.start_i;
	while (x < solution.start_i + solution.size)
	{
		y = solution.start_j;
		while (y < solution.start_j + solution.size)
		{
			map[x][y] = config->full;
			y++;
		}
		x++;
	}
	return (map);
}
