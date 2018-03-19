/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish_header.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemchuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 18:44:58 by bsemchuk          #+#    #+#             */
/*   Updated: 2018/03/12 19:10:08 by bsemchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static void		free_deintegrated(unsigned char **array)
{
	int			i;

	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
}

static void		free_trio(t_line *line)
{
	free(line->line_content);
	free(line->line_content_trim);
	free(line->line_content_nocommas);
}

int				finish_header(t_champion *header)
{
	unsigned	i;

	i = 0;
	while (i < header->lines_count)
	{
		if (header->tlines)
		{
			free_trio(&header->tlines[i]);
			if (header->tlines[i].label)
				free(header->tlines[i].label);
			if (header->tlines[i].args)
				free_deintegrated(header->tlines[i].args);
			if (header->tlines[i].deintegrated_line)
				free_deintegrated(header->tlines[i].deintegrated_line);
		}
		i++;
	}
	if (header->out_filename)
		free(header->out_filename);
	free_lists(header->labels);
	free(header->tlines);
	ft_free(header);
	return (EXIT_SUCCESS);
}
