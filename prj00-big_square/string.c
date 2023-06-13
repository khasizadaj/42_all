/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 14:01:41 by jkhasiza          #+#    #+#             */
/*   Updated: 2023/06/13 14:04:16 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
