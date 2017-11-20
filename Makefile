NAME = corewar

CC= gcc -o
FLAGS = -Wall -Wextra -Werror -g
LIBFT = libft/libft.a
LIBFTPRINTF= src/ft_printf/libftprintf.a

SRC = src/main src/initial src/printing src/parsing \
		src/validation

OBJ = $(addsuffix .o,$(SRC))

all: lib ft_printf fractol

lib:
	@make -C ./libft

ft_printf:
	@make -C ./src/ft_printf

fractol: $(OBJ)
	gcc -o $(NAME) $(FLAGS) $(OBJ) $(LIBFT) $(LIBFTPRINTF)

%.o: %.c
	gcc $(FLAGS) -c -o $@ $< 

clean:
	@make -C libft clean
	@make -C ./src/ft_printf clean
	@rm -f $(OBJ)
	
fclean: clean
	@rm -f $(NAME)
	@rm -f $(LIBFTPRINTF)
	@rm -f $(LIBFT)

re: fclean all
