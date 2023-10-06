/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 17:08:27 by codespace         #+#    #+#             */
/*   Updated: 2023/10/06 02:54:46 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

 == GET NEXT LINE

This project is about programming a function that returns a line
read from a file descriptor.

*/

#include "get_next_line.h"

char	*ft_strjoin_until(const char *s1, const char *s2, char until);

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin_until(const char *s1, const char *s2, char until)
{
	int		len_1;
	int		len_2;
	char	*joined;
	int		i;

	len_1 = ft_strlen(s1);
	len_2 = ft_strlen(s2);
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
		if (s2[i] == until)
			break ;
		i++;
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
	while (file->buffer[i] != '\0' && i < BUFFERSIZE)
		file->buffer[++j] = file->buffer[i++];
	// printf("j=%ld\n", j);
	while (++j < BUFFERSIZE)
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
		return (NULL);
	line[0] = '\0';
	if (*(f->buffer) && ft_strlen(f->buffer) > 0)
	{
		temp = line;
		line = ft_strjoin_until(temp, f->buffer, '\n');
		if (!line)
			return (free(temp), NULL);
		free(temp);
	}
	// FIXME: Can't handle bigger buffersize
	while ((f->read = read(f->fd, f->buffer, BUFFERSIZE)) > 0)
	{
		printf("[proc-w]\t[rd=%d]\t'%s'\n", f->read, f->buffer);
		temp = line;
		if (chr_in('\n', f->buffer))
		{
			line = ft_strjoin_until(temp, f->buffer, '\n');
			if (!line)
				return (free(temp), NULL);
			return (free(temp), flush_buffer(f), line);	
		}
		else
		{
			line = ft_strjoin_until(temp, f->buffer, '\0');
			if (!line)
				return (free(temp), NULL);
			flush_buffer(f);
			free(temp);
		}
	}
	
	temp = line;
	line = ft_strjoin_until(temp, f->buffer, '\0');
	// if ((line && ft_strlen(line) == 0))
	// 	return (line);
	if (!line || (line && ft_strlen(line) == 0))
		return (flush_buffer(f), free(temp), free(line), NULL);
	printf("[proc]\t[rd=%d]\t'%s'\n", f->read, line);
	if(f->read == 0 || chr_in('\n', f->buffer))
		return (flush_buffer(f), free(line), free(temp), NULL);
	return (free(temp), line);
}

void	print_list(t_fd *list);

char	*get_next_line(int fd)
{
	static t_fd	*list = NULL;
	t_fd		*file;
	char		*line;

	// printf("\n==\nCurr fd: %d\n", fd);
	// TODO: Add condition to free finished files but in list
	if (fd < 0)
		return (NULL);
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
	printf("[gnl]\t[rd=%d]\t'%s'\n", file->read, line);
	printf("[gnl-f]\t[rd=%d]\t'%s'\n", file->read, file->buffer);
	if (!line && file->read == 0)
		return (ft_lstremove(&list, file), NULL);
	else if (!line || file->read < 0)
		return (ft_lstclear(&list, &free), NULL);
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