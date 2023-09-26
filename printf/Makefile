CC := cc
CFLAGS := -Wall -Wextra -Werror -I.
NAME := libftprintf.a
LIBFT_PATH = ./libft

SRCS := ft_printf.c
# BONUS_SRCS := bonus.c

OBJS := $(SRCS:%.c=%.o)
# BONUS_OBJS := $(BONUS_SRCS:%.c=%.o)

.PHONY: all clean fclean re bonus

all: $(NAME)

$(NAME): $(OBJS)
	(cd $(LIBFT_PATH) && $(MAKE))
	ar -rcs $(NAME) $(OBJS)
	ranlib $(NAME)

# bonus: $(BONUS_OBJS)
# 	cd ./libft
# 	make fclean all bonus
# 	cd ..
# 	ar -rcs $(NAME) $(BONUS_OBJS)
# 	ranlib $(NAME)

re: fclean all

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)
