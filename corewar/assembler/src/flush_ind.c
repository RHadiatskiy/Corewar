/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flush_ind.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemchuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 17:45:44 by bsemchuk          #+#    #+#             */
/*   Updated: 2018/03/11 17:46:46 by bsemchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int			flush_ind(char *arg, t_champion *champion, unsigned id)
{
	int		res;

	if (arg[0] == LABEL_CHAR)
	{
		if (flush_indir_char(arg, champion, id) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		return (EXIT_SUCCESS);
	}
	else if (ft_isdigit(arg[0]) || arg[0] == '-')
	{
		res = ft_atoi(arg);
		ft_write_value_big_e2(champion->fdout, (unsigned short)res);
	}
	return (EXIT_SUCCESS);
}
