#include <stdio.h>
#include <string.h>

char *ft_strcat(char *dest, char *src);

int main() {
    // Test Case 1: Concatenate two empty strings
    char test_1_dest[10] = "";
    char *test_1_src = "";
    char *test_1_result = ft_strcat(test_1_dest, test_1_src);
    char *test_1_result_expected = strcat(test_1_dest, test_1_src);
    printf("Test Case 1:\n");
    printf("Dest:\t\"%s\"\n", test_1_dest);
    printf("Src:\t\"%s\"\n", test_1_src);
    printf("RES:\t\"%s\"\t[EXP: \"%s\"]\n", test_1_result, test_1_result_expected);
    if (strcmp(test_1_result, test_1_result_expected) != 0) {
        printf("Problem: Expected result does not match the actual result.\n");
    }
    printf("\n");

    // Test Case 2: Concatenate empty string with non-empty string
    char test_2_dest[10] = "";
    char *test_2_src = "World";
    char *test_2_result = ft_strcat(test_2_dest, test_2_src);
    char *test_2_result_expected = strcat(test_2_dest, test_2_src);
    printf("Test Case 2:\n");
    printf("Dest:\t\"%s\"\n", test_2_dest);
    printf("Src:\t\"%s\"\n", test_2_src);
    printf("RES:\t\"%s\"\t[EXP: \"%s\"]\n", test_2_result, test_2_result_expected);
    if (strcmp(test_2_result, test_2_result_expected) != 0) {
        printf("Problem: Expected result does not match the actual result.\n");
    }
    printf("\n");

    // Test Case 3: Concatenate non-empty string with empty string
    char test_3_dest[10] = "Hello";
    char *test_3_src = "";
    char *test_3_result = ft_strcat(test_3_dest, test_3_src);
    char *test_3_result_expected = strcat(test_3_dest, test_3_src);
    printf("Test Case 3:\n");
    printf("Dest:\t\"%s\"\n", test_3_dest);
    printf("Src:\t\"%s\"\n", test_3_src);
    printf("RES:\t\"%s\"\t[EXP: \"%s\"]\n", test_3_result, test_3_result_expected);
    if (strcmp(test_3_result, test_3_result_expected) != 0) {
        printf("Problem: Expected result does not match the actual result.\n");
    }
    printf("\n");

    // Test Case 4: Concatenate two non-empty strings
    char test_4_dest[20] = "Hello";
    char *test_4_src = "World";
    char *test_4_result = ft_strcat(test_4_dest, test_4_src);
    char *test_4_result_expected = strcat(test_4_dest, test_4_src);
    printf("Test Case 4:\n");
    printf("Dest:\t\"%s\"\n", test_4_dest);
    printf("Src:\t\"%s\"\n", test_4_src);
    printf("RES:\t\"%s\"\t[EXP: \"%s\"]\n", test_4_result, test_4_result_expected);
    if (strcmp(test_4_result, test_4_result_expected) != 0) {
        printf("Problem: Expected result does not match the actual result.\n");
    }
    printf("\n");

    return 0;
}
