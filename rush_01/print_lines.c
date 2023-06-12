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

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_lines(int **array, int size)
{
	int	i;
	int	j;

	i = 1;
	while (i < size -1)
	{
		j = 1;
		while (j < size -1)
		{	
			if (j < (size - 2))
			{
				ft_putchar(array[i][j] + 48);
				ft_putchar(' ');
			}
			else
				ft_putchar(array[i][j] + 48);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
