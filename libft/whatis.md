This project is about coding a C library. It will contain a lot of general
purpose functions your programs will rely upon.

link to pdf: https://cdn.intra.42.fr/pdf/pdf/101362/en.subject.pdf

## Content

### Part 1

- [x] ft_atoi
- [x] ft_bzero
- [x] ft_isalpha
- [x] ft_isdigit
- [x] ft_isalnum
- [x] ft_isascii
- [x] ft_isprint
- [x] ft_strlen
- [x] ft_memset
- [x] ft_memchr
- [x] ft_memcmp
- [x] ft_memcpy
- [x] ft_memmove
- [x] ft_strlcpy
- [x] ft_strlcat
- [x] ft_toupper
- [x] ft_tolower
- [x] ft_strchr
- [x] ft_strrchr
- [x] ft_strncmp
- [x] ft_strnstr

- [x] ft_calloc (note: use `malloc`)
- [x] ft_strdup (note: use `malloc`)


### Part 2

- [x] ft_substr
- [x] ft_strjoin
- [x] ft_strtrim
- [x] ft_split
- [x] ft_itoa
- [x] ft_strmapi
- [x] ft_striteri
- [x] ft_putchar_fd
- [x] ft_putstr_fd
- [x] ft_putendl_fd
- [x] ft_putnbr_fd


### Bonus

- [x] ft_lstnew
- [x] ft_lstadd_front
- [x] ft_lstsize
- [x] ft_lstlast
- [x] ft_lstadd_back
- [x] ft_lstdelone
- [x] ft_lstclear
- [x] ft_lstiter
- [x] ft_lstmap


### Explanations

#### ft_memset

> Got help of ChatGPT. 

The variable `p` is used in the `memset` function to help iterate through the memory block and set each byte to the specified value `c`. It is not strictly necessary, and you can directly use the `s` pointer to achieve the same result. However, using `p` makes the code more readable and can help avoid potential issues with pointer arithmetic.

Here's why `p` is used:

1. **Readability:** By introducing `p`, the code becomes more self-explanatory. It clearly indicates that you're treating the memory as an array of bytes and iterating over it. Without `p`, the code might look less intuitive and require more mental effort to understand.

2. **Pointer Arithmetic:** When you perform pointer arithmetic directly on `s`, you might encounter issues with the type of the pointer. The `memset` function takes a `void*` pointer, which doesn't support pointer arithmetic directly because the size of the data type it points to is not known. By casting `s` to `unsigned char*`, you make it explicit that you're working with bytes, and pointer arithmetic becomes well-defined.

3. **Type Safety:** Casting `c` to `unsigned char` ensures that you are working with a byte-sized value, which is important for correct behavior when setting each byte in memory. This cast helps prevent unintended behavior that might occur if `c` were a larger data type.

In summary, while it's technically possible to use `s` directly without introducing `p`, using `p` is a good practice for code clarity, type safety, and avoiding potential pointer arithmetic issues. It makes the code easier to understand and maintain.
