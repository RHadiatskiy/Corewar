/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flush_header_structure.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemchuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 17:40:32 by bsemchuk          #+#    #+#             */
/*   Updated: 2018/03/20 17:50:39 by bsemchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int			flush_header_structure(t_champion *champion, int fd)
{
	ft_write_value_big_e4(champion->fdout, COREWAR_EXEC_MAGIC);
	write(fd, &champion->prog_name, PROG_NAME_LENGTH + 4);
	champion->champion_size =
		count_executable_size(champion, champion->lines_count);
	if (!champion->champion_size)
	{
		ft_putstr("No commands to execute\n");
		return (EXIT_FAILURE);
	}
	ft_write_value_big_e4(fd, champion->champion_size);
	write(fd, &champion->comment, COMMENT_LENGTH + 4);
	return (EXIT_SUCCESS);
}
