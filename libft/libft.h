#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <stdio.h>

void	ft_bzero(void *s, size_t n);
int		ft_isalnum(char c);
int		ft_isalpha(char c);
int		ft_isascii(int c);
int		ft_isdigit(char c);
char	*ft_itoa(int n);
void	*ft_memchr(const void *s, int c, size_t n);
int     ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
char    *ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strlen(char *str);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int     ft_tolower(int c);
int     ft_toupper(int c);

#endif