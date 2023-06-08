/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 14:55:01 by jkhasiza          #+#    #+#             */
/*   Updated: 2023/06/08 16:54:56 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	int				j;
	unsigned int	i;

	j = ft_strlen(dest);
	i = 0;
	while (i < nb && src[i] != '\0')
	{
		dest[j] = src[i];
		j++;
		i++;
	}
	if (nb > 0)
		dest[j] = '\0';
	return (dest);
}
