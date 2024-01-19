/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 20:30:10 by jkhasiza          #+#    #+#             */
/*   Updated: 2024/01/19 20:56:27 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "libft/libft.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
		exit_for(INVALID_MAP_NO_MAP);
	if (!ft_str_endswith(argv[1], MAP_EXTENSION))
		exit_for(INVALID_MAP_WRONG_FILE_TYPE);
	ft_printf("ALL GOOHUDEE");
	return (1);
}
