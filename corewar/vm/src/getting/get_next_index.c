/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_index.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 16:33:37 by rhadiats          #+#    #+#             */
/*   Updated: 2017/12/28 16:33:38 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/vm.h"

int						get_next_index(t_process *process, unsigned char *map,
										int command, int value)
{
	int			index;
	int			step;

	index = 0;
	step = 0;
	ITER = -1;
	ft_bzero(process->args, MAX_ARGS_NUMBER);
	while (++ITER < g_op_tab[command - 1].count_args && ITER < MAX_ARGS_NUMBER)
	{
		if (g_op_tab[command - 1].codage_octal)
		{
			step = g_sizes[command - 1][value >> (6 - ITER * 2) & 3];
			ARGS[ITER].type = value >> (6 - ITER * 2) & 3;
			ARGS[ITER].arg = get_value_from_map(map, process->pc + 1 +
				g_op_tab[command - 1].codage_octal + index, step);
		}
		else
		{
			step = g_sizes[command - 1][2];
			ARGS[ITER].type = g_op_tab[command - 1].arg[ITER];
			ARGS[ITER].arg = get_value_from_map(map, process->pc + 1, step);
		}
		index += step;
	}
	return (index);
}
