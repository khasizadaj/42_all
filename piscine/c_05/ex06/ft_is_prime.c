/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 12:06:09 by abied-ch          #+#    #+#             */
/*   Updated: 2023/06/15 14:57:07 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	i;

	i = 2;
	if (nb == 2)
		return (1);
	if (nb <= 1)
		return (0);
	if (nb % i == 0)
		return (0);
	while (i <= nb / i)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

/* #include <stdio.h>
int	main(void)
{
//	printf("%d", ft_is_prime(11));
	int nb = 2000000011;
	if (ft_is_prime(nb) == 1)
	printf("%d is a prime number!!", nb);
	else
	printf("%d is not a prime number:(((", nb);
	return (0);
} */
