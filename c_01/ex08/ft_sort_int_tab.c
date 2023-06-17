/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 12:58:32 by jkhasiza          #+#    #+#             */
/*   Updated: 2023/05/30 17:50:25 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	a;
	int	b;
	int	pos_smallest;
	int	smallest;

	a = 0;
	while (a < size - 1)
	{
		b = a;
		smallest = tab[a];
		pos_smallest = a;
		while (b < size)
		{
			if (tab[b] <= smallest)
			{
				smallest = tab[b];
				pos_smallest = b;
			}
			b++;
		}
		if (pos_smallest != a)
			ft_swap(&tab[a], &tab[pos_smallest]);
		a++;
	}
}
