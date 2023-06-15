/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 12:03:16 by jkhasiza          #+#    #+#             */
/*   Updated: 2023/06/15 12:05:17 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char	*ft_strdup(char *src);

int main() {
    char *original_str = "Hello, World!";
    char *duplicated_str = ft_strdup(original_str);

    printf("Original string: %s\n", original_str);
    printf("Duplicated string: %s\n", duplicated_str);

    free(duplicated_str);  // Don't forget to free the allocated memory

    return 0;
}
