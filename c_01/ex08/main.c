#include <stdio.h>
#include <unistd.h>

void ft_sort_int_tab(int *tab, int size);

// TODO Learn how to work with arrays

int	main(void)
{
	int tab[] = {2, 3, 1, 5};
	int size = 4;

	ft_sort_int_tab(tab, size);
	
	int i;
	for (i = 0; i < size; i++) {
		printf("ACT:\t%d\n", tab[i]);
	}

	// printf("\n");

	// int tab_2[] = {1, 4, 3, 2};
	// size = 4;

	// ft_sort_int_tab(tab_2, size);
	
	// for (i = 0; i < size; i++) {
	// 	printf("ACT:\t%d\n", tab_2[i]);
	// }

	// printf("\n");
}
