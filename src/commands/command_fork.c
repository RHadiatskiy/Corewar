/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_fork.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 18:35:26 by rhadiats          #+#    #+#             */
/*   Updated: 2018/01/04 18:35:29 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/vm.h"

static void				print_flag_v(t_core *core, t_process *process, int val)
{
	int			position;
	int			i;

	i = -1;
	position = (process->pc + val) % MEM_SIZE;
	position += position < 0 ? MEM_SIZE : 0;
	if (FLAGS->v && FLAGS->verbosity_four)
	{
		printf("P%5d | %s ", process->id, "fork");
		printf("%d (%d)\n", val, position);
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

int						command_fork(t_core *core, t_process *process)
{
	int			value;

	value = 0;
	if (ARGS[0].type == DIR_CODE)
	{
		value = ARGS[0].arg % IDX_MOD;
		fork_process(&core->process, process, value);
		print_flag_v(core, process, value);
	}
	return (1);
}
