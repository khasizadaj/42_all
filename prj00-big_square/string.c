/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abied-ch <abied-ch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 14:01:41 by jkhasiza          #+#    #+#             */
/*   Updated: 2023/06/14 17:04:07 by abied-ch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_space(char c);

int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_atoi(char *str)
{
	int	res;
	int	minus;
	int	i;

	i = 0;
	minus = 1;
	res = 0;
	while (is_space(str[i]) == 1)
		i++;
	if (str[i] == '-')
	{
		minus = -1;
		i++;
	}
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (res * minus);
		res = res * 10 + (str[i] - 48);
		i++;
	}
	return (res * minus);
}

int	ft_strstr_pos(char *str, char *to_find)
{
	int	i;
	int	l;

	if (to_find[0] == '\0')
		return (-1);
	i = 0;
	l = 0;
	while (str[i])
	{
		if (str[i] == to_find[l])
		{
			if (to_find[l + 1] == '\0')
				return (i);
			l++;
		}
		else
			l = 0;
		i++;
	}
	return (-1);
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
