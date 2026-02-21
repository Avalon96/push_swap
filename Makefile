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
		stack_ops \
		stack_ops2 \
		ps_ops1 \
		ps_ops2 \
		ps_ops3 \
		ps_ops_special \
		list_utils \
		utils \
		utils2 \
		disorder \
		parse \
		strategies \
		benchmark \
		insertion_sort \
		insertion_sort_utils \
		insertion_sort_utils2 \
		bucket_sort \
		bucket_sort_utils \
		bucket_sort_utils2 \
		radix_sort \
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
