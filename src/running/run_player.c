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
	int			cmd;
	int			codage;

	cmd = get_value_from_map(core->map, process->pc, 1);
	codage = get_value_from_map(core->map, process->pc + 1, 1);
	if (cmd != 0 && cmd <= 17 && g_op_tab[cmd - 1].codage_octal)
	{
		printf("command: %s\t\t", g_op_tab[cmd - 1].command);
		printf("pc: %x\t", core->map[process->pc]);
		printf("index: %d\t", process->pc);
		printf("next: %d\t\t", get_next_index(cmd, codage));
		printf("process: %d\t\n", process->reg[0]);
		process->pc += (2 + get_next_index(cmd, codage));
	}
	else if (cmd != 0 && cmd <= 17 && !g_op_tab[cmd - 1].codage_octal)
	{
		printf("command: %s\t\t", g_op_tab[cmd - 1].command);
		printf("pc: %x\t", core->map[process->pc]);
		printf("index: %d\t", process->pc);
		printf("next: %d\t\t", get_next_index(cmd, codage));
		printf("process: %d\t\n", process->reg[0]);
		process->pc += (1 + g_sizes[cmd - 1][2]);
	}
}
