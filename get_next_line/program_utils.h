/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_utils.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 16:29:38 by codespace         #+#    #+#             */
/*   Updated: 2023/10/05 20:15:21 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROGRAM_UTILS_H
# define PROGRAM_UTILS_H

# include <stdio.h>
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

char    *get_next_line(int fd);
size_t	ft_strlen(const char *s);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *s, int c, size_t n);
int		ft_atoi(const char *nptr);

#endif