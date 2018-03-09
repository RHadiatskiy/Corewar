/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_st.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 18:30:30 by rhadiats          #+#    #+#             */
/*   Updated: 2018/01/04 18:30:32 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/vm.h"

static void				print_flag_v(t_core *core, t_process *process)
{
	if (FLAGS->v && FLAGS->verbosity_four &&
		ARGS[0].arg <= REG_NUMBER && ARGS[0].arg > 0)
	{
		ft_printf("P%5d | %s ", process->id, "st");
		ft_printf("r%d %d\n", ARGS[0].arg, ARGS[1].arg);
	}
	if (FLAGS->v && FLAGS->verbosity_sixteen)
		pc_movements(core, process);
}

int						command_st(t_core *core, t_process *process)
{
	int			position;

	position = (PC + (ARGS[1].arg % IDX_MOD)) % MEM_SIZE;
	position += position < 0 ? MEM_SIZE : 0;
	if (ARGS[1].type == IND_CODE)
	{
		if (ARGS[0].arg <= REG_NUMBER && ARGS[0].arg > 0)
			put_value_on_the_map(core, position, REG[ARGS[0].arg - 1], process);
	}
	else if (ARGS[1].type == REG_CODE)
	{
		if (ARGS[0].arg <= REG_NUMBER && ARGS[0].arg > 0 &&
			ARGS[1].arg <= REG_NUMBER && ARGS[1].arg > 0)
			REG[ARGS[1].arg - 1] = REG[ARGS[0].arg - 1];
	}
	print_flag_v(core, process);
	return (1);
}
