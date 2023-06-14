/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sample_header.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 22:51:50 by jkhasiza          #+#    #+#             */
/*   Updated: 2023/06/14 22:52:45 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SAMPLE_HEADER_H
# define HEADER_FILE

char	*open_and_read(char *file);
int		check_validity(char *str, t_conf *config);
void	memory_error(void);
void	map_error(void);
void	argument_error(void);
t_conf	init_config(void);
int		validate_config(t_conf *config);
t_conf	*set_config(char *map_as_str, t_conf *config);
void	ft_putstr(char *str);
t_sol	find_solution(char **map, t_conf conf);
int		compare_length(char *str, int lines_count);
int		count_lines(char *str);
char	*get_numbers_of_lines(char *map_as_str, int size);
void	print_map(char **map);
int		ft_strlen(char *str);
int		ft_strstr_pos(char *str, char *to_find);/* add your prototypes here */

#endif
