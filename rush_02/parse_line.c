/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 20:42:19 by jkhasiza          #+#    #+#             */
/*   Updated: 2023/06/11 22:29:52 by mmarta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char	*ft_strstr(char *str, char *to_find);
int		is_space(char c);
char	*ft_reallocate(char *old, int old_size, int new_size);

char	*get_word(char *str)
{	
	char	*dirty_word;
	char	*clean_word;
	int		i;
	int		j;
	int		is_writable;

	dirty_word = ft_strstr(str, ":");
	i = 1;
	j = 0;
	is_writable = 0;
	clean_word = malloc(sizeof(char) * 20);
	while (dirty_word[i] != '\0')
	{
		if (is_space(dirty_word[i]) == 0 || is_writable == 1)
		{
			is_writable = 1;
			clean_word[j] = dirty_word[i];
			j++;
		}
		i++;
		if (i % 20 == 0)
			clean_word = ft_reallocate(clean_word, i, i + 20);
	}
	clean_word[j] = '\0';
	return (clean_word);
}
