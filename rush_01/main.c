/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkozmus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 19:48:10 by jkozmus           #+#    #+#             */
/*   Updated: 2023/06/04 21:42:42 by jkozmus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	base_array(char *arg, int *base);
int	validate_input(char *str);
int	write_input(int *base, int size);

int	error(void)
{
	write(1, "Error\n", 6);
	return (0);
}

int	memory_error(void)
{
	write(1, "Memory error\n", 13);
	return (0);
}

int	main(int argc, char *argv[])
{
	int		*base;
	int		count_of_inputs;
	char	*arg;

	base = malloc(sizeof(int) * 100);
	if (base == NULL)
		memory_error();

	arg = argv[1];
	if (argc != 2)
		return (error());
	if (validate_input(argv[1]) == 0)
		return (error());
	count_of_inputs = base_array(arg, base);
	printf("Count of elements: %d\n", count_of_inputs);

	for (int i = 0; i < count_of_inputs; i++)
	{
		printf("%d ", base[i]);
	}
	
	if (count_of_inputs % 4 != 0)
		return (error());
	int size = (count_of_inputs / 4) + 2;
	
	printf("Size of map: %d\n", size);
	if (write_input(base, size) == 0)
	{
		printf("Failure");
		free(base);
		return (error());
	}
	else 
	{
		printf("Success");
		free(base);
		return (1);
	}
}
