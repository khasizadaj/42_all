#include <stdio.h>
#include <ctype.h>
#include "libft.h"

void	run_test(char *res, char *exp)
{
	printf("RES: '%s'\n", res);
	printf("EXP: '%s'\n", exp);
	if (ft_strncmp(res, exp, 4) == 0)
		printf("\n>> PASS: All good!\n\n");
	else
		printf("\n>> FAIL: Not good || \n\tEXP: '%s'; \n\tRES: '%s'\n\n", exp, res);	
	return ;
}

char	custom_to_upper(unsigned int i, char ch)
{
	printf("CHR:\t%c, I:\t%d\n", ch, i);

	return ((char) ft_toupper(ch));
}

int	main()
{
	char	*str_1;
	char	*exp_1;
	char	*res_1;

	str_1 = "hello";
	exp_1 = "HELLO";
	res_1 = ft_strmapi(str_1, &custom_to_upper);
	run_test(res_1, exp_1);

	char	*str_2;
	char	*exp_2;
	char	*res_2;

	str_2 = "aBied";
	exp_2 = "ABIED";
	res_2 = ft_strmapi(str_2, &custom_to_upper);
	run_test(res_2, exp_2);
}
