/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 23:08:26 by jkhasiza          #+#    #+#             */
/*   Updated: 2023/06/12 22:08:52 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_space(char c)
{
	if (c != '\f' && c != '\n' && c != '\r'
		&& c != '\t' && c != '\v' && c != 32 && c != ' ')
		return (0);
	return (1);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
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
