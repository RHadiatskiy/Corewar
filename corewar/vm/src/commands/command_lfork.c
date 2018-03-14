/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_lfork.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 18:36:49 by rhadiats          #+#    #+#             */
/*   Updated: 2018/01/04 18:36:50 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/vm.h"

static void				print_flag_v(t_core *core, t_process *process, int val)
{
	int		position;

	position = PC + val;
	if (FLAGS->v && FLAGS->verbosity_four)
	{
		ft_printf("P %4d | %s ", process->id, "lfork");
		ft_printf("%d (%d)\n", val, position);
	}
	if (FLAGS->v && FLAGS->verbosity_sixteen)
		pc_movements(core, process);
}

int						command_lfork(t_core *core, t_process *process)
{
	if (ARGS[0].type == DIR_CODE)
	{
		fork_process(&core->process, process, ARGS[0].arg);
		FLAGS->visual ? 0 : print_flag_v(core, process, ARGS[0].arg);
	}
	return (1);
}
