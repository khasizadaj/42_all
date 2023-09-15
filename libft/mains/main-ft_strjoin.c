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

char	*ft_strjoin(char const *s1, char const *s2);

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
	char	s_1_1[5];
	char	s_1_2[5];
	char	*exp_1;

	exp_1 = "ajaxxaja";
	strncpy(s_1_1, "ajax", sizeof(s_1_1));
	s_1_1[sizeof(s_1_1) - 1] = '\0';
	strncpy(s_1_2, "xaja", sizeof(s_1_2));
	s_1_2[sizeof(s_1_2) - 1] = '\0';

	char *res_1 = ft_strjoin(s_1_1, s_1_2);
	if (ft_strncmp(exp_1, res_1, sizeof(s_1_1) + sizeof(s_1_2)) == 0)
		printf("All good!\n\n");
	else
		printf("Not good || \n\tEXP: '%s'; \n\tRES: '%s'\n\n", exp_1, res_1);

	printf("Test 2: \n");
	char	s_2_1[5];
	char	s_2_2[11];
	char	*exp_2;

	exp_2 = "ajaxGulnara123";
	strncpy(s_2_1, "ajax", sizeof(s_2_1));
	s_2_1[sizeof(s_2_1) - 1] = '\0';
	strncpy(s_2_2, "Gulnara123", sizeof(s_2_2));
	s_2_2[sizeof(s_2_2) - 1] = '\0';

	char *res_2 = ft_strjoin(s_2_1, s_2_2);
	if (ft_strncmp(exp_2, res_2, sizeof(s_2_1) + sizeof(s_2_2)) == 0)
		printf("All good!\n\n");
	else
		printf("Not good || \n\tEXP: '%s'; \n\tRES: '%s'\n\n", exp_2, res_2);


	printf("Test 3: \n");
	char	s_3_1[5];
	char	s_3_2[1];
	char	*exp_3;

	exp_3 = "ajax";
	strncpy(s_3_1, "ajax", sizeof(s_3_1));
	s_3_1[sizeof(s_3_1) - 1] = '\0';
	strncpy(s_3_2, "", sizeof(s_3_2));
	s_3_2[sizeof(s_3_2) - 1] = '\0';

	char *res_3 = ft_strjoin(s_3_1, s_3_2);
	if (ft_strncmp(exp_3, res_3, sizeof(s_3_1) + sizeof(s_3_2)) == 0)
		printf("All good!\n\n");
	else
		printf("Not good || \n\tEXP: '%s'; \n\tRES: '%s'\n\n", exp_3, res_3);

	printf("Test 4: \n");
	char	s_4_1[1];
	char	s_4_2[1];
	char	*exp_4;

	exp_4 = "";
	strncpy(s_4_1, "", sizeof(s_4_1));
	s_4_1[sizeof(s_4_1) - 1] = '\0';
	strncpy(s_4_2, "", sizeof(s_4_2));
	s_4_2[sizeof(s_4_2) - 1] = '\0';

	char *res_4 = ft_strjoin(s_4_1, s_4_2);
	if (ft_strncmp(exp_4, res_4, sizeof(s_4_1) + sizeof(s_4_2)) == 0)
		printf("All good!\n\n");
	else
		printf("Not good || \n\tEXP: '%s'; \n\tRES: '%s'\n\n", exp_4, res_4);
}
