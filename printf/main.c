#include "ft_printf.h"


int main(void)
{
    // // %s flag
    // ft_printf("Test: 's' Flag\n");
    // ft_printf("RES: Hello %s hh\n", "Hey");
    // printf("EXP: Hello %s hh\n", "Hey");
    // ft_printf("... PASS\n\n");
    
    // // %c flag
    // ft_printf("Test: 'c' Flag\n");
    // ft_printf("RES: Character: %c\n", 'z');
    // printf("EXP: Character: %c\n", 'z');
    // ft_printf("... PASS\n\n");

    // // %d flag
    // ft_printf("Test: 'd' Flag\n");
    // ft_printf("RES: Number: %d\n", -125);
    // printf("EXP: Number: %d\n", -125);
    // ft_printf("... PASS\n\n");

    // // %p flag
    // ft_printf("Test: 'p' Flag\n");
    // ft_printf("RES: Pointer: %p\n", &"123");
    // printf("EXP: Pointer: %p\n", &"123");
    // ft_printf("... PASS\n\n");

    // // %i flag
    // ft_printf("Test: 'i' Flag\n");
    // ft_printf("RES: Integer: %i\n", 12345);
    // printf("EXP: Integer: %i\n", 12345);
    // ft_printf("... PASS\n\n");

    // // %s flag
    // ft_printf("Test: just percentage sign with flag\n");
    // ft_printf("RES: Hello \%s hh\n", "Hey");
    // printf("EXP: Hello \%s hh\n", "Hey");
    // ft_printf("... PASS\n\n");

    // // %u flag
    // ft_printf("Test: 'u' Flag\n");
    // ft_printf("RES: Unsigned: %u\n", 12345);
    // printf("EXP: Unsigned: %u\n", 12345);
    // ft_printf("--- PASS\n\n");

    // %x flag
    ft_printf("Test: 'x' Flag\n");
    ft_printf("RES: Hex (lowercase): %x\n", 0xABCDEF);
    printf("EXP: Hex (lowercase): %x\n", 0xABCDEF);

    // %X flag
    ft_printf("Test: 'X' Flag\n");
    ft_printf("RES: Hex (uppercase): %X\n", 0xABCDEF);
    printf("EXP: Hex (uppercase): %X\n", 0xABCDEF);

    // %% flag
    ft_printf("Test: '%' Flag\n");
    ft_printf("RES: Percentage: %%\n");
    printf("EXP: Percentage: %%\n");


    return 0;
}
