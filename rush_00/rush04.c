/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaintha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 10:22:00 by shaintha          #+#    #+#             */
/*   Updated: 2023/05/27 13:29:43 by shaintha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	printfline(int x, int currentline)
{
	int	xcount;

	xcount = 1;
	while (xcount <= x)
	{
		if (currentline == 1)
		{
			if (xcount == 1)
				ft_putchar('A');
			else if (xcount == x)
				ft_putchar('C');
			else
				ft_putchar('B');
		}
		else
		{
			if (xcount == 1)
				ft_putchar('C');
			else if (xcount == x)
				ft_putchar('A');
			else
				ft_putchar('B');
		}
		xcount++;
	}	
}

void	printeline(int x)
{
	int	xcount;

	xcount = 1;
	while (xcount <= x)
	{
		if (xcount == 1 || xcount == x)
		{
			ft_putchar('B');
		}
		else
		{
			ft_putchar(' ');
		}
		xcount++;
	}
}

void	rush(int x, int y)
{
	int	ycount;

	if (x >= 1 && y >= 1)
	{
		ycount = 1;
		while (ycount <= y)
		{
			if (ycount == 1)
				printfline(x, 1);
			else if (ycount == y)
				printfline(x, ycount);
			else
				printeline(x);
			ft_putchar('\n');
			ycount++;
		}
	}
	else
		write(1, "ERROR: The width and length cannot be smaller than 1!\n", 54);
}
