CC := cc
CFLAGS := -Wall -Wextra -Werror
NAME := libft.a
SRCS := ft_bzero.c ft_memset.c
OBJS := $(SRCS:%.c=%.o)

all: $(NAME)

re: fclean all

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS) $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
