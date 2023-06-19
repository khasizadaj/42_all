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

void	print_lines(int **array, int size);
int		ft_calculate(int **board, int size);

int	**alloc_array(int size)
{
	int	**array;
	int	i;

	i = 0;
	array = malloc(sizeof(int *) * size);
	while (i < size)
	{
		array[i] = malloc(sizeof(int) * size);
		i++;
	}
	return (array);
}

void	populate_zero(int **array, int size)
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

void	populate_array(int **array, int *base, int size)
{
	int	b;
	int	k;

	b = 0;
	k = 1;
	while (base[b])
	{	
		while (b < size - 2)
			array[k++][0] = base[b++];
		k = 1;
		while ((size - 2) <= b && b < (size - 2) * 2)
			array[k++][size - 1] = base[b++];
		k = 1;
		while ((size - 2) * 2 <= b && b < (size - 2) * 3)
			array[0][k++] = base[b++];
		k = 1;
		while ((size - 2) * 3 <= b && b < (size - 2) * 4)
			array[size - 1][k++] = base[b++];
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
}

int	write_input(int *base, int size)
{
	int	**array;

	array = alloc_array(size);
	populate_zero(array, size);
	populate_array(array, base, size);
	if (ft_calculate(array, size) == 0)
	{
		free_array(array, size);
		return (0);
	}
	print_lines(array, size);
	free_array(array, size);
	return (1);
}
/*
int    write_input(int *base, int size)
{
	int	**array;
	int	i;
	int	b;
	int	k;
	
	i = 0;
	array = malloc(sizeof(int *) * (size));
	while (i < size)
		array[i++] = malloc(sizeof(int) * (size)); 
	k=1;
	b = 0;
	while (base[b])
	{
		while (b < ((size-2)))
			array[k++][0] = base[b++];
		k = 1;	
		while ((size-2) <= b && b < ((size-2)*2))
			array[k++][size-1] = base[b++];	
		k = 1;		
		while(((size-2)*2) <= b && b < ((size-2)*3))
			array[0][k++] = base[b++];
		k = 1;
		while ((((size-2)*3)) <= b && b < (size-2)*4)
			array[size-1][k++] = base[b++];

	}
	if (ft_calculate(array, size) == 0)
		return (0);
	print_lines(array, size);
	i = 0;
	while (i < size)
		free (array[i++]);
	return (1);
}*/
