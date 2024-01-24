/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 18:20:04 by jkhasiza          #+#    #+#             */
/*   Updated: 2024/01/24 20:09:51 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	key_hook(int keycode, t_data *data)
{
	if (keycode == 65307)
		exit_gracefully(data, PROGRAM_HALTED_WITH_ESCAPE);
	else if (keycode == K_UP || keycode == K_ARR_UP)
		move(data, K_UP);
	else if (keycode == K_DOWN || keycode == K_ARR_DOWN)
		move(data, K_DOWN);
	else if (keycode == K_LEFT || keycode == K_ARR_LEFT)
		move(data, K_LEFT);
	else if (keycode == K_RIGHT || keycode == K_ARR_RIGHT)
		move(data, K_RIGHT);
	return (0);
}
