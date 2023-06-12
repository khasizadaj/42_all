/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 20:14:20 by jkhasiza          #+#    #+#             */
/*   Updated: 2023/06/11 20:40:41 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strlen(char *str);
int	ft_strcmp(char *s1, char *s2);

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while ((i < n) && (s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

int	is_numeric(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	is_in_range(char *number)
{
	int	i;

	i = 0;
	while (number[i])
	{
		if (ft_strlen(number) == 10
			&& ft_strncmp("4294967295", number, 10) >= 0)
			return (1);
		else if (ft_strlen(number) < 10)
			return (1);
		else
			return (0);
		i++;
	}
	return (1);
}

int	validate_input(int argc, char *argv[])
{
	char	*number;
	int		is_number;
	int		number_is_in_range;

	if (argc > 3)
		return (0);
	number = argv[argc - 1];
	is_number = is_numeric(number);
	if (is_number == 0)
		return (0);
	number_is_in_range = is_in_range(number);
	if (number_is_in_range == 0)
		return (0);
	return (1);
}
