/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_header_valid.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemchuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 19:17:41 by bsemchuk          #+#    #+#             */
/*   Updated: 2018/03/20 18:36:17 by bsemchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static int		g_comment_written;
static int		g_name_written;

int				space_before(t_line *tline)
{
	if (!tline->deintegrated_line || !tline->deintegrated_line[1])
		return (EXIT_FAILURE);
	if (tline->deintegrated_line[1][0] == START_QUOTES)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

static int		comment_comment(t_champion *header, int *i)
{
	if (space_before(&header->tlines[(*i)]) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	header->tlines[(*i)].linetype = HEADER_TYPE;
	if (treat_comment_header((char *)header->tlines[(unsigned)(*i)].\
			line_content_trim, header, i) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	g_comment_written++;
	return (EXIT_SUCCESS);
}

static int		name_name(t_champion *header, int *i)
{
	if (space_before(&header->tlines[(*i)]) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	header->tlines[(*i)].linetype = HEADER_TYPE;
	if (treat_name_header((char *)header->tlines[(*i)].\
				line_content_trim, header, i) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	g_name_written++;
	return (EXIT_SUCCESS);
}

int				is_header_valid(t_champion *header)
{
	int			i;

	i = 0;
	g_comment_written = 0;
	g_name_written = 0;
	while (header->tlines[i].command_index == -1 &&\
			(unsigned)i < header->lines_count)
	{
		if (ft_strequ(COMMENT_CMD_STRING, (const char *)\
					header->tlines[i].deintegrated_line[0]))
		{
			if (comment_comment(header, &i) == EXIT_FAILURE)
				return (EXIT_FAILURE);
		}
		else if (ft_strequ(NAME_CMD_STRING, (const char *)\
				header->tlines[i].deintegrated_line[0]))
			if (name_name(header, &i) == EXIT_FAILURE)
				return (EXIT_FAILURE);
		i++;
	}
	if (g_comment_written == 1 && g_name_written == 1)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}
