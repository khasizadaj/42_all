#include <stdio.h>

void    ft_ft(int *nbr);

int	main(void)
{
	int n = 10;

	printf("%d => ", n);
	ft_ft(&n);

	printf("%d", n);
}
