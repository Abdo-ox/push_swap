CC = gcc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address
NAME  = push_swap
NAME_LIB = libft/libft.a
NAME_PRI = ft_printf/libftprintf.a
SRC = push_swap.c utils.c
OBJ =$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(NAME_LIB) $(NAME_PRI)
	$(CC) $(CFLAGS) $(OBJ) $(NAME_LIB) $(NAME_PRI) -o $(NAME)

$(NAME_LIB):
	make all bonus clean -C ./libft

$(NAME_PRI):
	make all clean -C ./ft_printf

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)
clean_all: fclean
	rm -rf $(NAME_LIB) $(NAME_PRI)

re: clean_all all