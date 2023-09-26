/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 02:50:45 by jkhasiza          #+#    #+#             */
/*   Updated: 2023/05/29 02:52:33 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	write_letters(int *a, int *b, int *c)
{
	write(1, a, 1);
	write(1, b, 1);
	write(1, c, 1);
}

void	add_comma(void)
{
	char	comma;
	char	empty;

	comma = 44;
	empty = 32;
	write(1, &comma, 1);
	write(1, &empty, 1);
}

void	ft_print_comb(void)
{
	int	a;
	int	b;
	int	c;

	a = '0';
	b = '1';
	c = '2';
	while (a <= '7')
	{
		while (b <= '8')
		{
			while (c <= '9')
			{
				write_letters(&a, &b, &c);
				if (a != '7')
					add_comma();
				c += 1;
			}
			b += 1;
			c = b + 1;
		}
		a += 1;
		b = a + 1;
		c = b + 1;
	}
}
