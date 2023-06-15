/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 12:09:00 by jkhasiza          #+#    #+#             */
/*   Updated: 2023/06/15 13:18:24 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

int	get_size(int min, int max)
{
	return (max - min);
}

int	*ft_range(int min, int max)
{
	int	*arr;
	int	i;

	if (max <= min)
		return (NULL);
	arr = malloc(get_size(min, max) * sizeof(int));
	if (arr == NULL)
		return (NULL);
	i = -1;
	while (++i < get_size(min, max))
		arr[i] = min + i;
	return (arr);
}