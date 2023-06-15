/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 13:22:14 by jkhasiza          #+#    #+#             */
/*   Updated: 2023/06/15 13:23:46 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	multiplier;

	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	multiplier = nb - 1;
	while (multiplier > 1)
	{
		nb = nb * multiplier;
		multiplier--;
	}
	return (nb);
}

/*
#include <stdio.h>

int 	main(void)
{
	char	nb = 13;
	printf("fac %d = %d", nb, ft_iterative_factorial(nb));
	return (0);
}*/
