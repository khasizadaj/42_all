#include <stdio.h>
#include <string.h>

char *ft_strlowcase(char *str);

int main() {
        // Test Case 1: All uppercase letters
        char str1[] = "HELLO WORLD";
        printf("Original string: \"%s\"\n", str1);
        ft_strlowcase(str1);
        printf("Lowercase string: \"%s\"\n", str1);
        printf("Expected: \"hello world\"\n\n");

        // Test Case 2: All lowercase letters
        char str2[] = "hello world";
        printf("Original string: \"%s\"\n", str2);
        ft_strlowcase(str2);
        printf("Lowercase string: \"%s\"\n", str2);
        printf("Expected: \"hello world\"\n\n");

        // Test Case 3: Mixed case letters
        char str3[] = "Hello World";
        printf("Original string: \"%s\"\n", str3);
        ft_strlowcase(str3);
        printf("Lowercase string: \"%s\"\n", str3);
        printf("Expected: \"hello world\"\n\n");

        // Test Case 4: Empty string
        char str4[] = "";
        printf("Original string: \"%s\"\n", str4);
        ft_strlowcase(str4);
        printf("Lowercase string: \"%s\"\n", str4);
        printf("Expected: \"\"\n\n");

        // Test Case 5: Numeric characters
        char str5[] = "1234";
        printf("Original string: \"%s\"\n", str5);
        ft_strlowcase(str5);
        printf("Lowercase string: \"%s\"\n", str5);
        printf("Expected: \"1234\"\n\n");

        return 0;
}
