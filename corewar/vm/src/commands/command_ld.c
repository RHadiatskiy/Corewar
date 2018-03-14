/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_ld.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 18:29:46 by rhadiats          #+#    #+#             */
/*   Updated: 2018/01/04 18:29:48 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/vm.h"

static void				print_flag_v(t_core *core, t_process *process)
{
	if (FLAGS->v && FLAGS->verbosity_four && ARGS[1].type == REG_CODE &&
		ARGS[1].arg <= REG_NUMBER && ARGS[1].arg > 0)
	{
		ft_printf("P %4d | %s ", process->id, "ld");
		ft_printf("%d r%d\n", REG[ARGS[1].arg - 1], ARGS[1].arg);
	}
	if (FLAGS->v && FLAGS->verbosity_sixteen)
		pc_movements(core, process);
}

int						command_ld(t_core *core, t_process *process)
{
	int		position;

	position = (process->pc + (ARGS[0].arg % IDX_MOD)) % MEM_SIZE;
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
	FLAGS->visual ? 0 : print_flag_v(core, process);
	return (1);
}
