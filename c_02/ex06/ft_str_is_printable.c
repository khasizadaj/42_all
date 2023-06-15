/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 14:19:00 by jkhasiza          #+#    #+#             */
/*   Updated: 2023/06/01 15:15:19 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str)
{
	int	i;
	int	printable_start;
	int	printable_end;
	int	is_printable;

	is_printable = 1;
	printable_start = 32;
	printable_end = 126;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < printable_start || str[i] > printable_end)
		{
			is_printable = 0;
			break ;
		}
		i++;
	}
	return (is_printable);
}
