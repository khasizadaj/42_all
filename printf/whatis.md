# Custom printf baby!

Write a library that contains `ft_printf()`, a function that will mimic the original `printf()`.

## Requirements

- [ ] `Makefile` to compile
    - Include `NAME`, `all`, `clean`, `fclean`, `re`
- [ ] `libftprintf.a` (at the root folder of the repository) 
- [ ] %c Prints a single character.
- [ ] %s Prints a string (as defined by the common C convention).
- [ ] %p The void * pointer argument has to be printed in hexadecimal format.
- [ ] %d Prints a decimal (base 10) number.
- [ ] %i Prints an integer in base 10.
- [ ] %u Prints an unsigned decimal (base 10) number.
- [ ] %x Prints a number in hexadecimal (base 16) lowercase format.
- [ ] %X Prints a number in hexadecimal (base 16) uppercase format.
- [ ] %% Prints a percent sign.

- Notes:
    - `libft` can be used.
    - Allowed functions:
        - `malloc`
        - `free`
        - `write`
        - `va_start`
        - `va_arg`
        - `va_copy`
        - `va_end`
    - Don’t implement the buffer management of the original `printf()`.
    - Compare your implementation against the original `printf()`.
    - Use the command `ar` to create your library. Using the `libtool` command is forbidden.