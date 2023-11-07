#include <stdio.h>
#include <string.h>

size_t ft_strlcat(char *dest, const char *src, size_t size);

int main()
{
	// Test Case 1: Empty destination string
	char test_1_dest[100] = "";
	char *test_1_src = "Hello";
	size_t test_1_size = 10;
	printf("Orig Dest:\t\"%s\"\n", test_1_dest);
	size_t test_1_result = ft_strlcat(test_1_dest, test_1_src, test_1_size);
	printf("Test Case 1:\n");
	printf("Dest:\t\t\"%s\"\n", test_1_dest);
	printf("Src:\t\t\"%s\"\n", test_1_src);
	printf("Size:\t\t%zu\n", test_1_size);
	printf("RES:\t\t%zu\n", test_1_result);
	printf("\n");

	// Test Case 2: Destination string is larger than the size
	char test_2_dest[100] = "Hello";
	char *test_2_src = " World";
	size_t test_2_size = 5;
	printf("Orig Dest:\t\"%s\"\n", test_2_dest);
	size_t test_2_result = ft_strlcat(test_2_dest, test_2_src, test_2_size);
	printf("Test Case 2:\n");
	printf("Dest:\t\t\"%s\"\n", test_2_dest);
	printf("Src:\t\t\"%s\"\n", test_2_src);
	printf("Size:\t\t%zu\n", test_2_size);
	printf("RES:\t\t%zu\n", test_2_result);
	printf("\n");

	// Test Case 3: Destination string exactly fits the size
	char test_3_dest[100] = "Hello";
	char *test_3_src = " World";
	size_t test_3_size = 11;
	printf("Orig Dest:\t\"%s\"\n", test_3_dest);

	size_t test_3_result = ft_strlcat(test_3_dest, test_3_src, test_3_size);
	printf("Test Case 3:\n");
	printf("Dest:\t\t\"%s\"\n", test_3_dest);
	printf("Src:\t\t\"%s\"\n", test_3_src);
	printf("Size:\t\t%zu\n", test_3_size);
	printf("RES:\t\t%zu\n", test_3_result);
	printf("\n");

	// Test Case 4: Destination string is smaller than the size
	char test_4_dest[100] = "Hello";
	char *test_4_src = " World";
	size_t test_4_size = 2;
	printf("Orig Dest:\t\"%s\"\n", test_4_dest);
	size_t test_4_result = ft_strlcat(test_4_dest, test_4_src, test_4_size);
	printf("Test Case 4:\n");
	printf("Dest:\t\t\"%s\"\n", test_4_dest);
	printf("Src:\t\t\"%s\"\n", test_4_src);
	printf("Size:\t\t%zu\n", test_4_size);
	printf("RES:\t\t%zu\n", test_4_result);
	printf("\n");

	return 0;
}
