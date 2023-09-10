#include <stdlib.h>
#include <stdio.h>

int	count_words(char const *s, char c)
{
	int	count;
	int	counting;
	int	i;

	i = 0;
	count = 0;
	counting = 0;

	while (s[i])
	{
		if (s[i] != c && counting == 0)
		{
			counting = 1;
			count++;
		}
		else if (s[i] == c)
			counting = 0;
		i++;
	}
	return (count);
}

int	length_of_next(int i, char const *s, char c)
{
	int	end_of_next;

	end_of_next = i + 1;
	while (s[end_of_next] != c && s[end_of_next])
		end_of_next++;
	return (end_of_next - i);
}


char	**ft_split(char const *s, char c)
{
	char	**result;
	int		count;
	int		i;
	int		len;
	int		curr_word;

	count = count_words(s, c);
	// printf("Count of Words %d\n", count);
	
	// TODO TRIM STRING BEFORE
	result = malloc(sizeof(char *) * count + 1);
	i = 0;
	curr_word = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			len = length_of_next(i, s, c);
			// printf("\tLen of Word %d\n", len);
			result[curr_word++] = "";
			i += len;
		}
		else
			i++;
	}
	result[i] = '\0';
	return (result);
}
