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
	struct s_player		*players;
}						t_core;

typedef struct			s_player
{
	unsigned int		id;
	unsigned char		*data;
	unsigned int		data_len;
	struct s_player		*next;
}						t_player;

int						ft_printf(const char *format, ...);

/*
**	INITIAL
*/

unsigned char			*init_map(void);
t_player				*init_players(void);

/*
**	READING
*/

int						read_file(t_core *core, char *av);
int						read_args(t_core *core, int ac, char **av);

/*
**	VALIDATION
*/

int						validation(t_core *info, char *data);

/*
**	PARSING
*/

void					parsing(t_core *info);

/*
**	PRINTING
*/

void					print_map(unsigned char *map);
void					print_data(t_player *players);
void					print_players(t_player *players);

/*
**	ADDITION
*/

void					add_player(t_player *players, unsigned char *data, \
	unsigned int data_len);

/*
**	GETTING
*/

unsigned int			get_players_size(t_player *players);

#endif
