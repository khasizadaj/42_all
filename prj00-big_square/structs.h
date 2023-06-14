/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 19:42:29 by jkhasiza          #+#    #+#             */
/*   Updated: 2023/06/14 05:35:14 by jkhasiza         ###   ########.fr       */
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
}	t_config;

typedef struct s_solution
{
	int	start_i;
	int	start_j;
	int	size;
}	t_solution;

#endif
