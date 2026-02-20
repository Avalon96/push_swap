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
		stack_ops4 \
		list_ops \
		utils \
		push_swap \
		insertion_sort \
		insertion_sort_utils \
		insertion_sort_utils2 \
		print_utils \
		radix_sort \
		strategies \
		bucket_sort \
		generics
SRCS	=	$(addprefix $(SRC), $(addsuffix .c, $(FILES)))
OBJS	=	$(SRCS:.c=.o)
NAME	=	push_swap
LIBS	=	libft/libft.a


all: libft
	$(MAKE) $(NAME)

run: all
# 	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) $(flags) $(args)
	./$(NAME) $(flags) $(args)

test: all
	./$(NAME) $(flags) $(args) | ./checker_linux $(args)

libft:
	$(MAKE) -C libft

$(SRC)/%.o: $(SRC)/%.c $(SRC)/buffer.h
	$(CC) -c $(CFLAGS) $< -o $@

$(NAME): $(OBJS) $(LIBS)
	$(CC) $(LDFLAGS) -o $@ $^
clean:
	rm -f ${OBJS}
	$(MAKE) -C libft fclean
fclean: clean
	rm -f ${NAME}
	$(MAKE) -C libft fclean
re: fclean
	$(MAKE) all

.PHONY: all clean fclean re libft
