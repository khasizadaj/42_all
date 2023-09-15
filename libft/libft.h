#ifndef LIBFT_H
# define LIBFT_H

#include <stdlib.h>

void	ft_bzero(void *s, size_t n);
int		ft_isalnum(char c);
int		ft_isalpha(char c);
int		ft_isascii(int c);
int		ft_isdigit(char c);
char	*ft_itoa(int n);
void	*ft_memset(void *s, int c, size_t n);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strlen(char *str);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif