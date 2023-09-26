#include <stdio.h>
#include <string.h>

int ft_strncmp(char *s1, char *s2, unsigned int n);

int main(void)
{
	char *test_1_s1 = "Hello XXX";
	char *test_1_s2 = "Hello";
	int test_1_result = ft_strncmp(test_1_s1, test_1_s2, 5);
	int test_1_result_expected = strncmp(test_1_s1, test_1_s2, 5);
	printf("Test 1\n");
	printf("W1:\t%s\n", test_1_s1);
	printf("W2:\t%s\n", test_1_s2);
	printf("RES:\t%d\t[EXP: %d]\n", test_1_result, test_1_result_expected);
	if (test_1_result != test_1_result_expected)
	{
		printf("Problem: Expected result does not match the actual result.\n");
	}
	printf("\n");

	char *test_2_s1 = "Hello";
	char *test_2_s2 = "hello";
	int test_2_result = ft_strncmp(test_2_s1, test_2_s2, 5);
	int test_2_result_expected = strncmp(test_2_s1, test_2_s2, 5);
	printf("Test 2\n");
	printf("W1:\t%s\n", test_2_s1);
	printf("W2:\t%s\n", test_2_s2);
	printf("RES:\t%d\t[EXP: %d]\n", test_2_result, test_2_result_expected);
	if (test_2_result != test_2_result_expected)
	{
		printf("Problem: Expected result does not match the actual result.\n");
	}
	printf("\n");

	char *test_3_s1 = "hello";
	char *test_3_s2 = "Hello";
	int test_3_result = ft_strncmp(test_3_s1, test_3_s2, 5);
	int test_3_result_expected = strncmp(test_3_s1, test_3_s2, 5);
	printf("Test 3\n");
	printf("W1:\t%s\n", test_3_s1);
	printf("W2:\t%s\n", test_3_s2);
	printf("RES:\t%d\t[EXP: %d]\n", test_3_result, test_3_result_expected);
	if (test_3_result != test_3_result_expected)
	{
		printf("Problem: Expected result does not match the actual result.\n");
	}
	printf("\n");

	char *test_4_s1 = "helloa";
	char *test_4_s2 = "hello";
	int test_4_result = ft_strncmp(test_4_s1, test_4_s2, 5);
	int test_4_result_expected = strncmp(test_4_s1, test_4_s2, 5);
	printf("Test 4\n");
	printf("W1:\t%s\n", test_4_s1);
	printf("W2:\t%s\n", test_4_s2);
	printf("RES:\t%d\t[EXP: %d]\n", test_4_result, test_4_result_expected);
	if (test_4_result != test_4_result_expected)
	{
		printf("Problem: Expected result does not match the actual result.\n");
	}
	printf("\n");

	char *test_5_s1 = "hello";
	char *test_5_s2 = "Helloa";
	int test_5_result = ft_strncmp(test_5_s1, test_5_s2, 5);
	int test_5_result_expected = strncmp(test_5_s1, test_5_s2, 5);
	printf("Test 5\n");
	printf("W1:\t%s\n", test_5_s1);
	printf("W2:\t%s\n", test_5_s2);
	printf("RES:\t%d\t[EXP: %d]\n", test_5_result, test_5_result_expected);
	if (test_5_result != test_5_result_expected)
	{
		printf("Problem: Expected result does not match the actual result.\n");
	}
	printf("\n");

	// Test Case 1: Empty strings
	char *test_empty_1_s1 = "";
	char *test_empty_1_s2 = "";
	int test_empty_1_result = ft_strncmp(test_empty_1_s1, test_empty_1_s2, 5);
	int test_empty_1_result_expected = strncmp(test_empty_1_s1, test_empty_1_s2, 5);
	printf("Test case 1:\n");
	printf("W1: \"%s\"\n", test_empty_1_s1);
	printf("W2: \"%s\"\n", test_empty_1_s2);
	printf("RES: %d\t[EXP: %d]\n", test_empty_1_result, test_empty_1_result_expected);
	if (test_empty_1_result != test_empty_1_result_expected)
	{
		printf("Problem: Expected result does not match the actual result.\n");
	}
	printf("\n");

	char *test_empty_2_s1 = "";
	char *test_empty_2_s2 = "Hello";
	int test_empty_2_result = ft_strncmp(test_empty_2_s1, test_empty_2_s2, 5);
	int test_empty_2_result_expected = strncmp(test_empty_2_s1, test_empty_2_s2, 5);
	printf("Test case 2:\n");
	printf("W1: \"%s\"\n", test_empty_2_s1);
	printf("W2: \"%s\"\n", test_empty_2_s2);
	printf("RES: %d\t[EXP: %d]\n", test_empty_2_result, test_empty_2_result_expected);
	if (test_empty_2_result != test_empty_2_result_expected)
	{
		printf("Problem: Expected result does not match the actual result.\n");
	}
	printf("\n");

	char *test_empty_3_s1 = "Hello";
	char *test_empty_3_s2 = "";
	int test_empty_3_result = ft_strncmp(test_empty_3_s1, test_empty_3_s2, 5);
	int test_empty_3_result_expected = strncmp(test_empty_3_s1, test_empty_3_s2, 5);
	printf("Test case 3:\n");
	printf("W1: \"%s\"\n", test_empty_3_s1);
	printf("W2: \"%s\"\n", test_empty_3_s2);
	printf("RES: %d\t[EXP: %d]\n", test_empty_3_result, test_empty_3_result_expected);
	if (test_empty_3_result != test_empty_3_result_expected)
	{
		printf("Problem: Expected result does not match the actual result.\n");
	}
	printf("\n");

	// Test Case 4: Strings with whitespace characters
	char *test_whitespace_1_s1 = " Hello ";
	char *test_whitespace_1_s2 = " Hello ";
	int test_whitespace_1_result = ft_strncmp(test_whitespace_1_s1, test_whitespace_1_s2, 5);
	int test_whitespace_1_result_expected = strncmp(test_whitespace_1_s1, test_whitespace_1_s2, 5);
	printf("Test case 4:\n");
	printf("W1: \"%s\"\n", test_whitespace_1_s1);
	printf("W2: \"%s\"\n", test_whitespace_1_s2);
	printf("RES: %d\t[EXP: %d]\n", test_whitespace_1_result, test_whitespace_1_result_expected);
	if (test_whitespace_1_result != test_whitespace_1_result_expected)
	{
		printf("Problem: Expected result does not match the actual result.\n");
	}
	printf("\n");

	char *test_whitespace_2_s1 = "Hello\tWorld";
	char *test_whitespace_2_s2 = "Hello World";
	int test_whitespace_2_result = ft_strncmp(test_whitespace_2_s1, test_whitespace_2_s2, 5);
	int test_whitespace_2_result_expected = strncmp(test_whitespace_2_s1, test_whitespace_2_s2, 5);
	printf("Test case 5:\n");
	printf("W1: \"%s\"\n", test_whitespace_2_s1);
	printf("W2: \"%s\"\n", test_whitespace_2_s2);
	printf("RES: %d\t[EXP: %d]\n", test_whitespace_2_result, test_whitespace_2_result_expected);
	if (test_whitespace_2_result != test_whitespace_2_result_expected)
	{
		printf("Problem: Expected result does not match the actual result.\n");
	}
	printf("\n");
}