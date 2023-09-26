/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main-ft_lstsize.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 16:53:14 by codespace         #+#    #+#             */
/*   Updated: 2023/09/22 17:01:23 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	main(void)
{
	t_list	*list_1;
	t_list	*list_2;
	t_list	*list_3;
	t_list	*list_4;
	int		size;

	list_1 = ft_lstnew("L1");
	list_2 = ft_lstnew("L2");
	list_3 = ft_lstnew("L3");
	list_4 = ft_lstnew("L4");

	list_1->next = list_2;
	list_2->next = list_3;

	size = ft_lstsize(list_1);
	printf("Size: %d [EXP: 3]\n", size);

	list_3->next = list_4;
	size = ft_lstsize(list_1);
	printf("Size: %d [EXP: 4]\n", size);

	return (0);
}