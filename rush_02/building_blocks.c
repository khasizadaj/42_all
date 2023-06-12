/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   building_blocks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 20:11:40 by mmarta            #+#    #+#             */
/*   Updated: 2023/06/10 23:06:50 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	main_block(int number, int *blocks, int start)
{
	int	hndred;
	int	ten;

	hndred = number / 100;
	if (hndred > 0)
	{
		blocks[start] = hndred;
		blocks[start + 1] = 100;
	}
	ten = (number % 100);
	if (ten >= 10 && ten < 20)
	{
		blocks[start + 2] = ten;
	}
	else if (ten >= 20)
	{
		blocks[start + 2] = (ten / 10) * 10;
		if (ten % 10 != 0)
			blocks[start + 3] = ten % 10;
	}
	else if (ten > 0 && ten < 10)
	{
		blocks[start + 3] = ten % 10;
	}
	return (0);
}

int	thousands(int number, int *blocks)
{
	int	thousand;

	thousand = number / 1000;
	main_block(thousand, blocks, 7);
	if (thousand > 0)
		blocks[11] = 1000;
	main_block(number % 1000, blocks, 12);
	return (0);
}

int	millions(int number, int *blocks)
{
	int	million;

	million = number / 1000000;
	main_block(million, blocks, 2);
	if (million > 0)
		blocks[6] = 1000000;
	thousands(number % 1000000, blocks);
	return (0);
}

void	init_blocks(int *blocks)
{
	int	i;
	int	size;

	i = 0;
	size = 16;
	while (i < size)
	{
		blocks[i] = -1;
		i++;
	}
}

int	*get_building_blocks(unsigned int number, int *blocks)
{
	unsigned int	billion;
	unsigned int	the_rest;

	init_blocks(blocks);
	if (number == 0)
	{
		blocks[15] = 0;
		return (blocks);
	}
	billion = number / 1000000000;
	if (billion > 0)
	{
		blocks[0] = billion;
		blocks[1] = 1000000000;
	}
	the_rest = number % 1000000000;
	millions(the_rest, blocks);
	return (blocks);
}
