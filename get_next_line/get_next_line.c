/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 17:08:27 by codespace         #+#    #+#             */
/*   Updated: 2023/10/27 15:43:57 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	flush_buffer(t_fd *file)
{
	size_t			i;
	size_t			j;

	i = 0;
	while (file->buffer[i] != '\n' && file->buffer[i] != '\0')
		i++;
	if (file->buffer[i] == '\n')
		i++;
	j = -1;
	while (file->buffer[i] != '\0' && i < BUFFER_SIZE)
		file->buffer[++j] = file->buffer[i++];
	while (++j < BUFFER_SIZE)
		file->buffer[j] = '\0';
}

char	*transfer(char *line, t_fd *f)
{
	char	*temp;

	temp = line;
	line = ft_strjoin_until(temp, f->buffer, '\n');
	if (!line)
		return (free(temp), NULL);
	free(temp);
	flush_buffer(f);
	return (line);
}

char	*process(t_fd *f)
{
	char	*line;

	line = malloc(1);
	if (!line)
		return ("\0\0");
	line[0] = '\0';
	if (ft_strlen(f->buffer, '\0') > 0)
	{
		line = transfer(line, f);
		if (!line)
			return ("\0\0");
	}
	while (!chr_in('\n', line))
	{
		f->rd = read(f->fd, f->buffer, BUFFER_SIZE);
		if (f->rd == 0 && ft_strlen(line, '\0') > 0)
			return (line);
		else if (f->rd <= 0)
			return (free(line), NULL);
		line = transfer(line, f);
		if (!line)
			return ("\0\0");
	}
	return (line);
}

/*

Static file used here is treated as list of files
and it's open for extension. However, there can be
one file at a time.

*/

char	*get_next_line(int fd)
{
	static t_fd	*file = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
		return (ft_clear(&file), NULL);
	if (!file)
	{
		file = ft_lstnew(fd);
		if (!file)
			return (NULL);
	}
	if (file->rd < 0)
		return (NULL);
	line = process(file);
	if (!line && file->rd == 0)
		return (ft_clear(&file), line);
	else if ((!line && file->rd < 0)
		|| (line && line[0] == '\0' && line[1] == '\0'))
		return (ft_clear(&file), NULL);
	return (line);
}
