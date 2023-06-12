/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 22:31:17 by mmarta            #+#    #+#             */
/*   Updated: 2023/06/12 13:31:38 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_reallocate(char *old, int old_size, int new_size)
{
	char	*new;
	int		i;

	new = malloc(sizeof(char) * new_size);
	if (new == 0)
	{
		return (0);
	}
	i = 0;
	while (i < old_size)
	{
		new[i] = old[i];
		i++;
	}
	free(old);
	return (new);
}

int	free_count_valid_lines_memory(char *line, int *numbers)
{
	free(line);
	free(numbers);
	return (0);
}
