/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 17:57:46 by jkhasiza          #+#    #+#             */
/*   Updated: 2023/05/31 20:22:02 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int     ft_str_is_numeric(char *str);

int main()
{
    char str1[] = "12345";
    int result1 = ft_str_is_numeric(str1);
    printf("Test case 1: \"%s\" -> %d [EXP: 1]\n", str1, result1); // Expected output: 1

    char str2[] = "123abc";
    int result2 = ft_str_is_numeric(str2);
    printf("Test case 2: \"%s\" -> %d [EXP: 0]\n", str2, result2); // Expected output: 0

    char str3[] = "";
    int result3 = ft_str_is_numeric(str3);
    printf("Test case 3: \"%s\" -> %d [EXP: 1]\n", str3, result3); // Expected output: 1

    char str4[] = "0";
    int result4 = ft_str_is_numeric(str4);
    printf("Test case 4: \"%s\" -> %d [EXP: 1]\n", str4, result4); // Expected output: 1

    char str5[] = "abc";
    int result5 = ft_str_is_numeric(str5);
    printf("Test case 5: \"%s\" -> %d [EXP: 0]\n", str5, result5); // Expected output: 0

    char str6[] = "123 456";
    int result6 = ft_str_is_numeric(str6);
    printf("Test case 6: \"%s\" -> %d [EXP: 0]\n", str6, result6); // Expected output: 0

    return 0;
}
