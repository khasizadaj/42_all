/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 00:23:51 by jkhasiza          #+#    #+#             */
/*   Updated: 2023/06/15 11:42:21 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_swap_elements(char **argv, int a, int b)
{
	char	*temp;

	temp = argv[a];
	argv[a] = argv[b];
	argv[b] = temp;
}

int	ft_strlen(char *str)
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

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

void	print_params(int argc, char **argv)
{
	int	i;

	i = 0;
	while (++i < argc)
	{
		write(1, argv[i], ft_strlen(argv[i]));
		write(1, "\n", 1);
	}
}

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	j = argc;
	while (--j > 0)
	{
		i = 0;
		while (++i < argc - 1 && i < j)
		{
			if (ft_strcmp(argv[i], argv[i + 1]) > 0)
			{
				ft_swap_elements(argv, i, i + 1);
			}
		}
	}
	print_params(argc, argv);
}
