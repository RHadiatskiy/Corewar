/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_add.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 18:30:59 by rhadiats          #+#    #+#             */
/*   Updated: 2018/01/04 18:31:00 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/vm.h"

// int						command_add(t_core *core, t_process *process)
// {
// 	if (core->flags->v && core->flags->verbosity_four)
// 	{
// 		printf("command: %s\t\t", g_op_tab[3].command);
// 		printf("pc: %x\t", core->map[process->pc]);
// 		printf("index: %d\t", process->pc);
// 		printf("cycle: %d\t", core->cycle);
// 		printf("reg[0]: %d\t\n", process->reg[0]);
// 	}
// 	return (0);
// }

static void				print_flag_v(t_core *core, t_process *process)
{
	if (core->flags->v && core->flags->verbosity_four)
	{
		printf("P%5d | %s ", process->id, "add");
		printf("r%d r%d ", process->args[0].arg, process->args[1].arg);
		printf("r%d\n", process->args[2].arg);
	}
}

int						command_add(t_core *core, t_process *process)
{
	int		first_arg;
	int		second_arg;

	first_arg = get_value_from_map(MAP, REG[ARGS[0].arg], 4);
	second_arg = get_value_from_map(MAP, REG[ARGS[1].arg], 4);
	process->carry = (REG[ARGS[2].arg] = first_arg + second_arg) ? 0 : 1;
	print_flag_v(core, process);
	return (1);
}
