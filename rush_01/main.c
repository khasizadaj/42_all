/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkozmus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 19:48:10 by jkozmus           #+#    #+#             */
/*   Updated: 2023/06/04 21:42:42 by jkozmus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	base_array(char *arg, int *base);
int	validate_input(char *str);
int	write_input(int *base, int size);

int	error(void)
{
	write(1, "Error\n", 6);
	return (0);
}

int	main(int argc, char *argv[])
{
	int		base[100];
	int		size;
	char	*arg;

	arg = argv[1];
	if (argc != 2)
		return (error());
	if (validate_input(argv[1]) == 0)
		return (error());
	size = base_array(arg, base);
	if (size % 4 != 0)
		return (error());
	size = (size / 4) + 2;
	if (write_input(base, size) == 0)
		return (error());
}
