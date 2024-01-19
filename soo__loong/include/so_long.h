/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 20:37:41 by jkhasiza          #+#    #+#             */
/*   Updated: 2024/01/19 20:55:56 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../src/libft/libft.h"

# define MAP_EXTENSION ".ber"
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

void	exit_for(int reason);

#endif
