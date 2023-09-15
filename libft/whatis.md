This project is about coding a C library. It will contain a lot of general
purpose functions your programs will rely upon.

link to pdf: https://cdn.intra.42.fr/pdf/pdf/101362/en.subject.pdf

## Content

### Part 1

- [ ] ft_atoi
- [x] ft_bzero
- [x] ft_isalpha
- [x] ft_isdigit
- [x] ft_isalnum
- [x] ft_isascii
- [ ] ft_isprint
- [x] ft_strlen
- [x] ft_memset
- [ ] ft_memchr
- [ ] ft_memcmp
- [ ] ft_memcpy
- [ ] ft_memmove
- [ ] ft_strlcpy
- [ ] ft_strlcat
- [ ] ft_toupper
- [ ] ft_tolower
- [ ] ft_strchr
- [ ] ft_strrchr
- [ ] ft_strncmp
- [ ] ft_strnstr

- [ ] ft_calloc (note: use `malloc`)
- [ ] ft_strdup (note: use `malloc`)


### Part 2

- [x] ft_substr
- [x] ft_strjoin
- [x] ft_strtrim
- [x] ft_split
- [x] ft_itoa
- [ ] ft_strmapi
- [ ] ft_striteri
- [ ] ft_putchar_fd
- [ ] ft_putstr_fd
- [ ] ft_putendl_fd
- [ ] ft_putnbr_fd


### Bonus

- [ ] ft_lstnew
- [ ] ft_lstadd_front
- [ ] ft_lstsize
- [ ] ft_lstsize
- [ ] ft_lstlast
- [ ] ft_lstadd_back
- [ ] ft_lstdelone
- [ ] ft_lstclear
- [ ] ft_lstiter
- [ ] ft_lstmap


### Explanations

#### ft_memset

> Got help of ChatGPT. 

The variable `p` is used in the `memset` function to help iterate through the memory block and set each byte to the specified value `c`. It is not strictly necessary, and you can directly use the `s` pointer to achieve the same result. However, using `p` makes the code more readable and can help avoid potential issues with pointer arithmetic.

Here's why `p` is used:

1. **Readability:** By introducing `p`, the code becomes more self-explanatory. It clearly indicates that you're treating the memory as an array of bytes and iterating over it. Without `p`, the code might look less intuitive and require more mental effort to understand.

2. **Pointer Arithmetic:** When you perform pointer arithmetic directly on `s`, you might encounter issues with the type of the pointer. The `memset` function takes a `void*` pointer, which doesn't support pointer arithmetic directly because the size of the data type it points to is not known. By casting `s` to `unsigned char*`, you make it explicit that you're working with bytes, and pointer arithmetic becomes well-defined.

3. **Type Safety:** Casting `c` to `unsigned char` ensures that you are working with a byte-sized value, which is important for correct behavior when setting each byte in memory. This cast helps prevent unintended behavior that might occur if `c` were a larger data type.

In summary, while it's technically possible to use `s` directly without introducing `p`, using `p` is a good practice for code clarity, type safety, and avoiding potential pointer arithmetic issues. It makes the code easier to understand and maintain.
