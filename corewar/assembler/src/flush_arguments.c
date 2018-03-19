/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flush_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemchuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 15:41:52 by bsemchuk          #+#    #+#             */
/*   Updated: 2018/03/12 16:12:32 by bsemchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

/*
**	Values are written in wrong order
**	04.02.18 no more in wrong order, it's ok
*/

static int	flush_one_arguments_loop(t_line *tline,
		t_champion *champion, int *i)
{
	while (tline->args[(*i)])
	{
		if (ft_startswithchar((char *)tline->args[(*i)], 'r'))
			flush_reg((char *)tline->args[(*i)], champion);
		else if (ft_isdigit(tline->args[(*i)][0]) ||
				ft_startswithchar((char *)tline->args[(*i)], LABEL_CHAR)
				|| tline->args[(*i)][0] == '-')
		{
			if (flush_ind((char *)tline->args[(*i)],
						champion, tline->id) == EXIT_FAILURE)
				return (EXIT_FAILURE);
		}
		else if (ft_startswithchar((char *)tline->args[(*i)], '%'))
		{
			if (flush_dir((char *)tline->args[(*i)], champion,
						tline->command_index, tline->id) == EXIT_FAILURE)
				return (EXIT_FAILURE);
		}
		else
			return (EXIT_FAILURE);
		(*i)++;
	}
	return (EXIT_SUCCESS);
}

int			flush_arguments(t_line *tline, t_champion *champion)
{
	int	i;

	i = 0;
	if (g_op_tab[(unsigned char)tline->command_index].codage)
		write(champion->fdout, &tline->command_codage, 1);
	flush_one_arguments_loop(tline, champion, &i);
	return (EXIT_SUCCESS);
}
