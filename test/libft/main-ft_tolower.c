#include <stdio.h>
#include <ctype.h>
#include "libft.h"

void	run_test(int ch, int exp)
{
	int	res;

	printf("INT rep of CH: '%d', ('%c')\n", ch, ch);
	printf("EXP: '%d' ('%c')\n", exp, exp);
	res = ft_tolower(ch);
	if (exp == res)
		printf("\n>> PASS: All good!\n\n");
	else
		printf("\n>> FAIL: Not good || \n\tEXP: '%c'; \n\tRES: '%c'\n\n", exp, res);	
	return ;
}

int	main()
{
	printf("TOLOWER\n\n");

	int	ch_1;
	int	exp_1;

	ch_1 = 'a';
	exp_1 = tolower(ch_1);
	run_test(ch_1, exp_1);

	int ch_2;
	int exp_2;

	ch_2 = '/';
	exp_2 = tolower(ch_2);
	run_test(ch_2, exp_2);

	int	ch_3;
	int	exp_3;

	ch_3 = 'Z';
	exp_3 = tolower(ch_3);
	run_test(ch_3, exp_3);

	int	ch_4;
	int	exp_4;

	ch_4 = 'M';
	exp_4 = tolower(ch_4);
	run_test(ch_4, exp_4);
}
