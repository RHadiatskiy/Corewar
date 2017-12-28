NAME = corewar

CC= gcc -o
FLAGS = -Wall -Wextra -Werror -g
LIBFT = libft/libft.a
LIBFTPRINTF= src/ft_printf/libftprintf.a

SRC = src/main \
		src/initial/init_core src/initial/init_flags \
				src/initial/init_header src/initial/init_map \
				src/initial/init_players src/initial/init_process \
		src/printing/print_debug src/printing/print_errors \
		src/parsing/parse_header \
		src/validation/validation \
		src/reading/read_file src/reading/read_args src/reading/read_flags \
		src/addition/add_player src/addition/add_process \
		src/getting/get_next_index src/getting/get_players_size \
				src/getting/get_value_from_map \
		src/other/sort_players src/other/ft_findchr \
				src/other/put_value_on_the_map \
		src/running/run_processes src/running/run_player \
		src/loading/load_players_on_the_map src/loading/load_processes

OBJ = $(addsuffix .o,$(SRC))

all: lib ft_printf vm

lib:
	@make -C ./libft

ft_printf:
	@make -C ./src/ft_printf

vm: $(OBJ)
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
