/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 17:50:05 by abied-ch          #+#    #+#             */
/*   Updated: 2023/06/14 16:38:11 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

void	ft_putstr(char *str);

char	*ft_realloc(char *old, int old_size, int new_size)
{
	char	*new;
	int		i;

	new = malloc(sizeof(char) * new_size);
	if (new == NULL)
		return (new);
	i = 0;
	while (i < old_size)
	{
		new[i] = old[i];
		i++;
	}	
	free (old);
	return (new);
}

char	*read_file(int fd)
{
	int		i;
	char	*str;
	char	current;
	char	*new;

	i = 0;
	str = malloc(sizeof(char) * 11);
	if (str == NULL)
		return (str);
	while (read(fd, &current, 1) != 0)
	{
		str[i] = current;
		if (++i % 10 == 0)
		{
			new = ft_realloc(str, i + 1, sizeof(char) * i + 11);
			if (new != NULL)
				str = new;
			else
				return (str);
		}
	}
	str[i] = '\0';
	return (str);
}

char	*open_and_read(char *file)
{
	int		fd;
	char	*str;

	fd = open(file, O_RDONLY);
	if (fd != -1)
	{
		str = read_file(fd);
		if (close(fd) == -1)
			ft_putstr("file error");
		return (str);
	}
	ft_putstr("file error");
	exit (0);
}
