#include <stdio.h>
#include <unistd.h>

int	ft_strlen(char *str);

int	main(void)
{
	char *a = "HELLO";
	int len;
	len = ft_strlen(a);
	printf("Word:\t%s\n", a);
	printf("EXP:\t%d\n", 5);
	printf("ACT:\t%d\n", len);

	printf("\n");

	char *b = "'lovin it!";
	len = ft_strlen(b);
	printf("Word:\t%s\n", b);
	printf("EXP:\t%d\n", 10);
	printf("ACT:\t%d\n", len);

	printf("\n");

	char *c = "0";
	len = ft_strlen(c);
	printf("Word:\t%s\n", c);
	printf("EXP:\t%d\n", 1);
	printf("ACT:\t%d\n", len);

	printf("\n");

	char *x = "";
	len = ft_strlen(x);
	printf("Word:\t%s\n", x);
	printf("EXP:\t%d\n", 0);
	printf("ACT:\t%d\n", len);
}
