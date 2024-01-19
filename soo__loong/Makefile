NAME = so_long

SRC_DIR = src
UTILS_DIR = ${SRC_DIR}/utils
LIBFT_DIR = ${SRC_DIR}/libft

SRCS =	${SRC_DIR}/main.c \
		${UTILS_DIR}/error.c

OBJS = ${SRCS:.c=.o}
LIBFT_OBJS = $(wildcard $(LIBFT_DIR)/*.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror -I ./include 

all: ${NAME}

run: ${NAME}
	./${NAME} ./maps/basic.ber

${NAME}: ${OBJS} ${LIBFT_OBJS}
	@${MAKE} -C ${LIBFT_DIR} --no-print-directory
	@${CC} ${CFLAGS} ${OBJS} ./${LIBFT_DIR}/libft.a -o ${NAME}

debug: ${OBJS} ${LIBFT_OBJS}
	@${MAKE} -C ${LIBFT_DIR} --no-print-directory
	@${CC} ${CFLAGS} -g ${OBJS} ./${LIBFT_DIR}/libft.a -o ${NAME}

valgrind: debug
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./${NAME}

clean: 
	@${MAKE} -C ${LIBFT_DIR} --no-print-directory clean
	@${RM} ${OBJS}

fclean: clean
	@${MAKE} -C ${LIBFT_DIR} --no-print-directory fclean
	@${RM} -f ${NAME}

re: fclean all
	
.PHONY: all clean fclean re debug valgrind
