/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 21:01:31 by jkhasiza          #+#    #+#             */
/*   Updated: 2024/01/18 21:31:41 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	exit_for(int reason)
{
	if (reason == INVALID_MAP_NO_VALID_PATH)
		ft_printf(INVALID_MAP_MSG_NO_VALID_PATH);
	else if (reason == INVALID_MAP_NOT_RECTANGLE)
		ft_printf(INVALID_MAP_MSG_NOT_RECTANGLE);
	else if (reason == INVALID_MAP_WRONG_WALLS)
		ft_printf(INVALID_MAP_MSG_WRONG_WALLS);
	else if (reason == INVALID_MAP_WRONG_FILE_TYPE)
		ft_printf(INVALID_MAP_MSG_WRONG_FILE_TYPE);
	exit(1);
}