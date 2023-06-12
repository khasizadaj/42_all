/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juitz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 17:28:42 by juitz             #+#    #+#             */
/*   Updated: 2023/06/04 17:29:48 by juitz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	base_array(char *str, int *base)
{
	int	i;
	int	k;
	int	tmp;

	k = 0;
	i = 0;
	while (str[i])
	{
		if ('0' <= str[i] && str[i] <= '9')
		{	
			tmp = str[i];
			base[k] = (tmp - 48);
			k++;
		}
		i++;
	}
	base[k] = '\0';
	return (k);
}
