/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_lines_extra.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemchuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 18:38:00 by bsemchuk          #+#    #+#             */
/*   Updated: 2018/03/19 16:31:00 by bsemchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int				get_label_id(char *label, t_champion *champion)
{
	unsigned	i;

	i = 0;
	while (i < champion->lines_count)
	{
		if (ft_strequ((const char *)champion->tlines[i].label, label))
			return (i);
		i++;
	}
	return (-1);
}

int				get_difference_in_bytes(int id_from,
		int id_to, t_champion *champion)
{
	int			difference;

	difference = 0;
	while (id_from != id_to)
	{
		if (id_from < id_to)
		{
			difference += champion->tlines[id_from].bytes_needed;
			id_from++;
		}
		else
		{
			difference -= champion->tlines[id_from - 1].bytes_needed;
			id_from--;
		}
	}
	return (difference);
}

/*
**  Функция не проверяет исправность фд -- его проверяют до этого
**  через ft_fd_valid();
*/

void			free_lists(t_llist *list)
{
	if (list)
	{
		if (list->next)
			free_lists(list->next);
		free(((t_label *)list->data)->name);
		free(list->data);
		free(list);
	}
}

int				count_executable_size(const t_champion *header,
		unsigned int count_of_lines_for_tline_array)
{
	int			executable_size;
	unsigned	i;

	i = 0;
	executable_size = 0;
	while (i < count_of_lines_for_tline_array)
	{
		executable_size += header->tlines[i].bytes_needed;
		i++;
	}
	return (executable_size);
}

int				validate_line(t_line *line, t_champion *champion)
{
	if (!line->label && !line->cmd && line->line_content)
	{
		write(2, "Unknown command", 15);
		champion->nerrorline = line->id - 1;
		champion->serrorline = line->line_content;
		return (EXIT_FAILURE);
	}
	if (line->command_index > -1)
	{
		if (arguments_validation_and_codage_writing(line, champion) \
				== EXIT_FAILURE)
		{
			champion->nerrorline = line->id;
			champion->serrorline = line->line_content;
			return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}
