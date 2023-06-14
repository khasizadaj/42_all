/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 19:42:29 by jkhasiza          #+#    #+#             */
/*   Updated: 2023/06/14 16:38:19 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_config
{
	int		line_count;
	char	empty;
	char	full;
	char	obstacle;
}	t_conf;

typedef struct s_solution
{
	int	start_i;
	int	start_j;
	int	size;
}	t_sol;

typedef struct s_next_sol_arg
{
	t_conf	*conf;
	int		next_size;
}	t_next_sol_arg;

#endif
