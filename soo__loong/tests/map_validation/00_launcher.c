/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 22:21:30 by jkhasiza          #+#    #+#             */
/*   Updated: 2024/01/29 20:43:41 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_validation.h"

void	map_validation_launcher(t_passed *statuses)
{
	t_routine	*routine;

	routine = NULL;
	testlist_load(&routine, "is_valid_line",
		"Has invalid chars", &test_has_invalid_characters);
	testlist_load(&routine, "is_valid_line",
		"Line is longer than expected", &test_line_is_longer_than_expected);
	testlist_load(&routine, "is_valid_line",
		"Line has valid length.", &test_line_is_valid);
	testlist_load(&routine, "is_valid_line",
		"Whole line is valid where size doesn't matter.", &test_whole_line_is_valid_without_size_limit);
	testlist_load(&routine, "is_valid_line",
		"Whole line is invalid where size doesn't matter.", &test_whole_line_is_invalid_without_size_limit);
	testlist_load(&routine, "is_valid_line",
		"Line is null and invalid.", &test_line_is_null);
	testlist_load(&routine, "get_map",
		"File doesn't exist.", &test_file_name_dont_exist);
	testlist_load(&routine, "get_map",
		"File has valid lines for 4x4!", &test_map_has_valid_lines_4x4);
	testlist_load(&routine, "get_map",
		"File has valid lines for 5x5!", &test_map_has_valid_lines_5x5);
	testlist_load(&routine, "get_map",
		"Invalid character in first line", &test_map_has_invalid_first_line);
	testlist_load(&routine, "get_map",
		"Invalid character other lines", &test_map_has_invalid_body);
	testlist_load(&routine, "is_valid_map",
		"Map is missing wall (one corner).", &test_map_has_missing_wall);
	testlist_load(&routine, "is_valid_map",
		"Map is missing wall (on side).", &test_map_has_missing_wall_on_sides);
	testlist_load(&routine, "is_valid_map",
		"Map has many players.", &test_map_has_many_players);
	testlist_load(&routine, "is_valid_map",
		"Map has many exits.", &test_map_has_many_exits);
	testlist_load(&routine, "is_valid_map",
		"Map is not rectangle.", &test_map_is_not_rectangle);
	testlist_load(&routine, "is_valid_map",
		"No valid path to exit.", &test_map_has_no_valid_path);
	testlist_load(&routine, "is_valid_map",
		"No valid path to collect all.", &test_map_has_no_valid_path_cannot_collect_all);
	testlist_run(&routine, statuses);
	testlist_clear(&routine);
}