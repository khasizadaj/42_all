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
	int		count;

	printf("Test 1: \n");
	char	*s_1 = "Hello Worlds !!!!";
	char	**exp_1;
	char	delimeter_1;

	count = 4;
	exp_1 = malloc(sizeof(char *) * count);
	delimeter_1 = ' ';
	exp_1[0] = "Hello";
	exp_1[1] = "Worlds";
	exp_1[2] = "!!!!";
	exp_1[3] = '\0';

	printf("String: \"%s\"\n", s_1);

	char **res_1 = ft_split(s_1, delimeter_1);
	for (int i = 0; i < count - 1; i++)
	{
		printf("Word %d\n", i);
		if (ft_strncmp(exp_1[i], res_1[i], sizeof(exp_1[0])) == 0)
			printf("All good!\n\n");
		else
			printf("Not good || \n\tEXP: '%s'; \n\tRES: '%s'\n\n", exp_1[i], res_1[i]);	
	}

	printf("Test 5: \n");
	char	*s_5 = "Hello World Welcome";
	char	**exp_5;
	char	delimeter_5;

	count = 4;
	exp_5 = malloc(sizeof(char *) * count);
	delimeter_5 = ' ';
	exp_5[0] = "Hello";
	exp_5[1] = "World";
	exp_5[2] = "Welcome";
	exp_5[3] = '\0';

	printf("String: \"%s\"\n", s_5);

	char **res_5 = ft_split(s_5, delimeter_5);
	for (int i = 0; i < count - 1; i++)
	{
		printf("Word %d\n", i);
		if (ft_strncmp(exp_5[i], res_5[i], sizeof(exp_5[0])) == 0)
			printf("All good!\n\n");
		else
			printf("Not good || \n\tEXP: '%s'; \n\tRES: '%s'\n\n", exp_5[i], res_5[i]);	
	}


	// printf("Test 3: Empty string\n");
	// char	*s_3 = "";
	// char	**exp_3;
	// char	delimeter_3;

	// count = 2;
	// exp_3 = malloc(sizeof(char *) * count);
	// delimeter_3 = ' ';
	// exp_3[0] = "";
	// exp_3[1] = '\0';

	// printf("String: \"%s\"\n", s_3);

	// char **res_3 = ft_split(s_3, delimeter_3);
	// for (int i = 0; i < count - 1; i++)
	// {
	// 	printf("Word %d\n", i);
	// 	if (ft_strncmp(exp_3[i], res_3[i], sizeof(exp_3[0])) == 0)
	// 		printf("All good!\n\n");
	// 	else
	// 		printf("Not good || \n\tEXP: '%s'; \n\tRES: '%s'\n\n", exp_3[i], res_3[i]);	
	// }

	// printf("Test 4: Empty string\n");
	// char	*s_4 = " Hello World ";
	// char	**exp_4;
	// char	delimeter_4;

	// count = 3;
	// exp_4 = malloc(sizeof(char *) * count);
	// delimeter_4 = ' ';
	// exp_4[0] = "Hello";
	// exp_4[1] = "World";
	// exp_4[2] = '\0';

	// printf("String: \"%s\"\n", s_4);

	// char **res_4 = ft_split(s_4, delimeter_4);
	// for (int i = 0; i < count - 1; i++)
	// {
	// 	printf("Word %d\n", i);
	// 	if (ft_strncmp(exp_4[i], res_4[i], sizeof(exp_4[0])) == 0)
	// 		printf("All good!\n\n");
	// 	else
	// 		printf("Not good || \n\tEXP: '%s'; \n\tRES: '%s'\n\n", exp_4[i], res_4[i]);	
	// }
}
