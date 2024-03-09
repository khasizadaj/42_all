/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 18:20:04 by jkhasiza          #+#    #+#             */
/*   Updated: 2024/03/09 19:47:21 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	key_hook(int keycode, t_data *data)
{
	if (data->attack[0] == '1' && keycode != K_ESC)
		return (0);
	if (keycode == K_ESC)
		exit_gracefully(data, PROGRAM_HALTED_WITH_ESCAPE);
	else if (keycode == K_UP || keycode == K_ARR_UP)
		move(data, K_UP);
	else if (keycode == K_DOWN || keycode == K_ARR_DOWN)
		move(data, K_DOWN);
	else if (keycode == K_LEFT || keycode == K_ARR_LEFT)
		move(data, K_LEFT);
	else if (keycode == K_RIGHT || keycode == K_ARR_RIGHT)
		move(data, K_RIGHT);
	else if (keycode == K_RIGHT || keycode == K_ARR_RIGHT)
		move(data, K_RIGHT);
	else if (keycode == K_E || keycode == K_Q)
		attack(data, keycode);
	return (0);
}

int	exit_hook(t_data *data)
{
	exit_gracefully(data, PROGRAM_HALTED_WITH_X_ICON);
	return (0);
}
