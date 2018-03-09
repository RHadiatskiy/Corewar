/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 20:13:43 by rhadiats          #+#    #+#             */
/*   Updated: 2017/11/20 20:13:45 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

/*
**	Colorize an output of ft_printf
*/

# define RESET			"\033[0m"
# define RED			"\033[1;31m"
# define YELLOW			"\033[1;33m"
# define WHITE			"\033[1;37m"
# define GREEN			"\033[1;32m"
# define BLUE    		"\x1b[34m"
# define MAGENTA 		"\x1b[35m"
# define CYAN    		"\x1b[36m"
# define BLACK   		"\x1b[37m"

# define DATA_SIZE		PROG_NAME_LENGTH + COMMENT_LENGTH + 4 + (MEM_SIZE / 4)
# define PROG_SIZE		len - ((PROG_NAME_LENGTH) + (COMMENT_LENGTH) + 16)
# define FORMAT			16
# define ITER			process->iter
# define PC				process->pc
# define MAP			core->map
# define FLAGS			core->flags
# define CYCLE			core->cycle
# define ARGS			process->args
# define REG			process->reg
# define CMD			process->command
# define CODAGE			process->codage
# define OCTAL			process->octal
# define STEP			process->step
# define ROW			68
# define COL			241

/*
** ----------------------------
*/

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <math.h>
# include <ncurses.h>

# include "op.h"
# include "../libft/libft.h"

typedef struct			s_header
{
	unsigned int		magic;
	char				*prog_name;
	char				*comment;
	char				*prog;
	unsigned int		prog_size;
}						t_header;

typedef struct			s_player
{
	unsigned int		id;
	int					number;
	unsigned int		size;
	unsigned int		lives;
	int					lives_in_period;
	struct s_header		*header;
	struct s_player		*next;
}						t_player;

typedef struct			s_process
{
	int					pc;
	int					player;
	int					*reg;
	unsigned int		id;
	unsigned int		cycle;
	unsigned int		carry : 1;
	unsigned int		is_live : 1;
	int					iter;
	int					players_last_live;
	int					last_live;
	int					cycles_to_exec;
	int					command;
	int					codage;
	unsigned int		octal : 1;
	int					step;
	struct s_args		*args;
	struct s_process	*next;
}						t_process;

typedef struct			s_flags
{
	unsigned int		dump : 1;
	int					dump_cycle;
	unsigned int		number : 1;
	int					n;
	unsigned int		v : 1;
	int					verbosity;
	unsigned int		verbosity_one : 1;
	unsigned int		verbosity_two : 1;
	unsigned int		verbosity_four : 1;
	unsigned int		verbosity_eight : 1;
	unsigned int		verbosity_sixteen : 1;
	unsigned int		color : 1;
	unsigned int		visual : 1;
	unsigned int		aff : 1;
}						t_flags;

typedef struct			s_args
{
	int					arg;
	int					type;
}						t_args;

typedef struct			s_core
{
	unsigned char		*map;
	char				*clr;
	int					cycle;
	int					current_cycle;
	int					cycle_to_die;
	int					max_checks;
	int					speed;
	int					speed_num;
	unsigned int		players_lives;
	struct s_player		*champ;
	struct s_player		*players;
	struct s_process	*process;
	struct s_flags		*flags;
}						t_core;

typedef struct			s_op
{
	char				*command;
	int					count_args;
	int					arg[MAX_ARGS_NUMBER];
	int					opcode;
	int					cycles;
	char				*name;
	int					codage_octal;
	int					flag_direct_size;
}						t_op;

static t_op				g_op_tab[17] =
{
	{"live", 1, {T_DIR}, 1, 10, "alive", 0, 0},
	{"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", 1, 0},
	{"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store", 1, 0},
	{"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", 1, 0},
	{"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction", 1, 0},
	{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
		"et (and  r1, r2, r3   r1&r2 -> r3", 1, 0},
	{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
		"ou  (or   r1, r2, r3   r1 | r2 -> r3", 1, 0},
	{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
		"ou (xor  r1, r2, r3   r1^r2 -> r3", 1, 0},
	{"zjmp", 1, {T_DIR}, 9, 20, "jump if zero", 0, 1},
	{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
		"load index", 1, 1},
	{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
		"store index", 1, 1},
	{"fork", 1, {T_DIR}, 12, 800, "fork", 0, 1},
	{"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load", 1, 0},
	{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
		"long load index", 1, 1},
	{"lfork", 1, {T_DIR}, 15, 1000, "long fork", 0, 1},
	{"aff", 1, {T_REG}, 16, 2, "aff", 1, 0},
	{0, 0, {0}, 0, 0, 0, 0, 0}
};

static int				g_sizes[17][4] =
{
	{0, 1, 4, 2},
	{0, 1, 4, 2},
	{0, 1, 2, 2},
	{0, 1, 2, 2},
	{0, 1, 2, 2},
	{0, 1, 4, 2},
	{0, 1, 4, 2},
	{0, 1, 4, 2},
	{0, 1, 2, 2},
	{0, 1, 2, 2},
	{0, 1, 2, 2},
	{0, 1, 2, 2},
	{0, 1, 4, 2},
	{0, 1, 2, 2},
	{0, 1, 2, 2},
	{0, 1, 2, 2},
	{0, 0, 0, 0}
};

int						ft_printf(const char *format, ...);

/*
**	INITIAL
*/

unsigned char			*init_map(void);
t_player				*init_players(void);
t_header				*init_header(unsigned int magic, char *name,
									char *comment, char *prog);
t_process				*init_process(void);
t_flags					*init_flags(void);
t_core					*init_core(void);

/*
**	READING
*/

int						read_file(t_core *core, char *av);
int						read_args(t_core *core, int ac, char **av);
int						read_flags(t_core *core, char **av, int *i);
void					read_verbosity(t_core *core);
int						read_visual(t_core *core, char **av, int *i);

/*
**	VALIDATION
*/

int						validation(t_core *info, char *data);

/*
**	PARSING
*/

t_header				*parse_header(unsigned char *data, unsigned int size);

/*
**	PRINTING
*/

void					print_map(t_core *core);
void					print_data(t_player *players);
void					print_players(t_player *players);
void					print_prog_attr(char *name, unsigned int len);
int						print_usage(void);
void					print_processes(t_process *processes);
int						print_prog_size_error(char *dir, int len);
int						print_magic_error(char *dir);
void					print_champ(t_core *core);

/*
**	ADDITION
*/

void					add_player(t_player *players, t_header *header,
									unsigned int size, t_flags *flags);
void					add_process(t_process **processes, int start, int exec);

/*
**	GETTING
*/

unsigned int			get_players_size(t_player *players);
unsigned int			get_value_from_map(void *buf, unsigned int start,
						unsigned int len);
int						get_next_index(t_process *process, unsigned char *map,
						int command, int value);
int						get_command_from_array(t_core *core, t_process *process,
						int k);

/*
**	RUNNING
*/

void					run(t_core *core);
void					run_players(t_core *core);
void					run_processes(t_core *core, t_process *process);

/*
**	LOADING
*/

void					load_processes(t_core *core);
void					load_players_on_the_map(t_core *core);
void					load_commands(void);

/*
**	OTHER
*/

void					ft_sort_list(t_player *players);
int						ft_findchr(char *str, char c);
void					put_value_on_the_map(t_core *core, int start,
						int value, t_process *process);
void					reset_players_lives(t_player *players);
void					kill_processes(t_core *core);
void					fork_process(t_process **processes,
						t_process *process, int value);
void					pc_movements(t_core *core, t_process *process);

/*
**	COMMANDS
*/

int						(*g_commands[16])(t_core *core, t_process *process);
int						command_live(t_core *core, t_process *process);
int						command_ld(t_core *core, t_process *process);
int						command_st(t_core *core, t_process *process);
int						command_add(t_core *core, t_process *process);
int						command_sub(t_core *core, t_process *process);
int						command_and(t_core *core, t_process *process);
int						command_or(t_core *core, t_process *process);
int						command_xor(t_core *core, t_process *process);
int						command_zjmp(t_core *core, t_process *process);
int						command_ldi(t_core *core, t_process *process);
int						command_sti(t_core *core, t_process *process);
int						command_fork(t_core *core, t_process *process);
int						command_lld(t_core *core, t_process *process);
int						command_lldi(t_core *core, t_process *process);
int						command_lfork(t_core *core, t_process *process);
int						command_aff(t_core *core, t_process *process);

/*
** NCURSES MODE
*/

int						ncurses_version(t_core *core);
char					*initiate_color(void);
int						choose_players_color(t_player *players, char *clr,
						int players_num);
int						create_borders();
void					draw_map(int players, t_core *core);
int						fullfill_players_on_map(int players_num,
						t_player *players, t_core *core);
void					print_const_part(t_core *core);
int						fullfill_map(t_core *core, int players);
void					print_champ_visual(t_core *core);
void					cycle_refresh(t_core *core);
void					cycles_to_die_refresh(int cycle_to_die);
void					check_processes(t_core *core);
int						refre_map(t_core *core);
void					pause_vm(t_core *core);
void					draw_counter(t_core *core, t_process *process);
int						position(int pc, int *x, int *y);
void					clear_counter(t_core *core, t_process *process);
void					draw_counter(t_core *core, t_process *process);
void					key_code(t_core *core, int ch);

#endif
