CC := cc
CFLAGS := -Wall -Wextra -Werror -I.
NAME := libftprintf.a
LIBFT_PATH = ./libft
LIBFT_NAME = libft.a

SRCS := ft_printf.c ft_nbr_to_hex.c ft_hex.c ft_nbrtoa.c \
	ft_nbrlen.c ft_put.c

OBJS := $(SRCS:%.c=%.o)

.PHONY: all clean fclean re bonus

all: $(NAME)

$(NAME): $(OBJS)
	@${MAKE} -C ./libft --no-print-directory
	cp ./libft/libft.a $(NAME)
	ar -rcs $(NAME) $(OBJS) 
	ranlib $(NAME)

re: fclean all

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@${MAKE} clean -C ./libft --no-print-directory
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	@${MAKE} clean -C ./libft --no-print-directory
	rm -f $(NAME)