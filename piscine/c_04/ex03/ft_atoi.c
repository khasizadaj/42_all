/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 15:47:53 by jkhasiza          #+#    #+#             */
/*   Updated: 2023/06/13 22:07:25 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Sample input: -+456 */

int	is_space(char c)
{
	if (c != '\f' && c != '\n' && c != '\r'
		&& c != '\t' && c != '\v' && c != 32 && c != ' ')
		return (0);
	return (1);
}

int	is_numeric(char str)
{
	int	i;

	i = 0;
	if (str < '0' || str > '9')
	{
		return (0);
	}
	return (1);
}

int	ft_atoi(char *str)
{
	int	number;
	int	sign;
	int	i;

	sign = 1;
	number = 0;
	i = 0;
	while (is_space(str[i]))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (is_numeric(str[i]))
	{
		number = (str[i] - '0') + number * 10;
		i++;
	}
	return (number * sign);
}
