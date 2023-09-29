#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello %s hh %c n=%d\n", "Hey", 'z', -125);
    printf("i=%i\n", -124);
    return (0);
}