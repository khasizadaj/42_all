/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 12:02:51 by jkhasiza          #+#    #+#             */
/*   Updated: 2023/09/15 13:14:30 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n);;

int	main()
{
	char	*res_1;
	char	*to_be_copied;
	char	*exp_1;
	int		n;

	to_be_copied = "123456789012345";
	n = 10;
	exp_1 = malloc(sizeof(char) * n);
	res_1 = malloc(sizeof(char) * n);

	ft_memmove(res_1, to_be_copied, n);
	memmove(exp_1, to_be_copied, n);
	printf("\n>> \tEXP: '%s'\n\tRES: '%s'\n\n", exp_1, res_1);	
	return (0);
}