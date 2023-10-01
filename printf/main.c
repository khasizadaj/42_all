#include "ft_printf.h"

int main(void)
{
    int ret1, ret2;

    // // %s flag
    // ft_printf("Test: 's' Flag\n");
    // ret1 = ft_printf("RES: Hello %s hh\n", "Hey");
    // ret2 = printf("EXP: Hello %s hh\n", "Hey");
    // if (ret1 == ret2) ft_printf("... PASS\n\n");
    // else ft_printf("... FAIL\n\n");

    // ret1 = ft_printf("RES: Hello %s hh\n", NULL);
    // ret2 = printf("EXP: Hello %s hh\n", NULL);
    // if (ret1 == ret2) ft_printf("... PASS\n\n");
    // else ft_printf("... FAIL\n\n");

    // %c flag
    // ft_printf("Test: 'c' Flag\n");
    // ret1 = ft_printf(" %c %c %c ", '0', 0, '1');
    // ret2 = printf(" %c %c %c ", '0', 0, '1');
    // if (ret1 == ret2) ft_printf("... PASS\n\n");
    // else ft_printf("... FAIL\n\n");

    // ret1 = ft_printf(" %c ", '0');
    // ret2 = printf(" %c ", '0');
    // if (ret1 == ret2) ft_printf("... PASS\n\n");
    // else ft_printf("... FAIL\n\n");

    // // %d flag
    // ft_printf("Test: 'd' Flag\n");
    // ret1 = ft_printf("RES: Number: %d\n", 0);
    // ret2 = printf("EXP: Number: %d\n", 0);
    // if (ret1 == ret2) ft_printf("... PASS\n\n");
    // else ft_printf("... FAIL\n\n");

    // // %p flag
    // ft_printf("Test: 'p' Flag\n");
	// int n = 0;
    // ret1 = ft_printf("RES: Pointer: %p\n", 0);
    // ret2 = printf("EXP: Pointer: %p\n", 0);
    // if (ret1 == ret2) ft_printf("... PASS\n\n");
    // else ft_printf("... FAIL\n\n");

    // // %i flag
    // ft_printf("Test: 'i' Flag\n");
    // ret1 = ft_printf("RES: Integer: %i\n", 9223372036854775807LL);
    // ret2 = printf("EXP: Integer: %i\n", 9223372036854775807LL);
	// printf("%d - %d\n", ret1, ret2);
    // if (ret1 == ret2) ft_printf("... PASS\n\n");
    // else ft_printf("... FAIL\n\n");

    // ft_printf("Test: 'i' Flag with Hex Input\n");
    // ret1 = ft_printf("RES: Integer: %i\n", 0xABCDEF);
    // ret2 = printf("EXP: Integer: %i\n", 0xABCDEF);
    // if (ret1 == ret2) ft_printf("... PASS\n\n");
    // else ft_printf("... FAIL\n\n");

    // // %u flag
    // ft_printf("Test: 'u' Flag\n");
    // ret1 = ft_printf("RES: Unsigned: %u\n", 12345);
    // ret2 = printf("EXP: Unsigned: %u\n", 12345);
    // if (ret1 == ret2) ft_printf("... PASS\n\n");
    // else ft_printf("... FAIL\n\n");

    // %x flag
    ft_printf("Test: 'x' Flag\n");
    ret1 = ft_printf("RES: Hex (lowercase): %x\n", 0);
    ret2 = printf("EXP: Hex (lowercase): %x\n", 0);
    if (ret1 == ret2) ft_printf("... PASS\n\n");
    else ft_printf("... FAIL\n\n");

    // // %X flag
    // ft_printf("Test: 'X' Flag\n");
    // ret1 = ft_printf("RES: Hex (uppercase): %X\n", 0xABCDEF);
    // ret2 = printf("EXP: Hex (uppercase): %X\n", 0xABCDEF);
    // if (ret1 == ret2) ft_printf("... PASS\n\n");
    // else ft_printf("... FAIL\n\n");

    // ret1 = ft_printf("RES: Hex (uppercase): %X\n", 0xabc12);
    // ret2 = printf("EXP: Hex (uppercase): %X\n", 0xabc12);
    // if (ret1 == ret2) ft_printf("... PASS\n\n");
    // else ft_printf("... FAIL\n\n");

    // // %% flag
    // ft_printf("Test: '%%' Flag\n");
    // ret1 = ft_printf("RES: Percentage: %%\n");
    // ret2 = printf("EXP: Percentage: %%\n");
    // if (ret1 == ret2) ft_printf("... PASS\n\n");
    // else ft_printf("... FAIL\n\n");

    // // NULL input
    // ft_printf("Test: NULL argument\n");
    // ret1 = ft_printf("RES: %x", NULL);
    // ret2 = printf("EXP: %x", NULL);
    // if (ret1 == ret2) ft_printf("... PASS\n\n");
    // else ft_printf("... FAIL\n\n");

    // ret1 = ft_printf("RES: %x", NULL);
    // ret2 = printf("EXP: Hello %");
    // if (ret1 == ret2) ft_printf("... PASS\n\n");
    // else ft_printf("... FAIL\n\n");

    return 0;
}
