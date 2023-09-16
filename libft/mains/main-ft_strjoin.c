/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main-ft_strjoin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 21:45:26 by jkhasiza          #+#    #+#             */
/*   Updated: 2023/09/16 12:34:59 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

void run_test(char *res, char *exp)
{
    printf("RES: '%s'\n", res);
    printf("EXP: '%s'\n", exp);
    if (ft_strncmp(res, exp, 4) == 0)
        printf("\n>> PASS: All good!\n\n");
    else
        printf("\n>> FAIL: Not good || \n\tEXP: '%s'; \n\tRES: '%s'\n\n", exp, res);
}

int main(int argc, char *argv[])
{
    printf("Test 1: \n");
    char s_1_1[5];
    char s_1_2[5];
    char *exp_1;

    exp_1 = "ajaxxaja";
    strncpy(s_1_1, "ajax", sizeof(s_1_1));
    s_1_1[sizeof(s_1_1) - 1] = '\0';
    strncpy(s_1_2, "xaja", sizeof(s_1_2));
    s_1_2[sizeof(s_1_2) - 1] = '\0';

    char *res_1 = ft_strjoin(s_1_1, s_1_2);
    run_test(res_1, exp_1);

    printf("Test 2: \n");
    char s_2_1[5];
    char s_2_2[11];
    char *exp_2;

    exp_2 = "ajaxGulnara123";
    strncpy(s_2_1, "ajax", sizeof(s_2_1));
    s_2_1[sizeof(s_2_1) - 1] = '\0';
    strncpy(s_2_2, "Gulnara123", sizeof(s_2_2));
    s_2_2[sizeof(s_2_2) - 1] = '\0';

    char *res_2 = ft_strjoin(s_2_1, s_2_2);
    run_test(res_2, exp_2);

    printf("Test 3: \n");
    char s_3_1[5];
    char s_3_2[1];
    char *exp_3;

    exp_3 = "ajax";
    strncpy(s_3_1, "ajax", sizeof(s_3_1));
    s_3_1[sizeof(s_3_1) - 1] = '\0';
    strncpy(s_3_2, "", sizeof(s_3_2));
    s_3_2[sizeof(s_3_2) - 1] = '\0';

    char *res_3 = ft_strjoin(s_3_1, s_3_2);
    run_test(res_3, exp_3);

    printf("Test 4: \n");
    char s_4_1[1];
    char s_4_2[1];
    char *exp_4;

    exp_4 = "";
    strncpy(s_4_1, "", sizeof(s_4_1));
    s_4_1[sizeof(s_4_1) - 1] = '\0';
    strncpy(s_4_2, "", sizeof(s_4_2));
    s_4_2[sizeof(s_4_2) - 1] = '\0';

    char *res_4 = ft_strjoin(s_4_1, s_4_2);
    run_test(res_4, exp_4);
}
