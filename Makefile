CC = gcc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address
NAME  = push_swap
NAME_LIB = libft/libft.a
NAME_PRI = ft_printf/libftprintf.a
SRC =  operations.c operations1.c utils.c push_swap.c
OBJ =$(SRC:.c=.o)

all: $(NAME)

$(NAME):  $(NAME_LIB) $(NAME_PRI) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(NAME_LIB) $(NAME_PRI) -o $(NAME)

$(NAME_LIB):
	make all bonus clean -C ./libft

$(NAME_PRI):
	make all clean -C ./ft_printf

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

clean_all: fclean
	rm -rf $(NAME_LIB) $(NAME_PRI)

re: clean_all all