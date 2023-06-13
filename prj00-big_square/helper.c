/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 23:08:26 by jkhasiza          #+#    #+#             */
/*   Updated: 2023/06/13 14:01:35 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_space(char c)
{
	if (c != '\f' && c != '\n' && c != '\r'
		&& c != '\t' && c != '\v' && c != 32 && c != ' ')
		return (0);
	return (1);
}

char	*ft_strlcpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] != '\0' && i < n - 1)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n - 1)
	{
		dest[i] = '\0';
		i++;
	}
	dest[i] = '\0';
	return (dest);
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
