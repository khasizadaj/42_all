/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 18:30:13 by abied-ch          #+#    #+#             */
/*   Updated: 2023/06/15 13:32:22 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	return (nb * (ft_recursive_power(nb, power - 1)));
}

/* #include <stdio.h>
#include <unistd.h>
int	main(void)
{
	int	nb = 5;
	int	power = 0;
	printf("%d^%d = %d\n", nb, power, ft_recursive_power(nb, power));
	// printf("nb = %d, power = %d\n", nb, power);
	// sleep (1);
	return(0);
}	
 */