#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char const *str)
{
	int	len;

	len = 0;
	while (*str != '\0')
	{
		str++;
		len++;
	}
	return (len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len_1;
	int		len_2;
	char	*joined;
	int		i;

	len_1 = ft_strlen(s1);
	len_2 = ft_strlen(s2);
	joined = malloc(sizeof(char) * (len_1 + len_2));
	i = -1;
	while (s1[++i] != '\0')
	{
		joined[i] = s1[i];
	}
	i = -1;
	while (s2[++i] != '\0')
	{
		joined[len_1 + i] = s2[i];
	}
	return (joined);
}