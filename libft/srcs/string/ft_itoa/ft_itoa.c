/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 21:34:08 by jkhasiza          #+#    #+#             */
/*   Updated: 2023/09/05 01:06:20 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_itoa function converts an integer to a string representation.
**
** Parameters:
** n - The integer to be converted.
**
** Return:
** A dynamically allocated string representing the converted integer.
** NULL is returned if memory allocation fails.
**
** Description:
** The ft_itoa function converts the given integer into string representation.
** It first determines the sign of the number by checking if it is negative.
** It calculates the length of the resulting string by counting the number
** of digits in the absolute value of the integer. Memory is allocated to store
** the resulting string, including space for the sign and the null-terminator.
** The conversion is performed by iteratively extracting the digits from the
** integer using modulo and division operations. The digits are then converted
** to characters by adding the ASCII value of '0'. The digits are added to the
** string in reverse order to ensure the correct representation of the number.
** Finally, the sign is added if necessary, the null-terminator is appended,
** and the resulting string is returned.
**
** Note: The caller is responsible for freeing the dynamically allocated memory
** for the returned string when it is no longer needed.
**
** Example:
** ft_itoa(12345);
** returns "12345"
**
** ft_itoa(-456);
** returns "-456"
**
** ft_itoa(0);
** returns "0"
**
** ft_itoa(2147483647);
** returns "2147483647" (maximum value of int)
**
** ft_itoa(-2147483648);
** returns "-2147483648" (minimum value of int)
*/

#include <stdlib.h>
#include <stdio.h>

int	count_digits(int n)
{
	int	count;

	count = 1;
	n = n / 10;
	while (n != 0)
	{
		count++;
		n = n / 10;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char			*str;
	int				size;
	long long		big_number;

	big_number = n;
	size = count_digits(n);
	if (big_number < 0)
		size++;
	str = malloc(sizeof(char) * size);
	if (str == NULL)
		return (NULL);
	if (big_number < 0)
	{
		big_number *= -1;
		str[0] = '-';
	}
	while (--size >= 0)
	{
		if (size == 0 && str[0] == '-')
			break ;
		str[size] = big_number % 10 + '0';
		big_number = big_number / 10;
	}
	return (str);
}
