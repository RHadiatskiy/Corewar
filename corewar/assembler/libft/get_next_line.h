/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemchuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 13:43:42 by bsemchuk          #+#    #+#             */
/*   Updated: 2017/02/15 08:38:15 by bsemchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include "libft.h"
# define BUFF_SIZE 500
# define TRUE 1
# define FALSE 0
# define ERROR -1

typedef struct		s_text
{
	int				fd;
	char			*text;
	size_t			pos;
	struct s_text	*next;
}					t_text;

int					get_next_line(const int fd, char **line);

#endif
