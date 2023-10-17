/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasizada <jkhasizada@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 17:08:27 by codespace         #+#    #+#             */
/*   Updated: 2023/10/17 21:12:26 by jkhasizada       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

 == GET NEXT LINE

This project is about programming a function that returns a line
read from a file descriptor.

*/

#include "get_next_line.h"

size_t	ft_strlen(const char *s, char until)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		if (s[i++] == until)
			break ;
	}
	return (i);
}

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
	while (!chr_in('\n', line) && !chr_in('\n', f->buffer))
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
	if (chr_in('\n', line))
		return (line);
	line = transfer(line, f);
	if (!line)
		return ("\0\0");
	return (line);
}

char	*get_next_line(int fd)
{
	static t_fd	*list = NULL;
	t_fd		*file;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
		return (ft_lstclear(&list, &free), NULL);
	file = lstget_or_create(&list, fd);
	if (!file)
		return (ft_lstclear(&list, &free), free(file), NULL);
	if (file->rd < 0)
		return (NULL);
	line = process(file);
	if (!line && file->rd == 0)
		return (ft_lstremove(&list, file), line);
	else if ((!line && file->rd < 0)
		|| (line && line[0] == '\0' && line[1] == '\0'))
		return (ft_lstclear(&list, &free), free(list), NULL);
	return (line);
}
