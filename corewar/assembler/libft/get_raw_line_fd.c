/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_raw_line_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemchuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 22:19:44 by bsemchuk          #+#    #+#             */
/*   Updated: 2018/03/12 22:21:04 by bsemchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	reset_buffer(char *b)
{
	int	i;

	i = 0;
	while (i < MAX_LINE + 1)
		b[i++] = '\0';
}

char		*get_raw_line_fd(const int fd)
{
	char	b[MAX_LINE + 1];
	int		done;
	int		line;

	done = 0;
	line = done;
	reset_buffer(b);
	if ((read(fd, NULL, 0) < 0) && fd > 0)
		ft_error("Error in line reading\n");
	while (done += read(fd, &b[done], 1))
	{
		if ((b[done - 1] == '\n') || done == line)
		{
			if (b[done - 1] == '\n')
				b[done - 1] = 0;
			if (done >= MAX_LINE)
				ft_error("Line is bigger than MAX_LINE define, sorry\n");
			return (ft_strdup(b));
		}
		line = done;
	}
	return (NULL);
}
