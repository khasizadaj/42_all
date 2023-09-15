CC := cc
CFLAGS := -Wall -Wextra -Werror
NAME := libft.a
SRCS := ft_bzero.c \
	ft_isalnum.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_itoa.c \
	ft_memset.c \
	ft_split.c \
	ft_strlen.c \
	ft_strtrim.c \
	ft_substr.c \
	ft_memcpy.c \
	main.c

OBJS := $(SRCS:%.c=%.o)

all: $(NAME)

re: fclean all

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
