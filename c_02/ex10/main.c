/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 09:19:08 by jkhasiza          #+#    #+#             */
/*   Updated: 2023/06/02 21:25:37 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <bsd/string.h>
#include <string.h>

unsigned int ft_strlcpy(char *dest, char *src, unsigned int size);

void test(int size)
{
    char string[] = "Hello there, Venus";
    char buffer[size];
    int r;

    r = strlcpy(buffer, string, size);

    printf("Copied '%s' (%lu character(s)) into '%s', length %d\n",
            string,
	    strlen(buffer),
            buffer,
            r
          );
}

int main()
{
    test(19);
    test(10);
    test(1);
    test(0);

    return(0);
}