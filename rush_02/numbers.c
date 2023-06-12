/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 15:56:46 by jkhasiza          #+#    #+#             */
/*   Updated: 2023/06/11 15:59:19 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		is_space(char c);
char	*get_word(char *str);
int		ft_strlen(char *str);

int	*get_expected_numbers(void)
{
	int	*numbers;
	int	i;
	int	value;

	numbers = malloc(sizeof(int) * 32);
	i = 0;
	value = 0;
	while (i < 32)
	{
		numbers[i] = value;
		if (value < 20)
			value++;
		else if (value < 100)
			value += 10;
		else if (value < 1000)
			value *= 10;
		else
			value *= 1000;
		i++;
	}
	return (numbers);
}

int	get_expected_numbers_index(int lookup)
{
	int	i;
	int	value;

	i = 0;
	value = -1;
	while (i < 32)
	{
		if (value < 20)
			value++;
		else if (value < 100)
			value += 10;
		else if (value < 1000)
			value *= 10;
		else
			value *= 1000;
		if (lookup == value)
			return (i);
		i++;
	}
	return (-1);
}

int	is_exist(int number, int *expected_numbers)
{
	int	i;

	i = get_expected_numbers_index(number);
	if (i == -1)
		return (0);
	if (expected_numbers[i] == -1)
		return (-1);
	expected_numbers[i] = -1;
	return (1);
}

int	has_valid_number(char *line)
{
	int	i;

	i = 0;
	while (line[i] != ':')
	{
		if ((line[i] >= '0' && line[i] <= '9') || is_space(line[i]) == 1)
			i++;
		else
			return (0);
	}
	return (1);
}

int	has_valid_value(char *line)
{
	char	*value;

	value = get_word(line);
	if (ft_strlen(value) == 0)
	{
		free(value);
		return (0);
	}
	free(value);
	return (1);
}
