CC := cc
CFLAGS := 
NAME := bsq

all: final

final: 
	$(CC) $(CFLAGS) main.c helper.c string.c read_file.c validate_characters.c validate_map.c error.c config.c solution.c -o $(NAME)

clean:
	rm *.o

fclean:
	rm $(NAME)
