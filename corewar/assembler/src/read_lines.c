/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_lines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemchuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 17:35:20 by bsemchuk          #+#    #+#             */
/*   Updated: 2018/03/19 16:18:21 by bsemchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int				flush_instructions(t_champion *header)
{
	unsigned	i;

	i = 0;
	while (i < header->lines_count)
	{
		if (header->tlines[i].command_index > -1)
			treat_instruction(&header->tlines[i], header);
		i++;
	}
	return (EXIT_SUCCESS);
}

int				validate_lines(t_champion *header)
{
	unsigned	i;

	i = 0;
	while (header->tlines[i].command_index == -1 && i < header->lines_count)
		i++;
	while (i < header->lines_count)
	{
		if (!header->tlines[i].line_content_trim[0])
		{
			i++;
			continue;
		}
		else if (validate_line(&header->tlines[i], header) == EXIT_FAILURE)
		{
			ft_printf("Error on line id %d: [%s]\n", i,
					header->tlines[i].line_content);
			return (EXIT_FAILURE);
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

int				parse_every_line(t_champion *header,
		unsigned *count_of_lines_for_tline_array)
{
	while ((header->tlines[(*count_of_lines_for_tline_array)].line_content = \
			(unsigned char *)get_raw_line_fd(header->fdin)))
	{
		header->tlines[*count_of_lines_for_tline_array].id = \
									*count_of_lines_for_tline_array;
		delete_comments(header->tlines\
				[*count_of_lines_for_tline_array].line_content);
		get_all_info_we_can_into_array_of_tlines(\
				&header->tlines[*count_of_lines_for_tline_array]);
		(*count_of_lines_for_tline_array)++;
	}
	return (EXIT_SUCCESS);
}

/*
**	Функція прибирає коментарії зі строк, і розбиває їх по пробілам
**	в двувимірний масив
*/

static int		ifelses(t_champion *header, char *path)
{
	if (is_header_valid(header) == EXIT_FAILURE)
	{
		ft_printf("Invalid header\n");
		return (EXIT_FAILURE);
	}
	if (validate_lines(header) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (change_filename_extension(path, &header->out_filename) == EXIT_FAILURE)
	{
		ft_printf("Error in filename extension\n");
		return (EXIT_FAILURE);
	}
	header->champion_size = count_executable_size(header, header->lines_count);
	if (!header->champion_size)
	{
		write(2, "No executable code, sorry\n", 27);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int				read_lines(char *path, t_champion *header)
{
	unsigned	count_of_lines_for_tline_array;

	count_of_lines_for_tline_array = 0;
	if (remember_all_labels_and_count_lines(header) == EXIT_FAILURE)
	{
		ft_printf("Can't remember labels, invalid label on line %d %s\n", \
				header->nerrorline, header->serrorline);
		return (EXIT_FAILURE);
	}
	header->tlines = ft_calloc(header->lines_count + 1, sizeof(t_line));
	lseek(header->fdin, 0, SEEK_SET);
	parse_every_line(header, &count_of_lines_for_tline_array);
	if (ifelses(header, path) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	ft_printf("Writing into %s\n", header->out_filename);
	header->fdout = open(header->out_filename, O_CREAT | O_WRONLY, 0644);
	flush_header_structure(header, header->fdout);
	flush_instructions(header);
	ft_printf("Executable size is %d bytes\n", header->champion_size);
	return (EXIT_SUCCESS);
}
