CC := cc
CFLAGS := -Wall -Wextra -Werror -I.
NAME := get_next_line.a

SRCS := get_next_line.c \
		get_next_line_utils.c \

BONUS_SRCS := get_next_line_bonus.c \
		get_next_line_utils_bonus.c \

OBJS := $(SRCS:%.c=%.o)
BONUS_OBJS := $(BONUS_SRCS:%.c=%.o)

.PHONY: all clean fclean re bonus

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)
	ranlib $(NAME)

bonus: $(BONUS_OBJS)
	ar -rcs $(NAME) $(BONUS_OBJS)
	ranlib $(NAME)

re: fclean all

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME) $(BONUS_OBJS)