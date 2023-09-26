#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void	*ft_memset(void *s, int c, size_t n);

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

int	main()
{
	char	*res_1;
	char	*exp_1;
	int		n;
	int		i;
	int		c;

	n = 10;
	i = 0;
	res_1 = malloc(sizeof(char) * n);

	i = 0;
	exp_1 = malloc(sizeof(char) * n);

	c = 'Z';
	ft_memset(res_1, c, n);
	memset(exp_1, c, n);
	printf("\n>> \tEXP: '%s'\n\tRES: '%s'\n\n", exp_1, res_1);	

	c = 'm';
	ft_memset(res_1, c, n);
	memset(exp_1, c, n);
	printf("\n>> \tEXP: '%s'\n\tRES: '%s'\n\n", exp_1, res_1);	
	return (0);
}