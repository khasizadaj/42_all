CC := cc
CFLAGS := -Wall -Wextra -Werror
NAME := rush-02

all: final

final: 
	$(CC) $(CFLAGS) building_blocks.c dictionary.c dictionary_helper.c ft_strstr.c helper.c main.c memory.c numbers.c parse_line.c validate_input.c -o $(NAME)

clean:
	rm *.o

fclean:
	rm $(NAME)
