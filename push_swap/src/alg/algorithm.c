/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 20:57:52 by jkhasiza          #+#    #+#             */
/*   Updated: 2023/12/20 23:11:09 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
#include <stdio.h>
#include <stdlib.h>

/* 

	STEP MAPPING

	- 0 : sa
	- 1 : sb
	- 2 : ss
	- 3 : ra
	- 4 : rb
	- 5 : rr
	- 6 : pa
	- 7 : pb
	- 8 : rra
	- 9 : rrb
	- 10 : rrr

	We'll represent potential steps to reach destination using
	array. Every spot refers to certain step and whenever that
	step is taken, spot value will be Updated to '1' from its
	initial value of '0'.

	steps = [0, 0, 0]
              1x sa                   1x ra   
	         [1, 1], [0, 0], [0, 0], [0, 0]]
			  1x pa          1x rra

	It would take 4 steps for given number to reach 
	its destination.

*/

void	get_steps_4_a(int lookup, int *steps, t_list *from)
{
	int size_a;

	size_a = ft_lstsize(from);
	if (lookup != 0 && lookup + 1 > size_a / 2 + 1)
		steps[8] = size_a - lookup;
	else if (lookup != 0)
		steps[3] = lookup;
}

void get_steps_4_b(lli val, int *steps, t_list *to)
{
	t_list	**tmp;
	int		i;

	i = 0;
	tmp = &to;
	while (*tmp) {
		if (!(*tmp)->next)
			break ;			
		if ((lli) (*tmp)->content > val)
			break ;
		i++;
		tmp = &((*tmp)->next);
	}
	if (val < (lli) ft_lstlast(to)->content)
		i = 0;
}

void get_steps(int lookup, lli val, int *steps, t_list *from, t_list *to)
{
	// MAYBE SWAP CAN HAPPEN IF AVERAGE IS SMALL
	get_steps_4_a(lookup, steps, from);
	get_steps_4_b(val, steps, to);

	printf("SIZE_A:\t%d\n", ft_lstsize(from));
	printf("SIZE_B:\t%d\n", ft_lstsize(to));
	printf("LOOKUP:\t%d\n", lookup);
	printf("ST[3]:\t%d\n", steps[3]);
	printf("ST[8]:\t%d\n", steps[8]);

}

void	reset_steps(int *steps)
{
	int	i;

	i = 0;
	while (i < 11) {
		steps[i] = 0; 
		i++;
	}
}

int *get_cheapest(t_list *from, t_list *to)
{
	int 	*steps;
	int		i;
	t_list	**tmp;

	if (!from || !to)
		return (NULL);
	steps = ft_calloc(11, sizeof(int));
	if (!steps)
		return (NULL);
	i = 0;
	tmp = &from;
	while(*tmp)
	{
		get_steps(i, (lli) (*tmp)->content, steps, from, to);
		tmp = &((*tmp)->next);
		reset_steps(steps);
		printf("\n=====\n\n");
		i++;
	}
	
	
	return steps;
}