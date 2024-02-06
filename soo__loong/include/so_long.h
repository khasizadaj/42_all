/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 20:37:41 by jkhasiza          #+#    #+#             */
/*   Updated: 2024/02/06 20:25:34 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../src/libft/libft.h"
# include <stdbool.h>
# include <mlx.h>
# include <sys/time.h>

typedef struct s_tile
{
	void			*img;
	int				state;
	char			type;
	struct s_tile	*next;
	int				id;
}	t_tile;

typedef struct s_assets
{
	void	*exit;
	void	*player;
	void	*floor;
	void	*coin;
	void	*wall;
}	t_assets;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	int		width;
	int		height;
	int		side_length;
	int		player_pos;
	int		exit;
	int		exit_code;
	int		x_count;
	int		y_count;
	int		collected;
	int		total_coins;
	int		move_count;
	time_t	start;
	t_tile	*assets;
	t_tile	*tile;
}	t_data;

/* ************************************************************************** */
/*                                                                            */
/*	    ASSETS                                                                */
/*                                                                            */
/* ************************************************************************** */
# define A_PLAYER_R "assets/player-right.xpm"
# define A_PLAYER_L "assets/player-left.xpm"
# define A_EXIT "assets/exit.xpm"
# define A_FLOOR "assets/floor.xpm"
# define A_COIN_L "assets/collectable-1.xpm"
# define A_COIN_R "assets/collectable-1-flip.xpm"
# define A_WALL_O "assets/wall-inside.xpm"

# define A_WALL_L "assets/wall-left.xpm"
# define A_WALL_R "assets/wall-right.xpm"
# define A_WALL_T "assets/wall-top.xpm"
# define A_WALL_B "assets/wall-bottom.xpm"
# define A_WALL_BL "assets/wall-bottom-left.xpm"
# define A_WALL_BR "assets/wall-bottom-right.xpm"
# define A_WALL_TL "assets/wall-top-left.xpm"
# define A_WALL_TR "assets/wall-top-right.xpm"
# define A_BOMB "assets/bomb.xpm"
# define A_DIAMOND "assets/diamond.xpm"
# define A_VILLAIN_R "assets/villain-right.xpm"
# define A_VILLAIN_L "assets/villain-right.xpm"

t_tile	*asset_factory(t_data *data, char type);
void	*asset_get_by_type(t_tile **assets, char type);
char	*asset_path_factory(char type);
bool	init_assets(t_data *data);

# define KEY_RELEASE 3
# define KEY_RELEASE_MASK 1L

/* ************************************************************************** */
/*                                                                            */
/*	    KEYBOARD MACROS                                                       */
/*                                                                            */
/* ************************************************************************** */
# define K_UP			119
# define K_DOWN			115
# define K_LEFT			97
# define K_RIGHT		100
# define K_ARR_UP		65362
# define K_ARR_DOWN		65364
# define K_ARR_LEFT		65361
# define K_ARR_RIGHT	65363
# define K_ESC			65307

# define HEIGHT 600
# define WIDTH 600
# define SIDE_LEN 72

# define WHITE 0xfafafa

# define PROGRAM_NAME "DND"
# define MAP_EXTENSION ".ber"

# define END_GAME 0
# define PROGRAM_HALTED_WITH_ESCAPE 300
# define PROGRAM_HALTED_MSG_WITH_ESCAPE "Escaped this hell!\n"
# define MEMORY_ERR 9999
# define MEMORY_ERR_MSG "Error\n -- Memory allocation failed.\n"
# define SCREEN_SIZE_ERR 1001
# define SCREEN_SIZE_MSG "Error\n -- Cannot generate this map because of screen size limit.\n"
# define UNKNOWN_ERR 9998
# define INVALID_MAP 2005
# define INVALID_MAP_MSG "Error\n -- Map is invalid.\n"
# define INVALID_MAP_INCORRECT_COMPONENT 2000
# define INVALID_MAP_MSG_INCORRECT_COMPONENT "Error\n -- Incorrect component.\n"
# define INVALID_MAP_NO_MAP 2000
# define INVALID_MAP_MSG_NO_MAP "Error\n -- Map is not provided.\n"
# define INVALID_MAP_WRONG_FILE_TYPE 2001
# define INVALID_MAP_MSG_WRONG_FILE_TYPE "Error\n -- Map file type is invalid.\n"
# define INVALID_MAP_NOT_RECTANGLE 2002
# define INVALID_MAP_MSG_NOT_RECTANGLE "Error\n -- Map is not rectangular.\n"
# define INVALID_MAP_WRONG_WALLS 2003
# define INVALID_MAP_MSG_WRONG_WALLS "Error\n -- Map is not enclosed by walls.\n"
# define INVALID_MAP_NO_VALID_PATH 2004
# define INVALID_MAP_MSG_NO_VALID_PATH "Error\n -- Map has no valid path.\n"

t_bool	draw_board_border(t_data *data, int padding, int border_width);

/* ************************************************************************** */
/*                                                                            */
/*	    UTILS                                                                 */
/*                                                                            */
/* ************************************************************************** */
void		exit_for(int reason);
void		exit_gracefully(t_data *data, int reason);
t_tile		*draw(t_data *data, int x, int y, char type);
t_tile		*draw_tile(t_data *data, int x, int y, char type);
t_tile		*draw_exit(t_data *data, int x, int y);
void		tile_add_back(t_tile **tile_list, t_tile *new_tile);
t_tile		*tile_new(t_data *data, char type, t_bool is_loaded);
t_tile		*tile_get(t_tile **tile, int index);
void		*tile_get_by_type(t_tile **tile, char type);
void		move(t_data *data, int keycode);
void		free_get_next_line(int fd, char **line);
int			get_x(int position, int x_tile_count);
int			get_y(int position, int x_tile_count);
int			animate(t_data *data);
long long	time_in_milliseconds(void);
void		init_data(t_data *data);
void		enhance_data(t_data *data, char *map_str);

/* ************************************************************************** */
/*                                                                            */
/*	    MLX HOOKS                                                             */
/*                                                                            */
/* ************************************************************************** */
int		key_hook(int keycode, t_data *data);
void	add_hooks(t_data *data);

/* ************************************************************************** */
/*                                                                            */
/*	    CLEANER FUNCS                                                         */
/*                                                                            */
/* ************************************************************************** */
void	free_tile(t_data *data);
void	free_assets(t_data *data);

#define MAP_LVL_1 "111111C0P11C0E111111"
#define MAP_LVL_2 "111111111C000P111C000011100000C11C000E111C00001111111111"


/* ************************************************************************** */
/*                                                                            */
/*	    MAP VALIDATION                                                        */
/*                                                                            */
/* ************************************************************************** */
char	*get_map(t_data *data, char *filename, int *x_tile_count,
					int *y_tile_count);
void	init_map(t_data *data, char *map_str);
int		is_valid_line(char *line, int expected_size);
int		is_valid_map(t_data *data, char *map);
bool	has_valid_path(t_data *data, char *map);

# define ALLOWED_CHARACTERS "1E0CP"

#endif
