CC := cc
CFLAGS := -Wall -Wextra -Werror
NAME := bsq

all: final

final: 
	$(CC) $(CFLAGS) helper.c main.c string.c read_file.c validate_characters.c validate_map.c -o $(NAME)

clean:
	rm *.o

fclean:
	rm $(NAME)
