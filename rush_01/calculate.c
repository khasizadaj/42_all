/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkozmus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 22:29:46 by jkozmus           #+#    #+#             */
/*   Updated: 2023/06/04 22:38:37 by jkozmus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	check_row(int **array, int size, int x);
int	check_column(int **array, int size, int y);
int	check_calculation(int **array, int size);
int	skyscrapersy(int **array, int size, int y, int direction);
int	skyscrapersx(int **array, int size, int x, int direction);
int	ft_possible(int **board, int x, int y, int value, int size);
int	ft_calculate(int **board, int size);

// int	check_values(int **board, int i, int j, int val)
// {
// 	int	size;
// 	int	k;

// 	k = 0;
// 	while (board[k])
// 		k++;
// 	size = k;
// 	if (ft_possible(board, i, j, val, size))
// 	{	
// 		board[i][j] = val;
// 		if (skyscrapersx(board, size, i, 1) <= board[i][0] &&
// 		skyscrapersy(board, size, j, 1) <= board[0][j])
// 		{
// 			if (ft_calculate(board, size))
// 				return (1);
// 		}
// 		board[i][j] = 0;
// 	}
// 	return (0);
// }

// int	process_board(int **board, int size, int i)
// {
// 	int	j;
// 	int	val;

// 	j = 1;
// 	while (j < size - 1)
// 	{
// 		if (board[i][j] == 0)
// 		{
// 			val = 1;
// 			while (val <= size - 2)
// 			{
// 				if (check_values(board, i, j, val))
// 					return (1);
// 				val++;
// 			}
// 			return (0);
// 		}
// 		j++;
// 	}
// 	if (check_row(board, size, i) == 0)
// 		return (0);
// 	return (1);
// }

// int	ft_calculate(int **board, int size)
// {	
// 	int	count;
// 	int	i;

// 	count = 0;
// 	i = 1;
// 	while (i < size - 1)
// 	{
// 		if (!process_board(board, size, i))
// 			return (0);
// 		i++;
// 	}	
// 	count++;
// 	if (count >= 2000000)
// 		return (0);
// 	if (check_calculation(board, size) == 1)
// 		return (1);
// 	return (0);
// }

int	ft_possible(int **board, int x, int y, int value, int size)
{
	int	i;

	i = 1;
	while (i < (size - 1))
	{
		if (board[x][i] == value)
			return (0);
		i++;
	}
	i = 1;
	while (i < (size - 1))
	{
		if (board[i][y] == value)
			return (0);
		i++;
	}
	return (1);
}

int	ft_calculate(int **board, int size)
{
	int	i;
	int	j;
	int	result;
	int	val;

	i = 1;
	while (i < size - 1)
	{
		j = 1;
		while (j < size - 1)
		{
			if (board[i][j] == 0)
			{
				val = 1;
				while (val <= size - 2)
				{
					if (ft_possible(board, i, j, val, size))
					{
						board[i][j] = val;
						if (skyscrapersx(board, size, i, 1) <= board[i][0] &&
							skyscrapersy(board, size, j, 1) <= board[0][j])
						{
							result = ft_calculate(board, size);
							if (result == 1)
								return (1);
						}
						board[i][j] = 0;
					}
					val++;
				}
			}
			if (board[i][j] == 0)
				return (0);
			j++;
		}
		if (check_row(board, size, i) == 0)
			return (0);
		i++;
	}
	if (check_calculation(board, size) == 1)
	{
		return (1);
	}
	return (0);
}
