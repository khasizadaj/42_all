/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 15:49:09 by jkhasiza          #+#    #+#             */
/*   Updated: 2023/06/01 21:02:03 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_other(char *str)
{
	int	is_other;

	is_other = 0;
	if (!((*str >= 'a' && *str <= 'z')
			|| (*str >= 'A' && *str <= 'Z')
			|| (*str >= '0' && *str <= '9')))
	{	
		is_other = 1;
	}
	return (is_other);
}

void	handle_first(char *str)
{
	if (*str >= 'a' && *str <= 'z')
	{
		*str = *str - 32;
	}
}

void	capitalize(char *str)
{
	if (*str >= 'a' && *str <= 'z')
	{
		*str = *str - 32;
	}
}

void	decapitate(char *str)
{
	if (*str >= 'A' && *str <= 'Z')
	{
		*str = *str + 32;
	}
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	handle_first(&str[0]);
	i = 1;
	while (str[i] != '\0')
	{
		if (ft_str_is_other(&str[i - 1]) == 1)
		{
			capitalize(&str[i]);
		}
		else
		{
			decapitate(&str[i]);
		}
		i++;
	}
	return (str);
}
