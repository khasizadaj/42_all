#include <stdio.h>
#include <ctype.h>

int	ft_isalpha(char c);

void	run_test(char ch, int exp)
{
	int	res;

	printf("CHAR: '%c'\n", ch);
	printf("EXP: '%d'\n", exp);
	res = ft_isalpha(ch);
	if ((res == 0 && exp == 0) || (res > 0 && exp > 0))
		printf("\n>> PASS: All good!\n\n");
	else
		printf("\n>> FAIL: Not good || \n\tEXP: '%d'; \n\tRES: '%d'\n\n", exp, res);	
	return ;
}

int	main(int argc, char const *argv[])
{
	char	ch_1;
	int		exp_1;

	ch_1 = 'a';
	exp_1 = isalpha(ch_1);
	run_test(ch_1, exp_1);

    char ch_2;
	int exp_2;

	ch_2 = '1';
	exp_2 = isalpha(ch_2);
	run_test(ch_2, exp_2);

	return (0);

    char ch_3;
	int exp_3;

	ch_3 = '/';
	exp_3 = isalpha(ch_3);
	run_test(ch_3, exp_3);

	return (0);
}
