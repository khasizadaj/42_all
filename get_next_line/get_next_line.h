/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasizada <jkhasizada@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 17:29:57 by codespace         #+#    #+#             */
/*   Updated: 2023/10/17 19:24:14 by jkhasizada       ###   ########.fr       */
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
	int			start;
}	t_fd;

char    *get_next_line(int fd);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_lstadd_back(t_fd **lst, t_fd *new);
void	ft_lstclear(t_fd **lst, void (*del)(void *));
t_fd	*lstget(t_fd **lst, int fd);
t_fd	*ft_lstnew(int fd);
void	ft_lstremove(t_fd **lst, t_fd *to_be_removed);


#endif