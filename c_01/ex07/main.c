#include <stdio.h>
#include <unistd.h>

void	ft_rev_int_tab(int *tab, int size);

int	main(void)
{
	int tab[] = {1, 2, 3};
	int size = 3;

	ft_rev_int_tab(tab, size);
	
	int i;
	for (i = 0; i < size; i++) {
		printf("ACT:\t%d\n", tab[i]);
	}

	printf("\n");

	int tab_2[] = {1, 2, 3, 4};
	size = 4;

	ft_rev_int_tab(tab_2, size);
	
	for (i = 0; i < size; i++) {
		printf("ACT:\t%d\n", tab_2[i]);
	}

	printf("\n");

	int tab_3[] = {1, 4, 4, 1, 5};
	size = 5;

	ft_rev_int_tab(tab_3, size);
	
	for (i = 0; i < size; i++) {
		printf("ACT:\t%d\n", tab_3[i]);
	}

	printf("\n");
	
	int tab_4[] = {-5};
	size = 1;

	ft_rev_int_tab(tab_4, size);
	
	for (i = 0; i < size; i++) {
		printf("ACT:\t%d\n", tab_4[i]);
	}

	printf("\n");

	// // Test 1: Tab is NULL
	// int *null_tab = NULL;
	// int null_size = 5;
	
	// ft_rev_int_tab(null_tab, null_size);
	
	// // In this case, we expect a segmentation fault because the pointer is NULL
	
	// printf("\n");

	// Test 6: Size is greater than the actual size of the array
	int tab_6[] = {1, 2, 3};
	size = 5;
	
	ft_rev_int_tab(tab_6, size);
	
	for (i = 0; i < size; i++) {
		printf("ACT:\t%d\n", tab_6[i]);
	}
	// In this case, we expect a segmentation fault because we're accessing memory outside the array

	printf("\n");

	// Test 7: Size is negative
	int tab_neg[] = {1, 2, 3};
	int neg_size = -3;
	
	ft_rev_int_tab(tab_neg, neg_size);
	
	for (i = 0; i < neg_size; i++) {
		printf("ACT:\t%d\n", tab_neg[i]);
	}
	// In this case, we also expect a segmentation fault because we're using a negative size

	printf("\n");

	// Test 7: Size is negative
	int tab_7[] = {1, 2};
	size = 1;
	
	ft_rev_int_tab(tab_7, size);

	printf("\n");
}
