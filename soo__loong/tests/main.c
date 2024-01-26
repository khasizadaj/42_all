/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 22:07:02 by jkhasiza          #+#    #+#             */
/*   Updated: 2024/01/26 22:42:40 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../libunit/include/libunit.h"
# include "map_validation/map_validation.h"

int	main(void)
{
	t_passed	res;

	res.passed = 0;
	res.total = 0;
	map_validation_launcher(&res);
	if (res.total == 0)
		return (ft_printf("No tests were launched\n"), 0);
	ft_printf("\n%d/%d tests checked\n", res.passed, res.total);
	if (res.passed == res.total)
		return (OK);
	return (KO);
}