CC := cc
CFLAGS := -Wall -Wextra -Werror
NAME := libft.a
SRCS := ft_bzero.c \
	ft_isalnum.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_itoa.c \
	ft_calloc.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_memchr.c \
	ft_memset.c \
	ft_split.c \
	ft_strchr.c \
	ft_strdup.c \
	ft_strlcpy.c \
	ft_strlcat.c \
	ft_strrchr.c \
	ft_strlen.c \
	ft_strtrim.c \
	ft_substr.c \
	ft_tolower.c \
	ft_toupper.c \

OBJS := $(SRCS:%.c=%.o)

all: $(NAME)

compile: $(NAME)
	$(CC) $(CFLAGS) $(OBJS) -o a.out

re: fclean all

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS) $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
