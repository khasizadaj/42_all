/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 15:37:01 by codespace         #+#    #+#             */
/*   Updated: 2023/09/15 16:15:35 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int main()
{
	char	**exp_1;
	char	**res_1;
	size_t	i;
	size_t	j;
	size_t	n;

	n = 5;
	i = 0;
	j = 0;
	exp_1 = calloc(n, sizeof(char *));
	for (i = 0; i < n; i++)
	{
		exp_1[i] = calloc(n, sizeof(char));
		for (j = 0; j < n; j++)
		{
			exp_1[i][j] = 'c';
		}
	}

	i = 0;
	j = 0;
	res_1 = ft_calloc(n, sizeof(char *));
	for (i = 0; i < n; i++)
	{
		res_1[i] = ft_calloc(n, sizeof(char));
		for (j = 0; j < n; j++)
		{
			res_1[i][j] = 'c';
		}
	}

	// Print the contents of exp_1
	printf("exp_1:\n");
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("%c ", exp_1[i][j]);
		}
		printf("\n");
	}

	// Print the contents of res_1
	printf("\nres_1:\n");
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("%c ", res_1[i][j]);
		}
		printf("\n");
	}
}
