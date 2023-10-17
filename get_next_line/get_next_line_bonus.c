/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasizada <jkhasizada@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 17:08:27 by codespace         #+#    #+#             */
/*   Updated: 2023/10/17 19:04:02 by jkhasizada       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

 == GET NEXT LINE

This project is about programming a function that returns a line
read from a file descriptor.

*/

#include "get_next_line.h"

char	*ft_strjoin_until(const char *s1, const char *s2, char until);

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

char	*ft_strjoin_until(const char *s1, const char *s2, char until)
{
	int		len_1;
	int		len_2;
	char	*joined;
	int		i;

	len_1 = ft_strlen(s1, '\0');
	len_2 = ft_strlen(s2, '\n');
	joined = malloc(sizeof(char) * (len_1 + len_2 + 1));
	if (joined == NULL)
		return (NULL);
	i = -1;
	while (s1[++i] != '\0')
	{
		joined[i] = s1[i];
	}
	i = 0;
	while (s2[i] != '\0')
	{
		joined[len_1 + i] = s2[i];
		if (s2[i++] == until)
			break ;
	}
	joined[len_1 + i] = '\0';
	return (joined);
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
	// printf("[flush]\t[buff]\t'%s'\n", file->buffer);
	while (file->buffer[i] != '\n' && file->buffer[i] != '\0')
		i++;
	// printf("i=%ld\n", i);
	if (file->buffer[i] == '\n')
		i++;
	// printf("i=%ld\n", i);
	
	j = -1;
	// printf("j=%ld\n", j);
	while (file->buffer[i] != '\0' && i < BUFFER_SIZE)
		file->buffer[++j] = file->buffer[i++];
	// printf("j=%ld\n", j);
	while (++j < BUFFER_SIZE)
		file->buffer[j] = '\0';
	// printf("j=%ld\n", j);
	// printf("[flush]\t[buff]\t'%s'\n", file->buffer);
}

char	*process(t_fd *f)
{
	char	*line;
	char	*temp;

	if (f->read < 0)
		return (NULL);
	line = malloc(1);
	if (!line)
		return ("\0\0");
	line[0] = '\0';
	// printf("[pr-0]\t[rd=%d]\t'%s'\n", f->read, f->buffer);
	if (ft_strlen(f->buffer, '\0') > 0)
	{
		temp = line;
		line = ft_strjoin_until(temp, f->buffer, '\n');
		// printf("[pr-0]\t[l=%ld]\t'%s'\n", ft_strlen(line), line);
		if (!line)
			return (free(temp), "\0\0");
		free(temp);
		flush_buffer(f);
	}
	while (!chr_in('\n', line) && !chr_in('\n', f->buffer))
	{
		// printf("[pr-1]\t[rd=%d]\t'%s'\n", f->read, f->buffer);
		f->read = read(f->fd, f->buffer, BUFFER_SIZE);
		// printf("[pr-1]\t[rd=%d]\t'%s'\n", f->read, f->buffer);
		if (f->read == 0 && ft_strlen(line, '\0') > 0)
			return (line);
		else if (f->read == 0 && ft_strlen(line, '\0') == 0 && ft_strlen(f->buffer, '\0') == 0)
			return (free(line), NULL);
		else if (f->read == -1)
			return (free(line), NULL);
		temp = line;
		line = ft_strjoin_until(temp, f->buffer, '\n');
		// printf("[pr-2]\t[l=%ld]\t'%s'\n", ft_strlen(line), line);
		if (!line)
			return (free(temp), "\0\0");
		free(temp);
		flush_buffer(f);
	}
	if (chr_in('\n', line))
		return (line);
	// FIXME: Can't handle new no new line at the end 
	// FIXME: Can't handle empty buffer at the end
	temp = line;
	line = ft_strjoin_until(temp, f->buffer, '\n');
	// printf("[pr-3]\t[rd=%d]\t'%s'\n", f->read, f->buffer);
	// printf("[pr-3]\t[l=%ld]\t'%s'\n", ft_strlen(line), line);
	if (!line)
		return (free(temp), "\0\0");
	return (free(temp), flush_buffer(f), line);	
}

void	print_list(t_fd *list);

char	*get_next_line(int fd)
{
	static t_fd	*list = NULL;
	t_fd		*file;
	char		*line;

	// printf("\n==\nCurr fd: %d\n", fd);
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
		return (ft_lstclear(&list, &free), NULL);
	file = lstget(&list, fd);
	if (!file)
	{
		file = ft_lstnew(fd);
		if (!file)
			return (ft_lstclear(&list, &free), free(file), NULL);
		// printf("[new]\t[fd=%d]\n", file->fd);
		ft_lstadd_back(&list, file);
	}
	line = process(file);
	// printf("[gnl]\t[rd=%d]\t'%s'\n", file->read, line);
	// printf("[gnl-f]\t[rd=%d]\t'%s'\n", file->read, file->buffer);

	if (!line && file->read == 0)
		return (ft_lstremove(&list, file), line);
	else if ((!line && file->read < 0) || (line && line[0] == '\0' && line[1] == '\0')) // added memory allocation guarding clause for line
	{
		// printf("LINE: %sl", line);
		return (ft_lstclear(&list, &free), free(list), NULL);
	}
	return (line);
}

// TODO: DELETE THIS LATER
void	print_list(t_fd *list)
{
	t_fd *current = list;
	if (!current)
		printf("\n========\nNO FILE LEFT\n");
	else
	{
		printf("\n========\nPRINT ALL FILES\n");
		while (current != NULL)
		{
			printf("fd=%d\n", current->fd);
			current = current->next;
		}
	}
	printf("========\n\n");
}