# GET NEXT LINE

This project is about programming a function that returns a line
read from a file descriptor.

## Requirements

{{TBA}}

## How to test

- Use francinette :)
    - https://github.com/xicodomingues/francinette

```bash
$ francinette
$ francinette -s
```


### Notes

When writing your tests, remember that:

1. Both the buffer size and the line size can be of very different values.
2. A file descriptor does not only point to regular files.

- `libft` cannot be used.
- Allowed functions:
    - `malloc`
    - `free`
    - `read`
