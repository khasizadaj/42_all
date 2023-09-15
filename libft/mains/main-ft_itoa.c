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

char	*ft_itoa(int n);

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

int	main(int argc, char *argv)
{
	int	num;
	char	*str;
	char	*converted;
	int	cmp;

	num = 200;
	str = "200";

	converted = ft_itoa(num);
	cmp = ft_strcmp(str, converted);
	if (cmp != 0)
		printf("\"%s\" is not equal to \"%s\".\n", converted, str);
	else
		printf("All good for '%d'!\n", num);

	num = -200;
        str = "-200";

        converted = ft_itoa(num);
        cmp = ft_strcmp(str, converted);
        if (cmp != 0)
                printf("\"%s\" is not equal to \"%s\".\n", converted, str);
	else
		printf("All good for '%d'!\n", num);

	num = 0;
        str = "0";

        converted = ft_itoa(num);
        cmp = ft_strcmp(str, converted);
        if (cmp != 0)
                printf("\"%s\" is not equal to \"%s\".\n", converted, str);
	else
		printf("All good for '%d'!\n", num);

	num = 2147483647;
        str = "2147483647";

        converted = ft_itoa(num);
        cmp = ft_strcmp(str, converted);
        if (cmp != 0)
                printf("\"%s\" is not equal to \"%s\".\n", converted, str);
	else
		printf("All good for '%d'!\n", num);

	num = -2147483648;
        str = "-2147483648";

        converted = ft_itoa(num);
        cmp = ft_strcmp(str, converted);
        if (cmp != 0)
                printf("\"%s\" is not equal to \"%s\".\n", converted, str);
	else
		printf("All good for '%d'!\n", num);
}
