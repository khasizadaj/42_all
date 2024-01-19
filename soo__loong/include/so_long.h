/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 20:37:41 by jkhasiza          #+#    #+#             */
/*   Updated: 2024/01/19 23:19:35 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../src/libft/libft.h"
# include <mlx.h>

typedef struct s_data
{
	void	*mlx;
	void	*win;
	int		width;
	int		height;
}	t_data;

# define HEIGHT 600
# define WIDTH 600

# define WHITE 0xfafafa

# define MAP_EXTENSION ".ber"

# define MEMORY_ERR 9999
# define UNKNOWN_ERR 9998
# define INVALID_MAP_NO_MAP 2000
# define INVALID_MAP_MSG_NO_MAP "Error\n -- Map is not provided."
# define INVALID_MAP_WRONG_FILE_TYPE 2001
# define INVALID_MAP_MSG_WRONG_FILE_TYPE "Error\n -- Map file type is invalid."
# define INVALID_MAP_NOT_RECTANGLE 2002
# define INVALID_MAP_MSG_NOT_RECTANGLE "Error\n -- Map is not rectangular."
# define INVALID_MAP_WRONG_WALLS 2003
# define INVALID_MAP_MSG_WRONG_WALLS "Error\n -- Map is not enclosed by walls."
# define INVALID_MAP_NO_VALID_PATH 2004
# define INVALID_MAP_MSG_NO_VALID_PATH "Error\n -- Map has no valid path."

t_bool	draw_board_border(t_data *data, int padding, int border_width);

/* UTILS */
void	exit_for(int reason);

#endif
