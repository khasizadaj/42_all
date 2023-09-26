/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 23:08:26 by jkhasiza          #+#    #+#             */
/*   Updated: 2023/06/11 15:57:31 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_space(char c)
{
	if (c != '\f' && c != '\n' && c != '\r'
		&& c != '\t' && c != '\v' && c != 32 && c != ' ')
		return (0);
	return (1);
}

int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int	ft_atoi(char *str)
{
	unsigned int	anzahl;
	unsigned int	i;
	int				zahl;

	anzahl = 0;
	zahl = 0;
	i = 0;
	while (is_space(str[i]) == 1)
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			anzahl += 1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		zahl = zahl * 10 + (str[i] - '0');
		i++;
	}
	if (anzahl % 2)
		zahl *= (-1);
	return (zahl);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] == s2[i])
			i++;
		else
			return (s1[i] - s2[i]);
	}
	return (s1[i] - s2[i]);
}
