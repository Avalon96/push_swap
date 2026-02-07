ROOT	=	./
SRC		=	$(ROOT)/
INC		=	$(ROOT)/

CC		=	cc
CFLAGS	=	-I $(INC) -pedantic -Wall -Wextra -I ./libft -I ./libft/ft_printf/include -g
LDFLAGS	=	-fsanitize=address

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
		push_swap
SRCS	=	$(addprefix $(SRC), $(addsuffix .c, $(FILES)))
OBJS	=	$(SRCS:.c=.o)
NAME	=	push_swap
LIBS	=	libft/libft.a


all: libft
	$(MAKE) $(NAME)

run: all
	./$(NAME) $(args)

libft:
	$(MAKE) -C libft

$(SRC)/%.o: $(SRC)/%.c $(SRC)/buffer.h
	$(CC) -c $(CFLAGS) $< -o $@

$(NAME): $(OBJS) $(LIBS)
	$(CC) $(LDFLAGS) -o $@ $^
clean:
	rm -f ${OBJS} 
fclean: clean
	rm -f ${NAME}
re: fclean
	$(MAKE) all

.PHONY: all clean fclean re libft
