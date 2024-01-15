/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:19:00 by codespace         #+#    #+#             */
/*   Updated: 2024/01/15 17:48:16 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

t_bool	validate_4_digits(char **raw_numbers, int start)
{
	int	col;
	int	row;

	row = start;
	while (raw_numbers[++row])
	{
		col = -1;
		if (raw_numbers[row][0] == '-' || raw_numbers[row][0] == '+')
			col++;
		while (ft_isint(raw_numbers[row]) == FALSE)
			return (FALSE);
	}
	return (TRUE);
}

t_bool	validate_4_duplicates(char **raw_numbers, int start)
{
	int	row;

	row = start;
	while (raw_numbers[++row])
	{
		if (ft_strarr_has(raw_numbers[row], &raw_numbers[row + 1]))
			return (FALSE);
	}
	return (TRUE);
}

t_bool	validate_4_overflow(char **raw_numbers, int start)
{
	int		row;
	char	*curr;
	t_bool	has_sign;

	row = start;
	while (raw_numbers[++row])
	{
		curr = raw_numbers[row];
		has_sign = FALSE;
		if (curr[0] == '-' || curr[0] == '+')
			has_sign = TRUE;
		if ((!has_sign && ft_strlen(raw_numbers[row]) > 10)
			|| (has_sign && ft_strlen(raw_numbers[row]) > 11))
			return (FALSE);
		if (ft_atoi_lli(curr) > 2147483647 || ft_atoi_lli(curr) < -2147483648)
			return (FALSE);
	}
	return (TRUE);
}

int	validate_input(int argc, char **argv)
{
	int		size;
	char	**raw_numbers;
	int		start;
	t_bool	result;

	size = get_raw_numbers(&raw_numbers, argc, argv);
	if (size == -1)
		return (0);
	start = 0;
	if (argc == 2)
		start = -1;
	result = TRUE;
	if (!validate_4_digits(raw_numbers, start)
		|| !validate_4_duplicates(raw_numbers, start)
		|| !validate_4_overflow(raw_numbers, start))
		result = FALSE;
	if (argc == 2)
		free_numbers(size, raw_numbers);
	return (result);
}
