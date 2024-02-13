/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 22:07:49 by jkhasiza          #+#    #+#             */
/*   Updated: 2024/01/29 21:55:21 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_VALIDATION_H
# define MAP_VALIDATION_H

# include "../../../libunit/include/libunit.h"
# include "../../include/so_long.h"

void	map_validation_launcher(t_passed *statuses);
int		test_has_invalid_characters(void);
int		test_line_is_longer_than_expected(void);
int		test_line_is_valid(void);
int     test_whole_line_is_valid_without_size_limit(void);
int     test_whole_line_is_invalid_without_size_limit(void);
int     test_line_is_null(void);

// GET MAP
int test_file_name_dont_exist(void);
int	test_map_has_valid_lines_4x4(void);
int	test_map_has_valid_lines_5x5(void);
int	test_map_has_invalid_first_line(void);
int	test_map_has_invalid_body(void);

// IS VALID MAP
int	test_map_has_missing_wall(void);
int	test_map_has_missing_wall_on_sides(void);
int	test_map_has_many_exits(void);
int	test_map_has_many_players(void);
int	test_map_is_not_rectangle(void);

// VALID PATH
int	test_map_has_no_valid_path(void);
int	test_map_has_no_valid_path_cannot_collect_all(void);
int	test_map_has_valid_path_simple(void);
int	test_map_has_valid_path_complex(void);
int	test_map_has_no_valid_path_complex(void);


#endif