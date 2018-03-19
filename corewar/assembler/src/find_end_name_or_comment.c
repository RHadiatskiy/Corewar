/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_end_name_or_comment.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemchuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 18:20:08 by bsemchuk          #+#    #+#             */
/*   Updated: 2018/03/12 20:28:34 by bsemchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static int	searching_loop(t_champion *champion,
		int *i, char *line, char **total)
{
	void	*to_free;

	to_free = NULL;
	while (champion->tlines[++(*i)].command_index == -1)
	{
		line = (char *)champion->tlines[(*i)].line_content_trim;
		if (line[0] != '\0')
		{
			if (*total)
				to_free = *total;
			*total = ft_strjoin_whitespace(*total, line);
		}
		if (ft_strchindex((const unsigned char *)line, END_QUOTES) > -1)
			return (EXIT_SUCCESS);
		if (to_free)
		{
			free(to_free);
			to_free = NULL;
		}
	}
	return (EXIT_FAILURE);
}

int			find_end_name_or_comment(char *line, t_champion *champion,\
											char **end, int *i)
{
	char	*start;
	int		is_complete;

	start = ft_strdup(line);
	*end = ft_strdup(start);
	is_complete = searching_loop(champion, i, line, end);
	free(start);
	return (is_complete);
}
