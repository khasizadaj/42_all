CC := cc
CFLAGS := -Wall -Wextra -Werror -I.
NAME := get_next_line.a

SRCS := get_next_line.c \
		get_next_line_utils.c \

OBJS := $(SRCS:%.c=%.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)
	ranlib $(NAME)

re: fclean all

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)