NAME = so_long

SRC_DIR = src
LIBFT_DIR = src/libft

SRCS =	${SRC_DIR}/main.c

OBJS = ${SRCS:.c=.o}

CC = cc

CFLAGS = -Wall -Wextra -Werror -I ./include 

all: ${NAME}

${NAME}: ${OBJS}
	@${MAKE} -C ${LIBFT_DIR} --no-print-directory
	@${CC} ${CFLAGS} ${OBJS} ./${LIBFT_DIR}/libft.a -o ${NAME}

debug: ${OBJS}
	@${MAKE} -C ${LIBFT_DIR} --no-print-directory
	@${CC} ${CFLAGS} -g ${OBJS} ./${LIBFT_DIR}/libft.a -o ${NAME}

valgrind: debug
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./${NAME}

clean: 
	@${MAKE} -C ${LIBFT_DIR} --no-print-directory clean
	@${RM} ${OBJS}

fclean: clean
	@${RM} -f ${NAME}

re: fclean all
	
.PHONY: all clean fclean re debug valgrind
