NAME = libftprintf.a
CC = cc
CFLAGS = -Wextra -Werror -Wall -c
SRC = ft_printf.c hexadecimal_tools.c ft_u_itoa.c
OBJ = $(SRC:.c=.o)
LIBFT = libft/libft.a

all: x
tester: x
	cd push_swap_tester && bash myTestes.sh && cd ../
x:
	gcc -g *.c -L. -lft -o push_swap
$(NAME): $(OBJ) $(LIBFT)
	# Extract object files from libft.a
	ar -x $(LIBFT)
	# Create libftprintf.a including those object files
	ar -rcs $(NAME) $(OBJ) *.o
	# Optionally, remove extracted object files to clean up
	rm -f *.o "__.SYMDEF SORTED"

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) $(SRC)

$(LIBFT):
	cd libft && make bonus && cd ../

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

