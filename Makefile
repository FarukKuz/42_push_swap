NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC = op_push.c push_swap.c op_swap.c libft/ft_atol.c op_rotate.c op_reverse_rotate.c\
	stack_utils.c error_management.c lis_utils.c lis_sort.c main.c cost_calculation.c\
	cost_calculation_utils.c

RM = rm -rf

OBJS = $(SRC:.c=.o)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

all: $(NAME)

fclean: clean
	$(RM) $(NAME)

clean:
	$(RM) $(OBJS)

re: fclean all

.PHONY: all clean fclean re
