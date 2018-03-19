/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flush_indir_char.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemchuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 17:47:21 by bsemchuk          #+#    #+#             */
/*   Updated: 2018/03/11 17:47:52 by bsemchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int		flush_indir_char(char *arg, t_champion *champion, unsigned id)
{
	int	diff;
	int	label_id;

	if (label_exists(arg, champion) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	++arg;
	label_id = get_label_id(arg, champion);
	assert(label_id != -1);
	diff = get_difference_in_bytes(id, label_id, champion);
	ft_write_value_big_e2(champion->fdout, (unsigned short)diff);
	return (EXIT_SUCCESS);
}
