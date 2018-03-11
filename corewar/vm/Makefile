NAME = corewar

CC= gcc -o
FLAGS = -Wall -Wextra -Werror -g
NCFLAGS = -lncurses
LIBFT = ../libft/libft.a
LIBFTPRINTF= ../ft_printf/libftprintf.a

SRC = src/main \
		src/initial/init_core src/initial/init_flags \
				src/initial/init_header src/initial/init_map \
				src/initial/init_players src/initial/init_process \
		src/printing/print_errors src/printing/print_flags \
				src/printing/print_map src/printing/print_players \
				src/printing/print_processes src/printing/print_prog_attr \
		src/parsing/parse_header \
		src/validation/validation \
		src/reading/read_file src/reading/read_args src/reading/read_flags \
				src/reading/read_verbosity src/reading/read_visual\
		src/addition/add_player src/addition/add_process \
		src/getting/get_next_index src/getting/get_players_size \
				src/getting/get_value_from_map src/getting/get_command_from_array \
		src/other/sort_players src/other/ft_findchr \
				src/other/put_value_on_the_map \
				src/other/reset_players_lives \
				src/other/kill_processes \
				src/other/fork_process \
				src/other/pc_movements \
		src/running/run_processes src/running/run_players src/running/run \
		src/loading/load_players_on_the_map src/loading/load_processes \
				src/loading/load_commands \
		src/commands/command_add src/commands/command_aff src/commands/command_and \
				src/commands/command_fork src/commands/command_ld \
				src/commands/command_ldi src/commands/command_lfork \
				src/commands/command_live src/commands/command_lld \
				src/commands/command_lldi src/commands/command_or \
				src/commands/command_st src/commands/command_sti \
				src/commands/command_sub src/commands/command_xor \
				src/commands/command_zjmp \
		src/ncurses/ncurses_version \
				src/ncurses/counter_changes \
				src/ncurses/refresh_data \
				src/ncurses/ncurses_2


OBJ = $(addsuffix .o,$(SRC))

all: lib ft_printf vm

lib:
	@make -C ./../libft

ft_printf:
	@make -C ../ft_printf

vm: $(OBJ)
	gcc -o $(NAME) $(FLAGS) $(OBJ) $(NCFLAGS) $(LIBFT) $(LIBFTPRINTF)

%.o: %.c
	gcc $(FLAGS) -c -o $@ $< 

clean:
	@make -C ../libft clean
	@make -C ../ft_printf clean
	@rm -f $(OBJ)
	
fclean: clean
	@rm -f $(NAME)
	@rm -f $(LIBFTPRINTF)
	@rm -f $(LIBFT)

re: fclean all