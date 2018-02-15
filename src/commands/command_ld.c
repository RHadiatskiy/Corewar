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

static void				print_flag_v(t_core *core, t_process *process, int val)
{
	if (FLAGS->v && FLAGS->verbosity_four)
	{
		printf("P%5d | %s ", process->id, "ld");
		printf("%d r%d\n", val, ARGS[1].arg);
	}
}

int						command_ld(t_core *core, t_process *process)
{
	int		position;

	// printf("command ld\n");
	position = (process->pc + ARGS[0].arg) % MEM_SIZE;
	if (ARGS[0].type == DIR_CODE)
	{
		if (ARGS[1].arg <= REG_NUMBER && ARGS[1].arg > 0)
			REG[ARGS[1].arg - 1] = ARGS[0].arg;
	}
	else if (ARGS[0].type == IND_CODE)
	{
		if (ARGS[1].arg <= REG_NUMBER && ARGS[1].arg > 0)
			REG[ARGS[1].arg - 1] = get_value_from_map(MAP, position, 4);
	}
	process->carry = (ARGS[0].arg == 0) ? 1 : 0;
	print_flag_v(core, process, REG[ARGS[1].arg - 1]);
	return (1);
}
