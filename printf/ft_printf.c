#include "./libft/libft.h"
#include "ft_printf.h"

int is_placeholder(char *str)
{
    char    *placeholders;

    placeholders = "scdpiuxX\%";
    if (str[0] == '%' && chr_in(str[1], placeholders))
        return (1);
    return (0);
}

void    dispatch(char type, void *arg)
{
    if (type == 's')
        ft_putstr_fd((char *) arg, 1);
    else if (type == 'c')
        ft_putchar_fd(*((char *) &arg), 1);
    else if (type == 'd' || type == 'i')
        ft_putnbr_fd(*((int *) &arg), 1);
}

int ft_printf(const char *input, ...)
{
    va_list args;
    int     i;
    void    *next_arg;

    va_start(args, input);
    i = 0;
    while (input[i])
    {
        if (is_placeholder((char *) &input[i]))
        {
            next_arg = va_arg(args, void *);
            dispatch(input[i + 1], next_arg);
            i+=2;
        }
        ft_putchar_fd(input[i], 1);
        i++;
    }
    va_end(args);
    return (0);
}

char    *strjoin_on_steroids(int n, ...)
{
    va_list list;
    char    *result;
    char    *prov;

    va_start(list, n);

    result = "";
    int i = 0;
    while (i < n)
    {
        prov = va_arg(list, char *);
        result = ft_strjoin(result, prov);
        if (result == NULL)
            return (NULL);
        i++;
    }
    va_end(list);
    return (result);
}