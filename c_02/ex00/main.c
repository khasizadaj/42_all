/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 09:19:08 by jkhasiza          #+#    #+#             */
/*   Updated: 2023/06/02 12:00:05 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char    *ft_strcpy(char *dest, char *src);

int     main(void)
{
    char dest_1[6];
    char dest_1_correct[6];
    char src_1[] = "Hello";
    int result;

    printf("SRC 1:\t%s\n", src_1);

    printf("Orig Pointer Before: %p", src_1);

    strcpy(dest_1_correct, src_1);
    ft_strcpy(dest_1, src_1);

    result = strcmp(dest_1_correct, dest_1);
    int result_2 = strcmp(src_1, dest_1);
    
    printf("strcmp(str1, str2) = %d\n", result);
    printf("Orig vs. Dest: strcmp(str1, str2) = %d\n", result_2);
    printf("Orig Pointer After: %p", src_1);
    printf("DEST 1:\t%s\n", dest_1);
    printf("DEST 1 CORRECT:\t%s\n", dest_1_correct);






    printf("\n\n");
    printf("\n\n");

    char dest_2[2];
    char dest_2_correct[9];
    char src_2[] = "Hello";

    printf("SRC 1:\t%s\n", src_2);

    strcpy(dest_2_correct, src_2);
    ft_strcpy(dest_2, src_2);

    result = strcmp(dest_2_correct, dest_2);
    
    printf("strcmp(str1, str2) = %d\n", result);
    printf("DEST 1:\t%s\n", dest_2);
    printf("DEST 1 CORRECT:\t%s\n", dest_2_correct);



    printf("\n\n");
    printf("\n\n");

    printf("\n\n");
    printf("\n\n");

    char	test1[2];
    char	test2[] = "It works!";

	ft_strcpy(test1, test2);
	printf("%s", test1);
    return (0);
}