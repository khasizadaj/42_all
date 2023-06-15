 #include <stdio.h>

void	ft_putnbr(int nb);
void	check_edge_cases(int *nb);

int	main(void)
{
	ft_putnbr(2000);
	printf("\n");
	ft_putnbr(200);
	printf("\n");
	ft_putnbr(207);
	printf("\n");
	ft_putnbr(20);
	printf("\n");
	ft_putnbr(1234);
	printf("\n");
	ft_putnbr(9);
	printf("\n");
	ft_putnbr(-2147483648);
}
