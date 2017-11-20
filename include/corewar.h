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

# define BUF_SIZE		10000

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
	char				*map;
}						t_core;

int						ft_printf(const char *format, ...);
char					*init_map(void);
void					print_map(char *map);
int						validation(char *data);

#endif
