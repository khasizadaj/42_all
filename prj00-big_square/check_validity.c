/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_validity.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abied-ch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 19:27:12 by abied-ch          #+#    #+#             */
/*   Updated: 2023/06/12 19:27:13 by abied-ch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strlen_till_char(char *str, char c);
char	*ft_strstr(char *str, char *to_find);

int	count_lines(char *str)
{
	int	i;
	int	lines;

	lines = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			lines++;
		i++;
	}
	return (lines);
}

int	compare_length(char *str, int lines_count)
{
	char	*next_line;
	int		expected_length;
	int		curr_length;

	next_line = ft_strstr(str, "\n");
	expected_length = ft_strlen_till_char(next_line + 1, '\n');
	while (lines_count - 1 > 1)
	{
		next_line = ft_strstr(next_line + 1, "\n");
		curr_length = ft_strlen_till_char(next_line + 1, '\n');
		if (curr_length != expected_length)
			return (0);
		lines_count--;

	}
	return (1);
}	

int	check_validity(char *str)
{
	if (count_lines(str) != 9 + 1) // should be taken from config
		return (0);
	else if (compare_length(str, 9 + 1) == 0)
		return (0);
	return (1);
}
