/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 15:45:53 by jkhasiza          #+#    #+#             */
/*   Updated: 2023/06/14 02:52:52 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>
#include <unistd.h>

void	ft_putnbr_base(int nbr, char *base);
int		base_is_valid(char *base);

int main() {
    // TEST: BASE
    char* base_1 = "123";
    int result1 = base_is_valid(base_1);
    printf("Result 1: =: %d := [1]\n", result1);

	char* base_2 = "1233";
    int result_2 = base_is_valid(base_2);
    printf("Result 2: =: %d := [0]\n", result_2);

	char* base_3 = "";
    int result_3 = base_is_valid(base_3);
    printf("Result 3: =: %d := [0]\n", result_3);

	char* base_4 = "a";
    int result_4 = base_is_valid(base_4);
    printf("Result 4: =: %d := [0]\n", result_4);

	char* base_5 = "abc-";
    int result_5 = base_is_valid(base_5);
    printf("Result 5: =: %d := [0]\n", result_5);

	char* base_6 = "abc+";
    int result_6 = base_is_valid(base_6);
    printf("Result 6: =: %d := [0]\n", result_6);

	// TEST: FUNCTION
	int num_7 = 123;
	char* base_7 = "0123456789ABCDEF";
    ft_putnbr_base(num_7, base_7);
	write(1, "\n", 1);

	int num_8 = 56748;
	char* base_8 = "01234567";
    ft_putnbr_base(num_8, base_8);
	write(1, " --> EXP: 156654\n", 17);

	int num_9 = 2147483647;
	char* base_9 = "01234567";
    ft_putnbr_base(num_9, base_9); // EXP: 17777777777
	write(1, " --> EXP: 17777777777\n", 23);

    return 0;
}