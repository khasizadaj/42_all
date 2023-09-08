/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 21:45:26 by jkhasiza          #+#    #+#             */
/*   Updated: 2023/09/05 00:59:31 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	**ft_split(char const *s, char c);

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	if (i < n)
		return (s1[i] - s2[i]);
	return (0);
}

int	main(int argc, char *argv)
{
	printf("Test 1: \n");
	char	*s_1 = "Hello World !!!!\n";
	char	**exp_1;
	char	delimeter_1;
	int		count;

	exp_1 = malloc(sizeof(char *) * 3);
	delimeter_1 = ' ';
	exp_1[0] = "Hello";
	exp_1[1] = "World";
	exp_1[2] = "!!!!\n";
	count = 3;

	char **res_1 = ft_split(s_1, delimeter_1);
	for (int i = 0; i < count; i++)
	{
		printf("Word %d\n", i);
		if (ft_strncmp(exp_1[i], res_1[i], sizeof(exp_1[0])) == 0)
			printf("All good!\n\n");
		else
			printf("Not good || \n\tEXP: '%s'; \n\tRES: '%s'\n\n", exp_1[i], res_1[i]);	
	}

	printf("Test 2: \n");
	char	*s_2 = "Hello World\n";
	char	**exp_2;
	char	delimeter_2;

	exp_2 = malloc(sizeof(char *) * 3);
	delimeter_2 = ' ';
	exp_2[0] = "Hello";
	exp_2[1] = "World";
	count = 2;

	char **res_2 = ft_split(s_2, delimeter_2);
	for (int i = 0; i < count; i++)
	{
		printf("Word %d\n", i);
		if (ft_strncmp(exp_2[i], res_2[i], sizeof(exp_2[0])) == 0)
			printf("All good!\n\n");
		else
			printf("Not good || \n\tEXP: '%s'; \n\tRES: '%s'\n\n", exp_2[i], res_2[i]);	
	}
}
