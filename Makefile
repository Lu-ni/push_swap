NAME = push_swap
CC = cc
CFLAGS = -Wextra -Werror -Wall
SRC = actions.c algo.c algo_low_n.c algo_utils.c algo_utils2.c error.c ft_atoi.c ft_calloc.c ft_split.c ft_strdup.c ft_strlen.c ft_substr.c init.c leastcost.c main.c node_basic.c stack_utils.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

