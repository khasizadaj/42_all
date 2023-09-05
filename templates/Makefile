CC := cc
CFLAGS := -Wall -Wextra -Werror
NAME := bsq
SRCS := main.c helper.c string.c read_file.c validate_characters.c validate_map.c error.c config.c solution.c
OBJS := $(SRCS:.c=.o)

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
