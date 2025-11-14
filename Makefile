NAME = pushswap.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC = op_push.c push_swap.c op_swap.c libft/ft_atol.c op_rotate.c op_reverse_rotate.c\
	stack_utils.c

RM = rm -rf

OBJS = $(SRC:.c=.o)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

all: $(NAME)

fclean: clean
	$(RM) $(NAME)

clean:
	$(RM) $(OBJS)

re: fclean all

.PHONY: all clean fclean re
