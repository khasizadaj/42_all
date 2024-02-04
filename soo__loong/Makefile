NAME 		=	so_long

CC 			=	cc
CFLAGS		=	-Wall -Wextra -Werror -I ./include -g

SRC_DIR 	=	src
UTILS_DIR 	=	${SRC_DIR}/utils
LIBFT_DIR 	=	${SRC_DIR}/libft
LIBFT		=	${SRC_DIR}/libft/libft.a

SRCS 		=	${SRC_DIR}/main.c \
				${UTILS_DIR}/asset.c \
				${UTILS_DIR}/draw.c \
				${UTILS_DIR}/error.c \
				${UTILS_DIR}/game.c \
				${UTILS_DIR}/map.c \
				${UTILS_DIR}/validate_map.c \
				${UTILS_DIR}/hook.c \
				${UTILS_DIR}/tile.c

OBJS 		=	${SRCS:.c=.o}
LIBFT_OBJS	=	$(wildcard $(LIBFT_DIR)/*.o)

MLX_FLAGS	=	-lmlx -lXext -lX11


all: ${NAME}

run: ${NAME}
	./${NAME} ./maps/basic.ber

${NAME}: ${OBJS} ${LIBFT_OBJS}
	@${MAKE} -C ${LIBFT_DIR} --no-print-directory
	@${CC} ${CFLAGS} ${OBJS} ./${LIBFT_DIR}/libft.a -o ${NAME} ${MLX_FLAGS}

valgrind: debug
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./${NAME} maps/invalid_non_rectangle.ber

clean: 
	@${MAKE} -C ${LIBFT_DIR} --no-print-directory clean
	@${RM} ${OBJS}

fclean: clean
	@${MAKE} -C ${LIBFT_DIR} --no-print-directory fclean
	@${RM} -f ${NAME}

re: fclean all

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean fclean re debug valgrind
