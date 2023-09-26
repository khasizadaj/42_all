#include <stdio.h>

void	ft_ultimate_div_mod(int *a, int *b);

int	main(void)
{
	int a = 40;
	int b = 12;
	
	printf("TEST 1\n=====\n");
	printf("{a=%d, b=%d}\n", a, b);
	printf("\tEXP:\ta=3, b=4\n");
	
	ft_ultimate_div_mod(&a, &b);

	printf("\tACT:\ta=%d, b=%d\n", a, b);
	
	a = 35;
	b = 12;

	printf("\nTEST 2\n=====\n");
	printf("\n{a=%d, b=%d}\n", a, b);
	printf("\tEXP:\ta=2, b=11\n");
	
	ft_ultimate_div_mod(&a, &b);

	printf("\tACT:\ta=%d, b=%d\n", a, b);
}
