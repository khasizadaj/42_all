#include <stdio.h>

void    ft_ultimate_ft(int *********nbr);

int	main(void)
{
	int n = 10;
	int* ptr_1 = &n;
	int** ptr_2 = &ptr_1;
	int*** ptr_3 = &ptr_2;
	int**** ptr_4 = &ptr_3;
	int***** ptr_5 = &ptr_4;
	int****** ptr_6 = &ptr_5;
	int******* ptr_7 = &ptr_6;
	int******** ptr_8 = &ptr_7;
	int********* ptr_9 = &ptr_8;

	printf("%d => ", n);
	ft_ultimate_ft(ptr_9);

	printf("%d", n);
}
