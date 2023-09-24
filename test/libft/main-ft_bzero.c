#include <stdio.h>
#include <strings.h>
#include <stdlib.h>
#include "libft.h"

void ft_bzero(void *s, size_t n);

int	main()
{
	char	*res_1;
	char	*exp_1;
	int		n;
	int		i;

	n = 10;
	i = 0;
	res_1 = malloc(sizeof(char) * n);
	while (i < 10)
	{
		res_1[i] = 'm';
		i++;
	}
	

	i = 0;
	exp_1 = malloc(sizeof(char) * n);
	while (i < 10)
	{
		exp_1[i] = 'c';
		i++;
	}

	ft_bzero(res_1, n);
	bzero(exp_1, n);
	printf("\n>> \tEXP: '%s'\n\tRES: '%s'\n\n", exp_1, res_1);	
	return (0);
}