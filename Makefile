CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME  = push_swap
NAMEB = checker
NAME_LIB = libft/libft.a
NAME_PRI = ft_printf/libftprintf.a
SRC =  operations.c operations1.c utils.c push_swap.c main.c
BONUS = checker.c operation_bonus.c operation_bonus1.c
GET = ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c
OBJ =$(SRC:.c=.o)
OBJB= $(BONUS:.c=.o)
all: $(NAME)

$(NAME):  $(NAME_LIB) $(NAME_PRI) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(NAME_LIB) $(NAME_PRI) -o $(NAME)

$(NAME_LIB):
	make all bonus clean -C ./libft

$(NAME_PRI):
	make all clean -C ./ft_printf

bonus: $(OBJB) $(NAME_LIB) $(NAME_PRI) $(GET)
	$(CC) $(CFLAGS) $(OBJB) $(NAME_LIB) $(NAME_PRI) $(GET) -o $(NAMEB)

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME) $(NAMEB)

clean_all: fclean
	rm -rf $(NAME_LIB) $(NAME_PRI)

re: clean_all all