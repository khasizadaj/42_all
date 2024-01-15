/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 16:56:35 by codespace         #+#    #+#             */
/*   Updated: 2024/01/15 18:03:44 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	exit_for(int reason)
{
	if (reason == INVALID_INPUT)
		ft_printf("Input is not valid.\n");
	else if (reason == NO_INPUT)
		ft_printf("./push_swap\n");
	exit(reason);
}
