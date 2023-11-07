/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easy_solves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juitz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 11:28:04 by juitz             #+#    #+#             */
/*   Updated: 2023/06/04 11:41:16 by juitz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	fill_column(int **array, int size, int y, int increment)
{
	int	i;
	int	value;

	i = 1;
	value = 1;
	if (increment < 0)
		value = size -2;
	while (i < size - 1)
	{
		array[i][y] = value;
		i++;
		value += increment;
	}
}

void	fill_row(int **array, int size, int x, int increment)
{
	int	i;
	int	value;

	i = 1;
	value = 1;
	if (increment < 0)
		value = size - 2;
	while (i < size - 1)
	{
		array[x][i] = value;
		i++;
		value += increment;
	}
}

void	easy_solves_one_and_four(int **array, int size)
{
	int	y;
	int	x;

	y = 1;
	while (y < (size -1))
	{
		if (array[size - 1][y] == 1 && array[0][y] == (size - 2))
			fill_column(array, size, y, 1);
		else if (array[size - 1][y] == (size - 2) && array[0][y] == 1)
			fill_column(array, size, y, -1);
		y++;
	}
	x = 1;
	while (x < (size - 1))
	{	
		if (array[x][0] == (size - 2) && array[x][size - 1] == 1)
			fill_row(array, size, x, 1);
		else if (array[x][0] == 1 && array[x][size - 1] == (size - 2))
			fill_row(array, size, x, -1);
		x++;
	}
}

void	easy_solves_sum_of_edges(int **array, int size)
{
	int	y;
	int	x;

	y = 1;
	x = 1;
	while (y < (size - 1))
	{
		if (array[0][y] + array[size - 1][y] == (size - 1))
		{
			array[array[0][y]][y] = (size - 2);
		}
		y++;
	}
	while (x < (size - 1))
	{
		if (array[x][0] + array[x][size - 1] == (size - 1))
		{
			array[x][array[x][0]] = (size - 2);
		}
		x++;
	}
}

void	easy_solves(int **array, int size)
{
	easy_solves_one_and_four(array, size);
	easy_solves_sum_of_edges(array, size);
}
