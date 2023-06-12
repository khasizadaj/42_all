CC := cc
CFLAGS := -Wall -Wextra -Werror
NAME := bsq

all: final

final: 
	$(CC) $(CFLAGS) helper.c main.c -o $(NAME)

clean:
	rm *.o

fclean:
	rm $(NAME)
