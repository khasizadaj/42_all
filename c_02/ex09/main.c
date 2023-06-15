#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *ft_strcapitalize_v2(char *str);

int main() {
    char str1[] = "hello wORld hey-there";
    char expected1[] = "Hello World Hey-There";

    printf("Test case 1:\n");
    printf("Original string: %s\n", str1);
    ft_strcapitalize_v2(str1);
    printf("Expected: %s\n", expected1);
    printf("Actual: %s\n", str1);
    printf("Result: %s\n\n", strcmp(str1, expected1) == 0 ? "PASS" : "FAIL");

    char str2[] = "HELLO WORLD";
    char expected2[] = "Hello World";

    printf("Test case 2:\n");
    printf("Original string: %s\n", str2);
    ft_strcapitalize_v2(str2);
    printf("Expected: %s\n", expected2);
    printf("Actual: %s\n", str2);
    printf("Result: %s\n\n", strcmp(str2, expected2) == 0 ? "PASS" : "FAIL");

    char str3[] = "123abc 456def ? ?abh+xxx-yU";
    char expected3[] = "123abc 456def ? ?Abh+Xxx-Yu";

    printf("Test case 3:\n");
    printf("Original string: %s\n", str3);
    ft_strcapitalize_v2(str3);
    printf("Expected: %s\n", expected3);
    printf("Actual: %s\n", str3);
    printf("Result: %s\n\n", strcmp(str3, expected3) == 0 ? "PASS" : "FAIL");

    return 0;
}
