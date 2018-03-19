/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_stdin.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemchuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 16:54:28 by bsemchuk          #+#    #+#             */
/*   Updated: 2017/10/23 14:30:45 by bsemchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**     Program reads from stdin and returns strduped string with no newline
*/

static void	reset_buffer(char *b)
{
	int	i;

	i = 0;
	while (i < MAX_LINE + 1)
		b[i++] = '\0';
}

char		*get_next_line_fd(int fd)
{
	char	b[MAX_LINE + 1];
	int		done;
	int		line;

	done = 0;
	line = done;
	reset_buffer(b);
	if ((read(fd, NULL, 0) < 0) && fd > 0)
		ft_error("Error\n");
	while (done += read(fd, &b[done], 1))
	{
		if ((b[done - 1] == '\n') || done == line)
			return (ft_strdup(b));
		line = done;
	}
	return (NULL);
}
