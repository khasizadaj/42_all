/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 20:19:26 by jkhasiza          #+#    #+#             */
/*   Updated: 2024/03/13 18:25:56 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

/*
 * Returns the current time in milliseconds since the Epoch.
 * Obtains current time in milliseconds with microsecond precision using
 * `gettimeofday`.
 */
long long	time_in_milliseconds(t_data *data)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) == -1)
		exit_gracefully(data, UNKNOWN_ERR);
	return ((((long long) tv.tv_sec) * 1000) + (tv.tv_usec / 1000));
}
