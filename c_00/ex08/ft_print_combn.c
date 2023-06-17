/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 20:37:04 by jkhasiza          #+#    #+#             */
/*   Updated: 2023/05/29 19:21:41 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	get_first(char end, int *result)
{
	int	curr;
	int	i;

	i = 0;
	curr = '0';
	while (curr <= end)
	{
		result[i] = curr;
		i++;
		curr++;
	}
}

void	find_start(int *result, int *start, int n)
{
	int	distance;
	int	value;

	distance = 0;
	while (distance <= n - 1)
	{
		value = result[*start];
		if (value + distance == 9 + '0')
		{
			(*start)--;
			if (*start == 0)
				break ;
		}
		else
			break ;
		distance++;
	}
}

void	print_next(int *result, int n)
{
	int	i;
	int	start;

	start = n - 1;
	find_start(result, &start, n);
	i = 0;
	while (i < n)
	{
		if (i == start)
			result[i] = result[i] + 1;
		else if (i > start)
			result[i] = result[i - 1] + 1;
		i++;
	}
}

void	ft_print_combn(int n)
{
	int	result[10];
	int	int_size;

	int_size = 4;
	get_first(n - 1 + '0', result);
	write(1, &result, int_size * n);
	while (result[0] < '9' - (n - 1))
	{
		write(1, ", ", 2);
		print_next(result, n);
		write(1, &result, int_size * n);
	}
}
