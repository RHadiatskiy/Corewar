/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 19:41:17 by rhadiats          #+#    #+#             */
/*   Updated: 2017/12/28 19:41:18 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/vm.h"

void					run_player(t_core *core, t_process *process)
{
	int			octal;
	int			pc;

	STEP = 0;
	pc = PC;
	CMD = get_value_from_map(MAP, PC, 1);
	CODAGE = get_value_from_map(MAP, PC + 1, 1);
	octal = g_op_tab[CMD - 1].codage_octal;
	if (CMD != 0 && CMD < 17)
	{
		if (process->cycles_to_exec == g_op_tab[CMD - 1].cycles)
		{
			process->cycles_to_exec = 1;
			pc += (1 + octal + get_next_index(process, MAP, CMD, CODAGE));
			STEP += (1 + octal + get_next_index(process, MAP, CMD, CODAGE));
			get_command_from_array(core, process, CMD);
			PC = (CMD == 9 && process->carry == 1) ? PC : pc;
			PC %= MEM_SIZE;
			PC += PC < 0 ? MEM_SIZE : 0;
		}
		else
			process->cycles_to_exec++;
	}
	else
		PC++;
}
