/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 22:07:49 by jkhasiza          #+#    #+#             */
/*   Updated: 2024/01/28 00:41:38 by jkhasiza         ###   ########.fr       */
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
int	test_map_is_valid_4x4(void);
int test_map_is_valid_5x5(void);
int	test_map_has_invalid_first_line(void);
int	test_map_has_invalid_body(void);

#endif