/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 17:57:46 by jkhasiza          #+#    #+#             */
/*   Updated: 2023/05/31 20:01:56 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_alpha(char *str);

int     main(void)
{
	char str1[] = "HelloWorld";
	int result1 = ft_str_is_alpha(str1);
	printf("Test case 1: \"%s\" -> %d [EXP: 1]\n", str1, result1); // Expected output: 1

	char str2[] = "Hello123";
	int result2 = ft_str_is_alpha(str2);
	printf("Test case 2: \"%s\" -> %d [EXP: 0]\n", str2, result2); // Expected output: 0

	char str3[] = "";
	int result3 = ft_str_is_alpha(str3);
	printf("Test case 3: \"%s\" -> %d [EXP: 1]\n", str3, result3); // Expected output: 1

	char str4[] = "A";
	int result4 = ft_str_is_alpha(str4);
	printf("Test case 4: \"%s\" -> %d [EXP: 1]\n", str4, result4); // Expected output: 1

	char str5[] = "!";
	int result5 = ft_str_is_alpha(str5);
	printf("Test case 5: \"%s\" -> %d [EXP: 0]\n", str5, result5); // Expected output: 0

	char str6[] = "Hello World";
	int result6 = ft_str_is_alpha(str6);
	printf("Test case 6: \"%s\" -> %d [EXP: 0]\n", str6, result6); // Expected output: 0

	char str7[] = "@#$%^&";
	int result7 = ft_str_is_alpha(str7);
	printf("Test case 7: \"%s\" -> %d [EXP: 0]\n", str7, result7); // Expected output: 0
}