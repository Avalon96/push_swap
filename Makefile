ROOT	=	./
SRC		=	$(ROOT)/
INC		=	$(ROOT)/

CC		=	cc
CFLAGS	=	-I $(INC) -pedantic -Wall -Wextra -I ./libft -I ./libft/ft_printf/include -g
LDFLAGS	=	#-fsanitize=address

ERR		=	-Werror

ifneq '$(err)' '0'
	CFLAGS	+=	$(ERR)
endif

FILES	=	cmd \
		stack_ops1 \
		stack_ops2 \
		stack_ops3 \
		list_ops \
		utils \
		push_swap \
		print_utils \
		strategies \
		generics
SRCS	=	$(addprefix $(SRC), $(addsuffix .c, $(FILES)))
OBJS	=	$(SRCS:.c=.o)
NAME	=	push_swap
LIBS	=	libft/libft.a


all: libft
	$(MAKE) $(NAME)

run: all
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) $(args)

libft:
	$(MAKE) -C libft

$(SRC)/%.o: $(SRC)/%.c $(SRC)/buffer.h
	$(CC) -c $(CFLAGS) $< -o $@

$(NAME): $(OBJS) $(LIBS)
	$(CC) $(LDFLAGS) -o $@ $^
clean:
	rm -f ${OBJS}
# 	$(MAKE) -C libft clean

fclean: clean
	rm -f ${NAME}
# 	$(MAKE) -C libft fclean

re: fclean
	$(MAKE) all

.PHONY: all clean fclean re libft
