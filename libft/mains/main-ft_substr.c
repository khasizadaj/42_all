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

char	*ft_substr(char const *s, unsigned int start, size_t len);

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
	int		start;
	int		len;

	printf("Test 1: Just enough length\n");
	char	s_1[10];
	char	sub_1[10];
	start = 0;
	len = 10;
	strncpy(s_1, "Gulnara123", sizeof(s_1));
	s_1[sizeof(s_1) - 1] = '\0';
	strncpy(sub_1, "Gulnara123", sizeof(sub_1));
	sub_1[sizeof(sub_1) - 1] = '\0';

	char *res_1 = ft_substr(s_1, start, len);
	if (ft_strncmp(sub_1, res_1, len) == 0)
		printf("All good!\n");
	else
		printf("Not good || sub_1: '%s'; res_1: '%s'\n", sub_1, res_1);

	printf("Test 2: Shorter length\n");
	char	s_2[10];
	char	sub_2[4];
	start = 1;
	len = 3;
	strncpy(s_2, "Gulnara123", sizeof(s_2));
	s_2[sizeof(s_2) - 1] = '\0';
	strncpy(sub_2, "uln", sizeof(sub_2));
	sub_2[sizeof(sub_2) - 1] = '\0';

	char *res_2 = ft_substr(s_2, start, len);
	if (ft_strncmp(sub_2, res_2, len) == 0)
		printf("All good!\n");
	else
		printf("Not good || sub_2: '%s'; res_2: '%s'\n", sub_2, res_2);


	printf("Test 3: Longer length\n");
	char	s_3[10];
	char	sub_3[10];
	start = 0;
	len = 15;
	strncpy(s_3, "Gulnara123", sizeof(s_3));
	s_3[sizeof(s_3) - 1] = '\0';
	strncpy(sub_3, "Gulnara123", sizeof(sub_3));
	sub_3[sizeof(sub_3) - 1] = '\0';

	char *res_3 = ft_substr(s_3, start, len);
	if (ft_strncmp(sub_3, res_3, len) == 0)
		printf("All good!\n");
	else
		printf("Not good || sub_3: '%s'; res_3: '%s'\n", sub_3, res_3);
}
