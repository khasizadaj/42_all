/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 15:45:53 by jkhasiza          #+#    #+#             */
/*   Updated: 2023/06/12 15:56:24 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>

int ft_atoi(const char* str);

int main() {
    // Test Case 1: Basic conversion with no leading whitespace or signs
    const char* str1 = "123";
    int result1 = ft_atoi(str1);
    printf("Result 1: %d\n, [123]", result1);  // Expected output: Result 1: 123

    // Test Case 2: Leading whitespace and signs
    const char* str2 = "   -+456";
    int result2 = ft_atoi(str2);
    printf("Result 2: %d [-456]\n", result2);

    // Test Case 3: Leading whitespace and signs with multiple '-' and '+' signs
    const char* str3 = "   ----+++--789";
    int result3 = ft_atoi(str3);
    printf("Result 3: %d [789]\n", result3);

    // Test Case 4: String with invalid characters at the end
    const char* str4 = "   123abc";
    int result4 = ft_atoi(str4);
    printf("Result 4: %d [123]\n", result4);

    // Test Case 7: String with invalid characters at the beginning
    const char* str7 = "    \t\t----vb1234";
    int result7 = ft_atoi(str7);
    printf("Result 7: %d [0]\n", result7);

    return 0;
}