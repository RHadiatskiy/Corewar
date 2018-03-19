/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flush_dir_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemchuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 17:37:00 by bsemchuk          #+#    #+#             */
/*   Updated: 2018/03/11 17:39:58 by bsemchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int		flush_dir_char(char *arg, t_champion *champion, unsigned id)
{
	int	diff;
	int	label_id;
	int	size;

	if (label_exists(arg, champion) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	++arg;
	label_id = get_label_id(arg, champion);
	assert(label_id != -1);
	diff = get_difference_in_bytes(id, label_id, champion);
	size = g_op_tab[(unsigned char)
		champion->tlines[id].command_index].labelsize;
	if (size == 2)
		ft_write_value_big_e2(champion->fdout, (unsigned short)diff);
	else if (size == 4)
		ft_write_value_big_e4(champion->fdout, (unsigned short)diff);
	else
	{
		ft_printf("Value of %s wasn't calculated\n", arg);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
