/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abied-ch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 17:50:05 by abied-ch          #+#    #+#             */
/*   Updated: 2023/06/12 18:45:44 by abied-ch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

char	*ft_realloc(char *old, int old_size, int new_size)
{
	char	*new;
	int		i;

	new = malloc(sizeof(char) * new_size);
	if (new == 0)
		return (0);
	i = 0;
	while (i < old_size)
	{
		new[i] = old[i];
		i++;
	}	
	free (old);
	return (new);
}

char	*read_file(char *file)
{
	int		fd;
	int		i;
	char	*str;
	char	current;
	int		allocated_size;

	allocated_size = 10;
	i = 0;
	str = malloc(sizeof(char) * 10);
	fd = open(file, O_RDONLY);
	while (read(fd, &current, 1) != 0)
	{
		str[i] = current;
		i++;
		if (i == allocated_size)
		{
			allocated_size = allocated_size + 10;
			str = ft_realloc(str, (allocated_size - 10),
					sizeof(char) * allocated_size);
		}
	}
	str[i] = '\0';
	return (str);
}
