#include <stdio.h>

void    ft_swap(int *a, int *b);

int	main(void)
{
	int a = 10;
	int b = 12;
	printf("%d, %d => ", a, b);

	ft_swap(&a, &b);

	printf("%d, %d ", a, b);
}
