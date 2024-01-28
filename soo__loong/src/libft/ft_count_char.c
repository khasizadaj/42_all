/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 02:12:52 by jkhasiza          #+#    #+#             */
/*   Updated: 2024/01/28 02:47:38 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
int ft_count_char(const char *str, char ch)
{
    int count;
    
    count = 0;
    if (!str)
        return 0;

    while (*str)
    {
        if (*str == ch)
            count++;
        str++;
    }
    return (count);
}

int ft_count_nchar(const char *str, char ch, int n)
{
    int count;
    
    count = 0;
    if (!str)
        return 0;

    while (*str && n-- > 0)
    {
        ft_printf("N%d\n", n);
        if (*str == ch)
            count++;
        str++;
    }
    return (count);
}