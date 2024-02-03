/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:19:00 by codespace         #+#    #+#             */
/*   Updated: 2024/02/04 00:42:49 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

t_bool	validate_4_digits(char **raw_numbers, int start)
{
	int	row;

	row = start;
	while (raw_numbers[++row])
	{
		if (ft_str_isdigit(raw_numbers[row]) == false)
			return (FALSE);
	}
	return (TRUE);
}

t_bool	validate_stack_4_duplicates(t_number **stack)
{
	t_number	*tmp;

	if (!stack || !(*stack))
		return (FALSE);
	tmp = *stack;
	while (tmp)
	{
		if (tmp->next && ft_stackindex(&tmp->next, tmp->number) != -1)
			return (FALSE);
		tmp = tmp->next;
	}
	return (TRUE);
}

t_bool	validate_4_overflow(char **nums, int start)
{
	int		row;
	char	*curr;
	int		i;

	row = start;
	while (nums[++row])
	{
		curr = nums[row];
		i = 0;
		while (curr[i] == ' ')
			i++;
		if (curr[i] == '-' || curr[i] == '+')
			i++;
		while (curr[i] == '0')
			i++;
		if (ft_strlen(&(nums[row][i])) > 11 || ft_atoi_lli(curr) > INT_MAX
			|| ft_atoi_lli(curr) < INT_MIN)
			return (false);
	}
	return (true);
}

/*
	Function validates input for having only digits, without
	any duplication and without any number that is over integer
	limits.

	Function considers one argument with array of integers or
	multiple arguments with single integer.
*/
t_bool	validate_input(int argc, char **argv)
{
	int		size;
	char	**raw_numbers;
	int		start;
	t_bool	result;

	size = get_raw_numbers(&raw_numbers, argc, argv);
	if (size == -1)
		return (FALSE);
	start = 0;
	if (argc == 2)
		start = -1;
	result = TRUE;
	if (!validate_4_digits(raw_numbers, start)
		|| !validate_4_overflow(raw_numbers, start))
		result = FALSE;
	if (argc == 2)
		free_numbers(size, raw_numbers);
	return (result);
}
