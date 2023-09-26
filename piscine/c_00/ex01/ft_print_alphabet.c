/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 10:17:22 by jkhasiza          #+#    #+#             */
/*   Updated: 2023/05/25 10:54:52 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_alphabet(void)
{
	int	a;
	int	z;
	int	letter;

	a = 'a';
	z = 'z';
	letter = a;
	while (letter >= a && letter <= z)
	{
		write(1, &letter, 1);
		letter += 1;
	}	
}
