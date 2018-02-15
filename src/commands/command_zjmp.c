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

static void				print_flag_v(t_core *core, t_process *proc, short pos)
{
	if (FLAGS->v && FLAGS->verbosity_four)
	{
		printf("P%5d | %s ", proc->id, "zjmp");
		printf("%d %s\n", pos, proc->carry ? "OK" : "FAILED");
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
