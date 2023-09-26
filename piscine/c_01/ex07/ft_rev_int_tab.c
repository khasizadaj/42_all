/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 12:54:19 by jkhasiza          #+#    #+#             */
/*   Updated: 2023/06/01 11:53:03 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	temp;
	int	max_index;
	int	mirrored_index;

	max_index = size - 1;
	i = 0;
	while (i <= max_index / 2)
	{
		mirrored_index = max_index - i;
		temp = tab[i];
		tab[i] = tab[mirrored_index];
		tab[mirrored_index] = temp;
		i++;
	}	
}
