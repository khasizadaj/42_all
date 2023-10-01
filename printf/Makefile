CC := cc
CFLAGS := -Wall -Wextra -Werror -I.
NAME := libftprintf.a
LIBFT_PATH = ./libft
LIBFT_NAME = libft.a

SRCS := ft_printf.c nbr_to_hex.c ft_hex.c ft_ulltoa.c
# BONUS_SRCS := bonus.c

OBJS := $(SRCS:%.c=%.o)
# BONUS_OBJS := $(BONUS_SRCS:%.c=%.o)

.PHONY: all clean fclean re bonus

all: $(NAME)

$(NAME): $(OBJS)
	@${MAKE} -C ./libft --no-print-directory
	cp ./libft/libft.a $(NAME)
	ar -rcs $(NAME) $(OBJS) 
	ranlib $(NAME)

# (cd $(LIBFT_PATH) --no-print-directory && $(MAKE))

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
	(cd $(LIBFT_PATH) && $(MAKE) clean)
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	(cd $(LIBFT_PATH) && $(MAKE) fclean)
	rm -f $(NAME)
