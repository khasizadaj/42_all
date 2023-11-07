/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 13:01:42 by abied-ch          #+#    #+#             */
/*   Updated: 2023/06/15 14:58:53 by jkhasiza         ###   ########.fr       */
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

int	ft_find_next_prime(int nb)
{
	int	i;

	i = nb;
	if (nb <= 2)
		return (2);
	if (nb % 2 == 0)
		i += 1;
	while (!ft_is_prime(i))
	{
		i = i + 2;
	}
	return (i);
}

/* #include <stdio.h>
int	main(void)
{
	int nb = 2;
	printf("next prime number after %d is %d",nb, ft_find_next_prime(nb));
} */
