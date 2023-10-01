/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 21:34:08 by jkhasiza          #+#    #+#             */
/*   Updated: 2023/10/01 19:32:30 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	if (n < 0)
		count++;
	return (count);
}

char	*allocate_memory(int n)
{
	int		size;
	char	*str;

	size = count_digits(n);
	if (n < 0)
		size++;
	str = malloc(sizeof(char) * size + 1);
	if (str == NULL)
		return (NULL);
	return (str);
}

int	get_size(int n)
{
	int	size;

	size = count_digits(n);
	if (n < 0)
		size++;
	return (size);
}

char	*ft_llutoa(unsigned long long n)
{
	char			*str;
	int				size;
	int				i;

	size = get_size(n);
	str = malloc(sizeof(char) * size + 1);
	if (str == NULL)
		return (NULL);
	if (n < 0)
		str[0] = '-';
	if (n < 0)
		n *= -1;
	i = 0;
	while (size - i - 1 >= 0)
	{
		if (size - i - 1 == 0 && str[0] == '-')
			break ;
		str[size - i - 1] = n % 10 + '0';
		n = n / 10;
		i++;
	}
	str[size] = '\0';
	return (str);
}
