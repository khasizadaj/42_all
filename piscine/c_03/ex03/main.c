#include <stdio.h>
#include <string.h>

char *ft_strncat(char *dest, const char *src, unsigned int nb);

int main() {
    // Test Case 1: Concatenate two empty strings
    char test_1_dest[10] = "";
    char *test_1_src = "";
    size_t test_1_n = 5;
    char *test_1_result = ft_strncat(test_1_dest, test_1_src, test_1_n);
    char *test_1_result_expected = strncat(test_1_dest, test_1_src, test_1_n);
    printf("Test Case 1:\n");
    printf("Dest:\t\"%s\"\n", test_1_dest);
    printf("Src:\t\"%s\"\n", test_1_src);
    printf("N:\t%zu\n", test_1_n);
    printf("RES:\t\"%s\"\t[EXP: \"%s\"]\n", test_1_result, test_1_result_expected);
    if (strcmp(test_1_result, test_1_result_expected) != 0) {
        printf("Problem: Expected result does not match the actual result.\n");
    }
    printf("\n");
    
    // Test Case 2: Concatenate empty string with non-empty string
    char test_2_dest[10] = "";
    char *test_2_src = "World";
    size_t test_2_n = 3;
    char *test_2_result = ft_strncat(test_2_dest, test_2_src, test_2_n);
    char *test_2_result_expected = strncat(test_2_dest, test_2_src, test_2_n);
    printf("Test Case 2:\n");
    printf("Dest:\t\"%s\"\n", test_2_dest);
    printf("Src:\t\"%s\"\n", test_2_src);
    printf("N:\t%zu\n", test_2_n);
    printf("RES:\t\"%s\"\t[EXP: \"%s\"]\n", test_2_result, test_2_result_expected);
    if (strcmp(test_2_result, test_2_result_expected) != 0) {
        printf("Problem: Expected result does not match the actual result.\n");
    }
    printf("\n");

    // Test Case 3: Concatenate non-empty string with empty string
    char test_3_dest[10] = "Hello";
    char *test_3_src = "";
    size_t test_3_n = 2;
    char *test_3_result = ft_strncat(test_3_dest, test_3_src, test_3_n);
    char *test_3_result_expected = strncat(test_3_dest, test_3_src, test_3_n);
    printf("Test Case 3:\n");
    printf("Dest:\t\"%s\"\n", test_3_dest);
    printf("Src:\t\"%s\"\n", test_3_src);
    printf("N:\t%zu\n", test_3_n);
    printf("RES:\t\"%s\"\t[EXP: \"%s\"]\n", test_3_result, test_3_result_expected);
    if (strcmp(test_3_result, test_3_result_expected) != 0) {
        printf("Problem: Expected result does not match the actual result.\n");
    }
    printf("\n");

    // Test Case 4: Concatenate non-empty string with non-empty string
    char test_4_dest[20] = "Hello";
    char *test_4_src = "World";
    size_t test_4_n = 4;
    char *test_4_result = ft_strncat(test_4_dest, test_4_src, test_4_n);
    char *test_4_result_expected = strncat(test_4_dest, test_4_src, test_4_n);
    printf("Test Case 4:\n");
    printf("Dest:\t\"%s\"\n", test_4_dest);
    printf("Src:\t\"%s\"\n", test_4_src);
    printf("N:\t%zu\n", test_4_n);
    printf("RES:\t\"%s\"\t[EXP: \"%s\"]\n", test_4_result, test_4_result_expected);
    if (strcmp(test_4_result, test_4_result_expected) != 0) {
        printf("Problem: Expected result does not match the actual result.\n");
    }
    printf("\n");

    return 0;
}
