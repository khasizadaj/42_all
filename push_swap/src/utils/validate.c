/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:19:00 by codespace         #+#    #+#             */
/*   Updated: 2024/01/05 17:18:28 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"


bool validate_4_digits(char **raw_numbers, int start)
{
    int col;
    int row;

    row = start;
    while (raw_numbers[++row])
    {
        col = -1;
        if (raw_numbers[row][0] == '-' || raw_numbers[row][0] == '+')
            col++;
        while (raw_numbers[row][++col])
            if (ft_isdigit(raw_numbers[row][col]) == false)
                return (false);
    }    
    print_raw_numbers(raw_numbers);
    return (true);
}


int validate_input(int argc, char **argv)
{
    int     size;
    char    **raw_numbers;
    int     start;

    size = get_raw_numbers(&raw_numbers, argc, argv);
    if (size == -1)
		return (0);
    start = 0;
    if (argc == 2)
        start = -1;
    /* TODO Add validation for overflow */
    /* TODO Add validation for duplicate */
    if (!validate_4_digits(raw_numbers, start))
        return (false);
    if (argc == 2)
        free_numbers(size, raw_numbers);
    return (true);
}
