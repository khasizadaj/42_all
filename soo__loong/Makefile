###############################################################################
######                            PROPERTIES                             ######
###############################################################################

NAME		= so_long
CFLAGS		= -Wall -Wextra -Werror -MP -MD -g
MLX_FLAGS	= -lmlx -lXext -lX11

SRCS_DIR	= src
UTILS_DIR	= src/utils
LIBFT		= ft
LIBFT_DIR	= src/libft
TEST_DIR	= tests

SRCS		= \
	${SRCS_DIR}/main.c

SRCS_UTILS	= \
	${UTILS_DIR}/animate.c \
	${UTILS_DIR}/animate_helper.c \
	${UTILS_DIR}/asset.c \
	${UTILS_DIR}/data.c \
	${UTILS_DIR}/draw.c \
	${UTILS_DIR}/error.c \
	${UTILS_DIR}/freer.c \
	${UTILS_DIR}/game.c \
	${UTILS_DIR}/game_helper.c \
	${UTILS_DIR}/hook.c \
	${UTILS_DIR}/map.c \
	${UTILS_DIR}/tile.c \
	${UTILS_DIR}/time.c \
	${UTILS_DIR}/validate_map.c

OBJS_DIR	= ${SRCS_DIR}/objs
OBJS		= \
	${SRCS:${SRCS_DIR}/%.c=${OBJS_DIR}/%.o} \
	${SRCS_UTILS:${UTILS_DIR}/%.c=${OBJS_DIR}/%.o}

# New directories should be added like this
#	${SRCS_DIR}/%.c=${OBJS_DIR}/%.o}

###############################################################################
######                               RULES                               ######
###############################################################################

all: ${NAME}

${NAME}: ${OBJS}
	@make -C ${LIBFT_DIR} --no-print-directory
	@cc ${CFLAGS} -o ${NAME} ${OBJS} -L${LIBFT_DIR} -l${LIBFT} ${MLX_FLAGS}

clean:
	@make -C ${LIBFT_DIR} clean --no-print-directory
	@rm -rf ${OBJS_DIR}

fclean: clean
	@make -C ${LIBFT_DIR} fclean --no-print-directory
	@rm -f ${NAME}

run: ${NAME}
	./${NAME}

re: fclean all

${OBJS_DIR}/%.o: ${SRCS_DIR}/%.c
	@mkdir -p $(dir $@)
	@cc ${CFLAGS} -c $< -o $@

${OBJS_DIR}/%.o: ${UTILS_DIR}/%.c
	@mkdir -p $(dir $@)
	${CC} ${CFLAGS} -c $< -o $@

# New rules for should be added like this
# ${OBJS_DIR}/%.o: ${NEW_DIR}/%.c
# 	@mkdir -p $(dir $@)
# 	${CC} ${CFLAGS} -c $< -o $@

.PHONY: all clean fclean re