/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 18:20:04 by jkhasiza          #+#    #+#             */
/*   Updated: 2024/01/23 23:55:44 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	key_hook(int keycode, t_data *data)
{
	if (keycode == 65307)
		exit_gracefully(data, PROGRAM_HALTED_WITH_ESCAPE);
	else if (keycode == K_UP || keycode == K_ARR_UP)
		ft_printf("PRESSED UP\n");
	else if (keycode == K_DOWN || keycode == K_ARR_DOWN)
		ft_printf("PRESSED DOWN\n");
	else if (keycode == K_LEFT || keycode == K_ARR_LEFT)
		ft_printf("PRESSED LEFT\n");
	else if (keycode == K_RIGHT || keycode == K_ARR_RIGHT)
		ft_printf("PRESSED RIGHT\n");
	return (0);
}
