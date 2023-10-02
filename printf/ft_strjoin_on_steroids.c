/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_on_steroids.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 21:33:38 by jkhasiza          #+#    #+#             */
/*   Updated: 2023/10/02 21:33:57 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char    *ft_strjoin_on_steroids(int n, ...)
{
	va_list list;
	char    *result;
	char    *prov;

	va_start(list, n);

	result = "";
	int i = 0;
	while (i < n)
	{
		prov = va_arg(list, char *);
		result = ft_strjoin(result, prov);
		if (result == NULL)
			return (NULL);
		i++;
	}
	va_end(list);
	return (result);
}