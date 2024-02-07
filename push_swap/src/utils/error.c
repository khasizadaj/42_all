/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 16:56:35 by codespace         #+#    #+#             */
/*   Updated: 2024/02/07 16:32:19 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	exit_for(int reason)
{
	if (reason == INVALID_INPUT)
		ft_putstr_fd("Error", 2);
	else if (reason == NO_INPUT)
		ft_putstr_fd("./push_swap\n", 2);
	exit(reason);
}
