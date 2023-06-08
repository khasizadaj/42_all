#include <stdio.h>
#include <string.h>

char	*ft_strstr(char *str, char *to_find);

int main()
{
	// Test Case 1: Needle is an empty string
	char *test_1_haystack = "Hello World";
	char *test_1_needle = "";
	char *test_1_result = ft_strstr(test_1_haystack, test_1_needle);
	char *test_1_result_expected = strstr(test_1_haystack, test_1_needle);
	printf("Test Case 1:\n");
	printf("Haystack:\t\"%s\"\n", test_1_haystack);
	printf("Needle:\t\t\"%s\"\n", test_1_needle);
	printf("RES:\t\t\"%s\"\t[EXP: \"%s\"]\n", test_1_result, test_1_result_expected);
	if (test_1_result != test_1_result_expected)
	{
		printf("Problem: Expected result does not match the actual result.\n");
	}
	printf("\n");

	// Test Case 2: Needle is not found in the haystack
	char *test_2_haystack = "Hello World";
	char *test_2_needle = "foo";
	char *test_2_result = ft_strstr(test_2_haystack, test_2_needle);
	char *test_2_result_expected = strstr(test_2_haystack, test_2_needle);
	printf("Test Case 2:\n");
	printf("Haystack:\t\"%s\"\n", test_2_haystack);
	printf("Needle:\t\t\"%s\"\n", test_2_needle);
	printf("RES:\t\t\"%s\"\t[EXP: \"%s\"]\n", test_2_result, test_2_result_expected);
	if (test_2_result != test_2_result_expected)
	{
		printf("Problem: Expected result does not match the actual result.\n");
	}
	printf("\n");

	// Test Case 3: Needle is found at the beginning of the haystack
	char *test_3_haystack = "Hello World";
	char *test_3_needle = "Hello";
	char *test_3_result = ft_strstr(test_3_haystack, test_3_needle);
	char *test_3_result_expected = strstr(test_3_haystack, test_3_needle);
	printf("Test Case 3:\n");
	printf("Haystack:\t\"%s\"\n", test_3_haystack);
	printf("Needle:\t\t\"%s\"\n", test_3_needle);
	printf("RES:\t\t\"%s\"\t[EXP: \"%s\"]\n", test_3_result, test_3_result_expected);
	if (test_3_result != test_3_result_expected)
	{
		printf("Problem: Expected result does not match the actual result.\n");
	}
	printf("\n");

	// Test Case 4: Needle is found in the middle of the haystack
	char *test_4_haystack = "Hello Worl World";
	char *test_4_needle = "World";
	char *test_4_result = ft_strstr(test_4_haystack, test_4_needle);
	char *test_4_result_expected = strstr(test_4_haystack, test_4_needle);
	printf("Test Case 4:\n");
	printf("Haystack:\t\"%s\"\n", test_4_haystack);
	printf("Needle:\t\t\"%s\"\n", test_4_needle);
	printf("RES:\t\t\"%s\"\t[EXP: \"%s\"]\n", test_4_result, test_4_result_expected);
	if (test_4_result != test_4_result_expected)
	{
		printf("Problem: Expected result does not match the actual result.\n");
	}
	printf("\n");

	// Test Case 5: Needle is found at the end of the haystack
	char *test_5_haystack = "Hello World";
	char *test_5_needle = "World";
	char *test_5_result = ft_strstr(test_5_haystack, test_5_needle);
	char *test_5_result_expected = strstr(test_5_haystack, test_5_needle);
	printf("Test Case 5:\n");
	printf("Haystack:\t\"%s\"\n", test_5_haystack);
	printf("Needle:\t\t\"%s\"\n", test_5_needle);
	printf("RES:\t\t\"%s\"\t[EXP: \"%s\"]\n", test_5_result, test_5_result_expected);
	if (test_5_result != test_5_result_expected)
	{
		printf("Problem: Expected result does not match the actual result.\n");
	}
	printf("\n");

	return 0;
}
