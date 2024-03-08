###############################################################################
######                            PROPERTIES                             ######
###############################################################################

CC			= cc
RM			= rm -rf
NAME		= routine
MAKE		+= --no-print-directory
CFLAGS		= -Wall -Wextra -Werror

###############################################################################
######                               TESTS                               ######
###############################################################################

T_VALIDATION_DIR	= map_validation

SRCS	= \
	${T_VALIDATION_DIR}/00_launcher.c \
	${T_VALIDATION_DIR}/01_is_valid_line.c \
	${T_VALIDATION_DIR}/02_get_map.c \
	main.c

OBJS	= $(SRCS:.c=.o)

###############################################################################
######                             SO LONG                               ######
###############################################################################

SO_LONG_SRCS = \
	../src/utils/map.c \
	../src/utils/validate_map.c \
	../src/libft/get_next_line.c \
	../src/libft/get_next_line_utils.c \
	../src/libft/ft_count_char.c

OBJS	+= $(SO_LONG_SRCS:.c=.o)

###############################################################################
######                             UNITTEST                              ######
###############################################################################

UNIT_DIR	= ../../libunit
UNIT		= ${UNIT_DIR}/libunit.a

###############################################################################
######                               RULES                               ######
###############################################################################

all: $(NAME)

test: $(NAME)
	@./$(NAME)

$(NAME): $(OBJS) $(NAME)
	$(MAKE) -C $(UNIT_DIR)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L $(UNIT_DIR) -lunit

clean:
	$(MAKE) clean -C $(UNIT_DIR)
	$(RM) $(OBJS)

fclean:
	$(MAKE) fclean -C $(UNIT_DIR)
	$(RM) $(OBJS) $(NAME)

re: fclean all

.PHONY: all clean fclean re test