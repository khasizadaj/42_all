/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasizada <jkhasizada@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 17:29:57 by codespace         #+#    #+#             */
/*   Updated: 2023/10/17 21:16:13 by jkhasizada       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 8
# endif

# include <stdio.h>
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_fd
{
	int			fd;
	char		*buffer;
	struct s_fd	*next;
	int			rd;
}	t_fd;

char    *get_next_line(int fd);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_lstadd_back(t_fd **lst, t_fd *new);
void	ft_lstclear(t_fd **lst, void (*del)(void *));
t_fd	*lstget(t_fd **lst, int fd);
t_fd	*ft_lstnew(int fd);
void	ft_lstremove(t_fd **lst, t_fd *to_be_removed);
t_fd	*lstget_or_create(t_fd **lst, int fd);
char	*ft_strjoin_until(const char *s1, const char *s2, char until);
size_t	ft_strlen(const char *s, char until);

#endif