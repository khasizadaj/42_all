/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 20:12:12 by mmarta            #+#    #+#             */
/*   Updated: 2023/06/12 13:18:22 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

char	**get_dict(char *dict_name, int count);
char	*get_word(char *str);
int		open_and_count(char *dict_name);
int		ft_atoi(char *str);
int		ft_strcmp(char *s1, char *s2);
int		main_block(int number);
int		get_building_blocks(int number, int *blocks);
int		validate_input(int argc, char *argv[]);
int		ft_strlen(char *str);
int		open_and_count_valid_lines(char *dict_name);
void	free_dict(char **dict, int count);

char	*get_line(char **dict, int number, int count)
{
	int		i;
	char	*line;
	int		curr;

	i = 0;
	while (i < count)
	{
		line = dict[i];
		curr = ft_atoi(line);
		if (curr == number)
			return (get_word(line));
		i++;
	}
	return ("");
}

void	print_number(char **dict, int *blocks, int count)
{
	int		i;
	char	*line;
	int		add_spaces;

	i = 0;
	add_spaces = 0;
	while (i < 16)
	{
		if (blocks[i] != -1)
		{
			if (add_spaces == 1)
				write(1, " ", 1);
			else
				add_spaces = 1;
			line = get_line(dict, blocks[i], count);
			write(1, line, ft_strlen(line));
			free(line);
		}
		i++;
	}
	write(1, "\n", 1);
}

int	write_errors(int type)
{
	if (type == 1)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	else if (type == 2)
	{
		write(1, "Dict Error\n", 11);
		return (0);
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	int				blocks[16];
	unsigned int	number;
	char			**dict;
	char			*dict_name;
	int				lines_count;

	dict_name = "numbers.dict";
	if (validate_input(argc, argv) == 1)
	{
		number = ft_atoi(argv[argc - 1]);
		if (argc == 3)
			dict_name = argv[1];
	}
	else
		return (write_errors(1));
	lines_count = open_and_count(dict_name);
	if (open_and_count_valid_lines(dict_name) < 32)
		return (write_errors(2));
	get_building_blocks(number, blocks);
	dict = get_dict(dict_name, lines_count);
	print_number(dict, blocks, lines_count);
	free_dict(dict, lines_count);
	return (1);
}
