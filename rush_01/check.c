/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juitz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 11:14:10 by juitz             #+#    #+#             */
/*   Updated: 2023/06/04 15:54:23 by juitz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	skyscrapersy(int **array, int size, int y, int direction)
{
	int	i;
	int	count;
	int	max_value;

	max_value = 0;
	count = 0;
	if (direction > 0)
		i = 1;
	else
		i = size - 2;
	while ((direction > 0 && i < size - 1) || (direction < 0 && i > 0))
	{
		if (array[i][y] > max_value)
		{
			count++;
			max_value = array[i][y];
		}
		i += direction;
	}
	return (count);
}

int	skyscrapersx(int **array, int size, int x, int direction)
{
	int	i;
	int	count;
	int	max_value;

	max_value = 0;
	count = 0;
	if (direction > 0)
		i = 1;
	else
		i = size - 2;
	while ((direction > 0 && i < size - 1) || (direction < 0 && i > 0))
	{
		if (array[x][i] > max_value)
		{
			count++;
			max_value = array[x][i];
		}
		i += direction;
	}
	return (count);
}

int	check_row(int **array, int size, int x)
{	
	if (skyscrapersx(array, size, x, 1) != array[x][0])
		return (0);
	if (skyscrapersx(array, size, x, -1) != array[x][size - 1])
		return (0);
	return (1);
}

int	check_column(int **array, int size, int y)
{
	if (skyscrapersy(array, size, y, 1) != array[0][y])
		return (0);
	if (skyscrapersy(array, size, y, -1) != array[size - 1][y])
		return (0);
	return (1);
}

int	check_calculation(int **array, int size)
{
	int	x;
	int	y;

	y = 0;
	while (++y < size - 1)
	{
		if (check_column(array, size, y) == 0)
			return (0);
	}
	x = 0;
	while (++x < size - 1)
	{
		if (check_row(array, size, x) == 0)
			return (0);
	}
	return (1);
}
