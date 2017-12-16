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

#ifndef COREWAR_H
# define COREWAR_H

/*
**	Colorize an output of printf
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
# define FORMAT			16

/*
** ----------------------------
*/

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <math.h>

# include "op.h"
# include "../libft/libft.h"

typedef struct			s_core
{
	unsigned char		*map;
	int 				cycle;
	int 				cycle_to_die;
	struct s_player		*players;
	struct s_process	*process;
	struct s_flags		*flags;
}						t_core;

typedef struct			s_player
{
	unsigned int		id;
	int					number;
	unsigned int		size;
	struct s_header		*header;
	struct s_player		*next;
}						t_player;

typedef struct			s_header
{
	unsigned int		magic;
	char				*prog_name;
	char				*comment;
	char				*prog;
	unsigned int		prog_size;
}						t_header;

typedef struct			s_process
{
	unsigned int		pc;
	int					*reg;
	unsigned int		carry : 1;
	struct s_process	*next;
}						t_process;

typedef struct			s_flags
{
	unsigned int		dump : 1;
	int					dump_cycle;
	unsigned int		number : 1;
	int					n;
}						t_flags;

// typedef struct			s_op
// {

// }						t_op;

// t_op					op_tab[17] =
// {
// 	{"live", 1, {T_DIR}, 1, 10, "alive", 0, 0},
// 	{"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", 1, 0},
// 	{"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store", 1, 0},
// 	{"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", 1, 0},
// 	{"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction", 1, 0},
// 	{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
// 		"et (and  r1, r2, r3   r1&r2 -> r3", 1, 0},
// 	{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
// 		"ou  (or   r1, r2, r3   r1 | r2 -> r3", 1, 0},
// 	{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
// 		"ou (xor  r1, r2, r3   r1^r2 -> r3", 1, 0},
// 	{"zjmp", 1, {T_DIR}, 9, 20, "jump if zero", 0, 1},
// 	{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
// 		"load index", 1, 1},
// 	{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
// 		"store index", 1, 1},
// 	{"fork", 1, {T_DIR}, 12, 800, "fork", 0, 1},
// 	{"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load", 1, 0},
// 	{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
// 		"long load index", 1, 1},
// 	{"lfork", 1, {T_DIR}, 15, 1000, "long fork", 0, 1},
// 	{"aff", 1, {T_REG}, 16, 2, "aff", 1, 0},
// 	{0, 0, {0}, 0, 0, 0, 0, 0}
// };

int						ft_printf(const char *format, ...);

/*
**	INITIAL
*/

unsigned char			*init_map(void);
t_player				*init_players(void);
t_header				*init_header(unsigned int magic, char *name, char *comment, char *prog);
t_process				*init_process(void);
t_flags					*init_flags(void);
void					init_game(t_core *core);

/*
**	READING
*/

int						read_file(t_core *core, char *av);
int						read_args(t_core *core, int ac, char **av);
int						read_flags(t_core *core, char **av, int *i);

/*
**	VALIDATION
*/

int						prog_size_error(char *dir, int len);
int						magic_error(char *dir);
int						validation(t_core *info, char *data);

/*
**	PARSING
*/

t_header				*parse_header(unsigned char *data, unsigned int size);
void					insert_to_map(t_core *core);

/*
**	PRINTING
*/

void					print_map(t_core *core);
void					print_data(t_player *players);
void					print_players(t_player *players);
void					print_prog_attr(char *name, unsigned int len);
void					print_header(t_header *header, unsigned int size);
void					print_headers(t_player *players);
int						print_usage(void);

/*
**	ADDITION
*/

void					add_player(t_player *players, t_header *header, unsigned int size, t_flags *flags);

/*
**	GETTING
*/

unsigned int			get_players_size(t_player *players);
unsigned int			get_value_from_file(void *buf, unsigned int start, unsigned int len);


#endif
