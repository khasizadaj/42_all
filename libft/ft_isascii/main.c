:#include <stdio.h>
#include <ctype.h>

int	ft_isascii(int c);

void	run_test(int ch, int exp)
{
	int	res;

	printf("INT rep of CH: '%d'\n", ch);
	printf("EXP: '%d'\n", exp);
	res = ft_isascii(ch);
	if ((res == 0 && exp == 0) || (res > 0 && exp > 0))
		printf("\n>> PASS: All good!\n\n");
	else
		printf("\n>> FAIL: Not good || \n\tEXP: '%d'; \n\tRES: '%d'\n\n", exp, res);	
	return ;
}

int	main()
{
	int	ch_1;
	int	exp_1;

	ch_1 = '0';
	exp_1 = isascii(ch_1);
	run_test(ch_1, exp_1);

	int ch_2;
	int exp_2;

	ch_2 = 200;
	exp_2 = isascii(ch_2);
	run_test(ch_2, exp_2);

	int	ch_3;
	int	exp_3;

	ch_3 = '/';
	exp_3 = isascii(ch_3);
	run_test(ch_3, exp_3);
}
