#include "ft_printf.h"

int main(void)
{
    int ret1, ret2;

    // %s flag
    ft_printf("Test: 's' Flag\n");
    ret1 = ft_printf("RES: Hello %s hh\n", "Hey");
    ret2 = printf("EXP: Hello %s hh\n", "Hey");
    if (ret1 == ret2) ft_printf("... PASS\n\n");
    else ft_printf("... FAIL\n\n");

    // %c flag
    ft_printf("Test: 'c' Flag\n");
    ret1 = ft_printf("RES: Character: %c\n", 'z');
    ret2 = printf("EXP: Character: %c\n", 'z');
    if (ret1 == ret2) ft_printf("... PASS\n\n");
    else ft_printf("... FAIL\n\n");

    // %d flag
    ft_printf("Test: 'd' Flag\n");
    ret1 = ft_printf("RES: Number: %d\n", -125);
    ret2 = printf("EXP: Number: %d\n", -125);
    if (ret1 == ret2) ft_printf("... PASS\n\n");
    else ft_printf("... FAIL\n\n");

    // %p flag
    ft_printf("Test: 'p' Flag\n");
    ret1 = ft_printf("RES: Pointer: %p\n", &"123");
    ret2 = printf("EXP: Pointer: %p\n", &"123");
    if (ret1 == ret2) ft_printf("... PASS\n\n");
    else ft_printf("... FAIL\n\n");

    // %i flag
    ft_printf("Test: 'i' Flag\n");
    ret1 = ft_printf("RES: Integer: %i\n", 12345);
    ret2 = printf("EXP: Integer: %i\n", 12345);
    if (ret1 == ret2) ft_printf("... PASS\n\n");
    else ft_printf("... FAIL\n\n");

    ft_printf("Test: 'i' Flag with Hex Input\n");
    ret1 = ft_printf("RES: Integer: %i\n", 0xABCDEF);
    ret2 = printf("EXP: Integer: %i\n", 0xABCDEF);
    if (ret1 == ret2) ft_printf("... PASS\n\n");
    else ft_printf("... FAIL\n\n");

    // %u flag
    ft_printf("Test: 'u' Flag\n");
    ret1 = ft_printf("RES: Unsigned: %u\n", 12345);
    ret2 = printf("EXP: Unsigned: %u\n", 12345);
    if (ret1 == ret2) ft_printf("... PASS\n\n");
    else ft_printf("... FAIL\n\n");

    // %x flag
    ft_printf("Test: 'x' Flag\n");
    ret1 = ft_printf("RES: Hex (lowercase): %x\n", 0xABCDEF);
    ret2 = printf("EXP: Hex (lowercase): %x\n", 0xABCDEF);
    if (ret1 == ret2) ft_printf("... PASS\n\n");
    else ft_printf("... FAIL\n\n");

    // %X flag
    ft_printf("Test: 'X' Flag\n");
    ret1 = ft_printf("RES: Hex (uppercase): %X\n", 0xABCDEF);
    ret2 = printf("EXP: Hex (uppercase): %X\n", 0xABCDEF);
    if (ret1 == ret2) ft_printf("... PASS\n\n");
    else ft_printf("... FAIL\n\n");

    ret1 = ft_printf("RES: Hex (uppercase): %X\n", 12345);
    ret2 = printf("EXP: Hex (uppercase): %X\n", 12345);
    if (ret1 == ret2) ft_printf("... PASS\n\n");
    else ft_printf("... FAIL\n\n");

    // %% flag
    ft_printf("Test: '%%' Flag\n");
    ret1 = ft_printf("RES: Percentage: %%\n");
    ret2 = printf("EXP: Percentage: %%\n");
    if (ret1 == ret2) ft_printf("... PASS\n\n");
    else ft_printf("... FAIL\n\n");

    // // NULL input
    // ft_printf("Test: NULL argument\n");
    // ret1 = ft_printf("RES: %x", NULL);
    // ret2 = printf("EXP: %x", NULL);
    // if (ret1 == ret2) ft_printf("... PASS\n\n");
    // else ft_printf("... FAIL\n\n");

    // ft_printf("Test: NULL formatted text\n");
    // ret1 = ft_printf(NULL, "x");
    // ret2 = printf(NULL, "x");
    // if (ret1 == ret2) ft_printf("... PASS\n\n");
    // else ft_printf("... FAIL\n\n");

    return 0;
}
