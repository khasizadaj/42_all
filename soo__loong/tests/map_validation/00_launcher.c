/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 22:21:30 by jkhasiza          #+#    #+#             */
/*   Updated: 2024/01/26 23:04:41 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_validation.h"

void	map_validation_launcher(t_passed *statuses)
{
	t_routine	*routine;

	routine = NULL;
	testlist_load(&routine, "is_valid_line", "Has invalid chars", &test_has_invalid_characters);
	testlist_load(&routine, "is_valid_line", "Line is longer than expected", &test_line_is_longer_than_expected);
	testlist_load(&routine, "is_valid_line", "Line has valid length.", &test_line_is_valid);
	testlist_run(&routine, statuses);
	testlist_clear(&routine);
}