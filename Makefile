NAME = pushswap.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC = push_operations.c push_swap.c swap_operations.c libft/ft_atoi.c

RM = rm -rf

OBJS = $(SRC:.c=.o)

$(NAME): $(OBJS)
	ar rcs -o $(NAME) $(OBJS)

all: $(NAME)

fclean: clean
	$(RM) $(NAME)

clean:
	$(RM) $(OBJS)

re: fclean all

.PHONY: all clean fclean re