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

int	ft_strlen_till_char(char *str, char c)
{
	unsigned int	i;

	i = 0;
	while (str[i])
	{
		if (c == str[i])
			return (i);
		i++;
	}
	return (i);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	if (to_find[0] == '\0')
		return (str);
	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] == to_find[j])
		{
			if (to_find[j + 1] == '\0')
				return (str + i - j);
			j++;
		}
		else
			j = 0;
		i++;
	}
	return (0);
}

int	compare_length(char *str, int lines)
{
	char	*ptr;
	int		n;
	int		compare;

	ptr = ft_strstr(str, "\n");
	n = ft_strlen_till_char(ptr + 1, '\n');
	while (*str != '\0' && lines - 1 > 1)
	{
		ptr = ft_strstr(ptr + 1, "\n");
		compare = ft_strlen_till_char(ptr + 1, '\n');
		if (compare != n)
			return (0);
		lines--;
	}
	return (1);
}	

int	check_validity(char *str)
{
	if (count_lines(str) < 1)
		return (0);
	else if (compare_length(str, count_lines(str)) == 0)
		return (0);
	return (1);
}
