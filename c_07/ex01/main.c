/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 13:07:34 by jkhasiza          #+#    #+#             */
/*   Updated: 2023/06/15 13:17:07 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	*ft_range(int min, int max);

int	main(void)
{
	int	min = 2;
	int	max = 4;

	int *arr = ft_range(min, max);
	for (int i = 0; i < max - min; i++)
	{
		printf("i: %d\n", arr[i]);
	}
	printf("----\n");

	min = 4;
	max = 2;

	arr = ft_range(min, max);
	if (arr == NULL)
		printf("is null\n");
	printf("----\n");

	min = 2;
	max = 2;

	arr = ft_range(min, max);
	if (arr == NULL)
		printf("is null\n");
	printf("----\n");

	return (0);
}