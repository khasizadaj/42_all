#include <stdio.h>
#include <unistd.h>

void	ft_putstr(char *str);

int	main(void)
{
	char *a = "HELLO";
	ft_putstr(a);
	printf("\n");

	char *b = "HEY  YYYY";
	ft_putstr(b);
	printf("\n");

	char *c = "1234578";
	ft_putstr(c);
	printf("\n");

	char *d = "123004";
	ft_putstr(d);
}
