/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_stdin.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemchuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 16:54:28 by bsemchuk          #+#    #+#             */
/*   Updated: 2017/06/27 16:35:32 by bsemchuk         ###   ########.fr       */
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

char		*get_next_line_stdin(void)
{
	char	b[MAX_LINE + 1];
	int		done;

	done = 0;
	reset_buffer(b);
	while (done += read(0, &b[done], 1) && done < MAX_LINE)
	{
		if (ft_strstr(b, "\n"))
			return (ft_strdup(b));
	}
	return (NULL);
}
