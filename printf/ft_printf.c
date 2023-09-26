#include "./libft/libft.h"

int ft_printf(const char *str)
{
    printf("Hello World!!!\n");
    printf("%s", str);
    ft_putchar_fd('n', 1);
    ft_putchar_fd('\n', 1);
    ft_putchar_fd('\n', 1);
    return (1);
}