#include <stdio.h>

void	ft_div_mod(int a, int b, int *div, int *mod);

int	main(void)
{
	// int a = 40;
	// int b = 20;

	// int a = 45;
	// int b = 20;

	int a = 40;
	int b = 12;
	int div = -1;
	int mod = -1;

	printf("%d, %d => ", div, mod);

	ft_div_mod(a, b, &div, &mod);

	printf("%d, %d ", div, mod);
}
