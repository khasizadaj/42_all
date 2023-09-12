/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 22:30:36 by jkhasiza          #+#    #+#             */
/*   Updated: 2023/09/10 22:30:41 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	chr_in(char c, char const *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_strlen(char const *str);

int	ft_strltrim_count(char const *s1, char const *set)
{
	int	i;

	i = 0;
	if (s1[i] == '\0')
		return (0);
	while (s1[i] && chr_in(s1[i], set) == 1)
		i++;
	return (i);
}

int	ft_strrtrim_count(char const *s1, char const *set)
{
	int	len;
	int	i;

	len = ft_strlen(s1);
	if (len == 0)
		return (0);
	i = len - 1;
	while (s1[i] && chr_in(s1[i], set) == 1)
	{
		i--;
	}
	return (len - 1 - i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		l_count;
	int		r_count;
	char	*trimmed;
	int		j;
	int		i;

	l_count = ft_strltrim_count(s1, set);
	r_count = ft_strrtrim_count(s1, set);
	trimmed = malloc(sizeof(char) * (ft_strlen(s1) - l_count - r_count + 1));
	if (trimmed == NULL)
		return (NULL);
	if (ft_strlen(s1) == 0)
		return (trimmed);
	i = 0;
	j = 0;
	while (s1[i])
	{
		if (i >= l_count && i <= (ft_strlen(s1) - 1 - r_count))
			trimmed[j++] = s1[i];
		i++;
	}
	return (trimmed);
}
