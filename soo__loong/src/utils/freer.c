/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 21:37:54 by jkhasiza          #+#    #+#             */
/*   Updated: 2024/02/04 21:39:19 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	free_get_next_line(int fd, char **line)
{
	while (*line)
	{
		free(*line);
		get_next_line(fd, line, false);
	}
}
