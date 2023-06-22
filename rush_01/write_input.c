/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juitz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 12:46:55 by juitz             #+#    #+#             */
/*   Updated: 2023/06/04 22:06:43 by jkozmus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	print_lines(int **array, int size, int edges);
int		ft_calculate(int **board, int size);

int	**allocate_array(int size)
{
	int	**array;
	int	i;

	i = 0;
	array = malloc(sizeof(int *) * size);
	if (array == NULL)
		return NULL;
	while (i < size)
	{
		array[i] = malloc(sizeof(int) * size);
		i++;
	}
	return (array);
}

void	populate_initial_values(int **array, int size)
{
	int	b;
	int	k;

	b = 0;
	while (b < size)
	{
		k = 0;
		while (k < size)
		{
			array[b][k] = 0;
			k++;
		}
		b++;
	}
}

void	populate_inputs(int **array, int *base, int size)
{
	int	b;
	int	k;

	b = 0;
	int size_of_map = size - 2;
	while (base[b])
	{	
		// populate top row
		k = 1;
		while ((size_of_map) * 2 <= b && b < (size_of_map) * 3)
			array[0][k++] = base[b++];
		// populate bottom row
		k = 1;
		while ((size_of_map) * 3 <= b && b < (size_of_map) * 4)
			array[size - 1][k++] = base[b++];
		// populate left column
		k = 1;
		while (b < size_of_map)
			array[k++][0] = base[b++];
		// populate right column
		k = 1;
		while ((size_of_map) <= b && b < (size_of_map) * 2)
			array[k++][size - 1] = base[b++];
	}
}

void	free_array(int **array, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

int	**get_populated_array(int *base, int size)
{
	int	**array;
	
	array = allocate_array(size);
	if (array == NULL)
		return NULL;
	populate_initial_values(array, size);
	populate_inputs(array, base, size);

	return (array);
}

int	write_input(int *base, int size)
{
	int	**array;

	array = get_populated_array(base, size);
	if (array == NULL)
		return (0);

	if (ft_calculate(array, size) == 0)
	{
		free_array(array, size);
		return (0);
	}
	print_lines(array, size, 0);
	return (1);
}

/*

    3 3 2 1
    | | | |
4 - 1 2 3 4 - 1
3 - 2 3 4 1 - 2
1 - 4 1 2 3 - 2
2 - 3 4 1 2 - 2
	| | | |
	2 1 3 3

*/
