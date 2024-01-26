/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 22:07:49 by jkhasiza          #+#    #+#             */
/*   Updated: 2024/01/26 23:04:16 by jkhasiza         ###   ########.fr       */
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

#endif