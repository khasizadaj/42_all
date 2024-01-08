/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 13:55:56 by jkhasiza          #+#    #+#             */
/*   Updated: 2023/06/13 20:16:03 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	memory_error(void)
{
	write(2, "memory error\n", 12);
	exit(0);
}

void	map_error(void)
{
	write(1, "map error\n", 10);
	exit(0);
}

void	argument_error(void)
{
	write(1, "argument error\n", 15);
	exit(0);
}
