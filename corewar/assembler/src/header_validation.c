/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header_validation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daleksan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 14:44:47 by daleksan          #+#    #+#             */
/*   Updated: 2018/03/12 19:31:16 by bsemchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int			check_after_quotes(char *line)
{
	char	*end;
	char	**split_end;

	end = ft_strchr(line + 1, END_QUOTES);
	split_end = ft_split_whitespace(end + 1);
	if ((split_end[0] != NULL && split_end[0][0] == COMMENT_CHAR)
			|| split_end[0] == NULL)
	{
		ft_delete_deintegrated(split_end);
		return (EXIT_SUCCESS);
	}
	ft_delete_deintegrated(split_end);
	return (EXIT_FAILURE);
}

int			write_prog_name(char *total, t_champion *champion)
{
	if (total)
	{
		if (ft_strlen(total) > PROG_NAME_LENGTH)
		{
			ft_putstr("Name length is too long\n");
			return (EXIT_FAILURE);
		}
		ft_strncpy(champion->prog_name, total + 1,
				(size_t)ft_strchindex(
					(const unsigned char *)(total + 1), END_QUOTES));
	}
	return (check_after_quotes(total));
}

int			treat_name_header(char *line, t_champion *header, int *i)
{
	char	*start;
	char	*end;

	start = ft_strchr(line, START_QUOTES);
	if (!start)
		return (EXIT_FAILURE);
	end = ft_strchr(start + 1, END_QUOTES);
	if (end)
	{
		if (write_prog_name(start, header) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	else
	{
		if (find_end_name_or_comment(start, header, &end, i) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		if (write_prog_name(end, header) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int			write_comment(char *total, t_champion *champion)
{
	if (total)
	{
		if (ft_strlen(total) > COMMENT_LENGTH)
		{
			ft_putstr("Comment length is too long\n");
			return (EXIT_FAILURE);
		}
		ft_strncpy(champion->comment, total + 1,
			(size_t)ft_strchindex(
				(const unsigned char *)(total + 1), END_QUOTES));
	}
	return (check_after_quotes(total));
}

int			treat_comment_header(char *line, t_champion *champion, int *i)
{
	char	*start;
	char	*end;

	if (!(start = ft_strchr(line, START_QUOTES)))
		return (EXIT_FAILURE);
	end = ft_strchr(start + 1, END_QUOTES);
	if (end)
	{
		if (write_comment(start, champion) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	else
	{
		if (find_end_name_or_comment(start, champion, &end, i) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		if (write_comment(end, champion) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		free(end);
	}
	return (EXIT_SUCCESS);
}
