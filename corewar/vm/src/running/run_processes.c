/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_processes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 19:41:17 by rhadiats          #+#    #+#             */
/*   Updated: 2017/12/28 19:41:18 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/vm.h"

static void				move_pc(t_process *process)
{
	PC++;
	CMD = 0;
}

static void				set_pc(t_process *process, int pc)
{
	PC = (CMD == 9 && process->carry == 1) ? PC : pc;
	PC %= MEM_SIZE;
	PC += PC < 0 ? MEM_SIZE : 0;
	CMD = 0;
	STEP = 0;
}

void					run_processes(t_core *core, t_process *process)
{
	int			pc;

	STEP = 0;
	pc = PC;
	CMD = CMD ? CMD : get_value_from_map(MAP, PC, 1);
	if (CMD != 0 && CMD < 17)
	{
		OCTAL = g_op_tab[CMD - 1].codage_octal;
		if (process->cycles_to_exec == g_op_tab[CMD - 1].cycles)
		{
			CODAGE = get_value_from_map(MAP, PC + 1, 1);
			process->cycles_to_exec = 1;
			STEP += (1 + OCTAL + get_next_index(process, MAP, CMD, CODAGE));
			pc += STEP;
			get_command_from_array(core, process, CMD);
			set_pc(process, pc);
		}
		else
			process->cycles_to_exec++;
	}
	else
		move_pc(process);
}
