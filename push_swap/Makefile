NAME = push_swap

SRC_DIR = src
UTILS_DIR = src/utils
ALG_DIR = alg
TEST_DIR = test
LIBFT_DIR = ./${SRC_DIR}/libft

SRCS =	${SRC_DIR}/main.c \
		${UTILS_DIR}/reverse_rotate.c \
		${UTILS_DIR}/rotate.c \
		${UTILS_DIR}/swap.c

OBJS = ${SRCS:.c=.o}

CC = cc

CFLAGS = -Wall -Wextra -Werror -I ./include

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
