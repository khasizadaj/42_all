#include <stdio.h>
#include <string.h>

char *ft_strupcase(char *str);

int main() {
	// Test Case 1: All lowercase letters
	char str1[] = "hello world";
	printf("Original string: %s\n", str1);
	ft_strupcase(str1);
	printf("Uppercase string: %s\n\n", str1);

	// Test Case 2: All uppercase letters
	char str2[] = "HELLO WORLD";
	printf("Original string: %s\n", str2);
	ft_strupcase(str2);
	printf("Uppercase string: %s\n\n", str2);

	// Test Case 3: Mixed case letters
	char str3[] = "Hello World";
	printf("Original string: %s\n", str3);
	ft_strupcase(str3);
	printf("Uppercase string: %s\n\n", str3);

	// Test Case 4: Empty string
	char str4[] = "";
	printf("Original string: %s\n", str4);
	ft_strupcase(str4);
	printf("Uppercase string: %s\n\n", str4);

	// Test Case 5: Numeric characters
	char str5[] = "1234";
	printf("Original string: %s\n", str5);
	ft_strupcase(str5);
	printf("Uppercase string: %s\n\n", str5);

	return 0;
}
