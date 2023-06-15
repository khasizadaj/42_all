/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 13:24:25 by jkhasiza          #+#    #+#             */
/*   Updated: 2023/06/15 13:25:49 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	if (nb == 0)
		return (1);
	if (nb >= 1)
	{	
		return (nb * ft_recursive_factorial(nb - 1));
	}
	return (0);
}

/* #include <stdio.h>

int 	main(void)
{
	int	nb = 10;
	printf("fac %d = %d", nb, ft_recursive_factorial(nb));
	return (0);
} */
