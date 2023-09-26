/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 15:47:53 by jkhasiza          #+#    #+#             */
/*   Updated: 2023/06/14 04:16:18 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	ft_strlen(char *str)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	while (str[i] != '\0')
	{
		i++;
		len++;
	}
	return (len);
}

int	base_is_valid(char *base)
{
	int	i;
	int	j;
	int	length;

	length = ft_strlen(base);
	if (length <= 1)
		return (0);
	i = -1;
	while (base[++i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[j] == base[i])
				return (0);
			j++;
		}
	}
	return (length);
}

void	convert_to_base(long long nbr, char *base, int base_size)
{
	int		curr;
	char	converted;
	int		remainder;

	if (nbr < base_size)
		write(1, &base[nbr], 1);
	else
	{
		curr = nbr / base_size;
		remainder = nbr % (curr * base_size);
		nbr = curr;
		convert_to_base(nbr, base, base_size);
		converted = base[remainder];
		write(1, &converted, 1);
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	int			base_size;
	long long	big_nbr;

	base_size = base_is_valid(base);
	big_nbr = nbr;
	if (base_size == 0)
		return ;
	if (big_nbr < 0)
	{
		write(1, "-", 1);
		big_nbr *= -1;
	}
	convert_to_base(big_nbr, base, base_size);
	return ;
}
