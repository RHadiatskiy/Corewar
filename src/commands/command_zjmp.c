/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_zjmp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 18:33:53 by rhadiats          #+#    #+#             */
/*   Updated: 2018/01/04 18:33:55 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/vm.h"

static void				print_flag_v(t_core *core, t_process *process, short p)
{
	int			i;

	i = -1;
	if (FLAGS->v && FLAGS->verbosity_four)
	{
		printf("P%5d | %s ", process->id, "zjmp");
		printf("%d %s\n", p, process->carry ? "OK" : "FAILED");
	}
	if (FLAGS->v && FLAGS->verbosity_sixteen)
	{
		printf("ADV %d ", STEP);
		printf("(0x%.4x -> 0x%.4x) ", PC, p);
		while (++i < STEP - 1)
			printf("%.2x ", MAP[PC + i]);
		printf("%.2x\n", MAP[PC + STEP - 1]);
	}
}

int						command_zjmp(t_core *core, t_process *process)
{
	short		position;

	position = ARGS[0].arg;
	position %= MEM_SIZE;
	process->pc = (process->pc + position) % MEM_SIZE;
	process->pc += process->pc < 0 ? MEM_SIZE : 0;
	print_flag_v(core, process, position);
	return (1);
}
