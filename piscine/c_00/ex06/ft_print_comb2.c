/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 20:37:04 by jkhasiza          #+#    #+#             */
/*   Updated: 2023/05/28 01:15:43 by jkhasiza         ###   ########.fr       */
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

void	ft_print(int a, int b)
{
	if (a >= 10)
		ft_putnbr(a);
	else
	{
		ft_putnbr(0);
		ft_putnbr(a);
	}
	write(1, " ", 1);
	if (b >= 10)
		ft_putnbr(b);
	else
	{
		ft_putnbr(0);
		ft_putnbr(b);
	}
}

void	ft_print_comb2(void)
{
	int	a;
	int	b;

	a = 0;
	b = 1;
	while (a <= 98)
	{
		while (b <= 99)
		{	
			ft_print(a, b);
			if (!(a == 98 && b == 99))
				write(1, ", ", 2);
			b++;
		}
		a++;
		b = a + 1;
	}
}
