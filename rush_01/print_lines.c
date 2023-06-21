/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psedlacz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 18:16:13 by psedlacz          #+#    #+#             */
/*   Updated: 2023/06/04 19:47:20 by jkozmus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_lines(int **array, int size, int edges)
{
	int		i;
	int		j;
	char 	c;
	int		start;
	int		end;

	start = 1;
	end = size - 1;
	if (edges)
	{
		start = 0;
		end = size;
	}


	i = start;
	while (i < end)
	{
		j = start;
		while (j < end)
		{	
			c = '0' + array[i][j];
			if (j < (end - 1))
			{
				ft_putchar(c);
				ft_putchar(' ');
			}
			else
				ft_putchar(c);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
