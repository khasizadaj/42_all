/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasizada <jkhasizada@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 01:39:17 by jkhasizada        #+#    #+#             */
/*   Updated: 2023/12/23 01:50:31 by jkhasizada       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void print_steps(int *steps, int size)
{
    if (!steps) {
        ft_printf("The steps array is NULL.\n");
        return;
    }

	ft_printf("\n\t  A B * \n");
	ft_printf("\t---------\n");
    for (int i = 0; i < size; i++) {
		if (i == 0)
			ft_printf(" S\t[ ");
		if (i == 3)
			ft_printf("]\n R\t[ ");
		if (i == 6)
			ft_printf("]\n RR\t[ ");
		if (i == 9)
			ft_printf("]\n P\t[ ");
		ft_printf("%d", steps[i]);
		if (i != size - 1)
			ft_printf(" ");
    }
    ft_printf("]\n");
}