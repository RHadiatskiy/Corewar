/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_lld.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 18:35:56 by rhadiats          #+#    #+#             */
/*   Updated: 2018/01/04 18:35:57 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/vm.h"

static void				print_flag_v(t_core *core, t_process *process, int val)
{
	if (FLAGS->v && FLAGS->verbosity_four &&
		ARGS[1].arg > 0 && ARGS[1].arg <= REG_NUMBER)
	{
		ft_printf("P%5d | %s ", process->id, "lld");
		ft_printf("%d r%d\n", val, ARGS[1].arg);
	}
	if (FLAGS->v && FLAGS->verbosity_sixteen)
		pc_movements(core, process);
}

int						command_lld(t_core *core, t_process *process)
{
	int		position;

	position = (process->pc + ARGS[0].arg) % MEM_SIZE;
	position += position < 0 ? MEM_SIZE : 0;
	if (ARGS[0].type == DIR_CODE && ARGS[1].type == REG_CODE)
	{
		if (ARGS[1].arg <= REG_NUMBER && ARGS[1].arg > 0)
		{
			REG[ARGS[1].arg - 1] = ARGS[0].arg;
			process->carry = REG[ARGS[1].arg - 1] ? 0 : 1;
		}
	}
	else if (ARGS[0].type == IND_CODE && ARGS[1].type == REG_CODE)
	{
		if (ARGS[1].arg <= REG_NUMBER && ARGS[1].arg > 0)
		{
			REG[ARGS[1].arg - 1] = get_value_from_map(MAP, position, 4);
			process->carry = REG[ARGS[1].arg - 1] ? 0 : 1;
		}
	}
	print_flag_v(core, process, REG[ARGS[1].arg - 1]);
	return (1);
}
