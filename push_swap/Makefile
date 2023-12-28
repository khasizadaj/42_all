NAME = push_swap

SRC_DIR = src
UTILS_DIR = ./${SRC_DIR}/utils
ALG_DIR = ./${SRC_DIR}/alg
TEST_DIR = test
LIBFT_DIR = ./${SRC_DIR}/libft

SRCS =	${SRC_DIR}/main.c \
		${UTILS_DIR}/reverse_rotate.c \
		${UTILS_DIR}/rotate.c \
		${UTILS_DIR}/swap.c \
		${UTILS_DIR}/push.c \
		${UTILS_DIR}/debug.c \
		${ALG_DIR}/algorithm.c \
		${ALG_DIR}/apply.c

OBJS = ${SRCS:.c=.o}

CC = cc

CFLAGS = -Wall -Wextra -Werror -I ./include -g

all: ${NAME}

${NAME}: ${OBJS}
	@${MAKE} -C ${LIBFT_DIR} --no-print-directory
	@${CC} ${CFLAGS} ${OBJS} ./${LIBFT_DIR}/libft.a -o ${NAME}

clean:
	@${MAKE} -C ${LIBFT_DIR} --no-print-directory clean
	@${RM} ${OBJS}

fclean: clean
	@${RM} -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
