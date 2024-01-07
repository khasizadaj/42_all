/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:19:00 by codespace         #+#    #+#             */
/*   Updated: 2024/01/07 14:25:20 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

bool	validate_4_digits(char **raw_numbers, int start)
{
	int	col;
	int	row;

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
	return (true);
}

bool	validate_4_duplicates(char **raw_numbers, int start)
{
	int	row;

	row = start;
	while (raw_numbers[++row])
	{
		if (ft_strarr_has(raw_numbers[row], &raw_numbers[row + 1]))
			return (false);
	}
	return (true);
}

bool	validate_4_overflow(char **raw_numbers, int start)
{
	int		row;
	char	*curr;
	bool	has_sign;

	row = start;
	while (raw_numbers[++row])
	{
		curr = raw_numbers[row];
		has_sign = false;
		if (curr[0] == '-' || curr[0] == '+')
			has_sign = true;
		if ((!has_sign && ft_strlen(raw_numbers[row]) > 10)
			|| (has_sign && ft_strlen(raw_numbers[row]) > 11))
			return (false);
		if (ft_atoi_lli(curr) > 2147483647 || ft_atoi_lli(curr) < -2147483648)
			return (false);
	}
	return (true);
}

int	validate_input(int argc, char **argv)
{
	int		size;
	char	**raw_numbers;
	int		start;
	bool	result;

	size = get_raw_numbers(&raw_numbers, argc, argv);
	if (size == -1)
		return (0);
	start = 0;
	if (argc == 2)
		start = -1;
	result = true;
	if (!validate_4_digits(raw_numbers, start)
		|| !validate_4_duplicates(raw_numbers, start)
		|| !validate_4_overflow(raw_numbers, start))
		result = false;
	if (argc == 2)
		free_numbers(size, raw_numbers);
	return (result);
}
