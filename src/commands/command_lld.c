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
	int			i;

	i = -1;
	if (FLAGS->v && FLAGS->verbosity_four)
	{
		printf("P%5d | %s ", process->id, "lld");
		printf("%d r%d\n", val, ARGS[1].arg);
	}
	if (FLAGS->v && FLAGS->verbosity_sixteen)
	{
		printf("ADV %d ", STEP);
		printf("(0x%.4x -> 0x%.4x) ", PC, PC + STEP);
		while (++i < STEP)
			printf("%.2x ", MAP[PC + i]);
		printf("\n");
	}
}

int						command_lld(t_core *core, t_process *process)
{
	int		position;

	position = (process->pc + ARGS[0].arg) % MEM_SIZE;
	if (ARGS[0].type == DIR_CODE && ARGS[1].type == REG_CODE)
	{
		if (ARGS[1].arg <= REG_NUMBER && ARGS[1].arg > 0)
			REG[ARGS[1].arg - 1] = ARGS[0].arg;
	}
	else if (ARGS[0].type == IND_CODE && ARGS[1].type == REG_CODE)
	{
		if (ARGS[1].arg <= REG_NUMBER && ARGS[1].arg > 0)
			REG[ARGS[1].arg - 1] = get_value_from_map(MAP, position, 4);
	}
	process->carry = (ARGS[0].arg == 0) ? 1 : 0;
	print_flag_v(core, process, REG[ARGS[1].arg - 1]);
	return (1);
}
