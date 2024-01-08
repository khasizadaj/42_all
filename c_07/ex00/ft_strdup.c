/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 11:58:10 by jkhasiza          #+#    #+#             */
/*   Updated: 2023/06/15 12:08:22 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (*str != '\0')
	{
		str++;
		len++;
	}
	return (len);
}

char	*ft_strdup(char *src)
{
	char	*new;
	int		size;
	int		i;

	size = ft_strlen(src);
	new = malloc((size + 1) * sizeof(char));
	if (new == NULL)
		return (NULL);
	i = -1;
	while (src[++i])
	{
		new[i] = src[i];
	}
	new[i] = '\0';
	return (new);
}
