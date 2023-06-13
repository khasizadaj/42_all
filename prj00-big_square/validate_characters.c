/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 12:54:27 by jkhasiza          #+#    #+#             */
/*   Updated: 2023/06/13 14:01:53 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_numeric(char *str)
{
	int	i;
	int	is_numeric;

	is_numeric = 1;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
		{	
			is_numeric = 0;
			break ;
		}
		i++;
	}
	return (is_numeric);
}

int	ft_char_is_printable(char c)
{
	int	printable_start;
	int	printable_end;

	printable_start = 32;
	printable_end = 126;
	if (c < printable_start || c > printable_end)
	{
		return (0);
	}
	return (1);
}
