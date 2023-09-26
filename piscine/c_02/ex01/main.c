/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 09:19:08 by jkhasiza          #+#    #+#             */
/*   Updated: 2023/05/31 16:48:18 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char    *ft_strncpy(char *dest, char *src, unsigned int n);

int     main(void)
{
    char dest_1[5];
    char dest_1_correct[5];
    char src_1[] = "Hello";
    int size;

    printf("SRC 1:\t%s\n", src_1);

    size = 3;
    strncpy(dest_1_correct, src_1, size);
    ft_strncpy(dest_1, src_1, size);
    
    printf("EXP:\t%s\n", dest_1);
    printf("ACT:\t%s\n", dest_1_correct);

    printf("\n\n");

    char dest_2[12];
    char dest_2_correct[12];
    char src_2[] = "Hello World Hi!";
    size = 10;

    printf("SRC 1:\t%s\n", src_2);

    strncpy(dest_2_correct, src_2, size);
    ft_strncpy(dest_2, src_2, size);

    printf("EXP:\t%s\n", dest_2);
    printf("ACT:\t%s\n", dest_2_correct);

    return (0);
}