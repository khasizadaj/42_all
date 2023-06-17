/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_putnbr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 09:40:04 by jkhasiza          #+#    #+#             */
/*   Updated: 2023/05/29 01:29:12 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	check_edge_cases(int *nb)
{
	if (*nb == -2147483648)
	{
		write(1, "-2", 2);
		*nb = 147483648;
	}
	else if (*nb < 0)
	{
		write(1, "-", 1);
		*nb = *nb * -1;
	}
	else if (*nb == 0)
	{
		write(1, "0", 1);
	}
}

void	ft_putnbr(int nb)
{
	int	place_value;
	int	write_zero;
	int	char_value;

	check_edge_cases(&nb);
	write_zero = 0;
	place_value = 1000 * 1000 * 1000;
	while (place_value > 0)
	{
		if (nb / place_value != 0 || write_zero == 1)
		{
			write_zero = 1;
			char_value = nb / place_value + '0';
			write(1, &char_value, 1);
		}
		nb = nb % place_value;
		place_value /= 10;
	}
}
