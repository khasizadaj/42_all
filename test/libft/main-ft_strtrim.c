#include <stdlib.h>
#include <stdio.h>

char	*ft_strtrim(char const *s1, char const *set);

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	if (i < n)
		return (s1[i] - s2[i]);
	return (0);
}

void	run_test(char const *str, char const *set, char *exp)
{
	char	*res;

	printf("STR: '%s'\n", str);
	printf("SET: '%s'\n", set);
	printf("EXP: '%s'\n", exp);
	res = ft_strtrim(str, set);
	if (ft_strncmp(exp, res, sizeof(exp)) == 0)
		printf("\n>> PASS: All good!\n\n");
	else
		printf("\n>> FAIL: Not good || \n\tEXP: '%s'; \n\tRES: '%s'\n\n", exp, res);	
	return ;
}

int	main(int argc, char const *argv[])
{
	char const	*str_1;
	char const	*set_1;
	char		*exp_1;

	str_1 = "  121  1111112";
	set_1 = " 1";
	exp_1 = "21  1111112";
	run_test(str_1, set_1, exp_1);

	char const	*str_2;
	char const	*set_2;
	char		*exp_2;

	str_2 = " 121  a a";
	set_2 = " 1a";
	exp_2 = "2";
	run_test(str_2, set_2, exp_2);

	char const	*str_3;
	char const	*set_3;
	char		*exp_3;

	str_3 = "";
	set_3 = " 1a";
	exp_3 = "";
	run_test(str_3, set_3, exp_3);
}
