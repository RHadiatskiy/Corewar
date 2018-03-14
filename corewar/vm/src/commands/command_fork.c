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

	position = process->pc + val;
	if (FLAGS->v && FLAGS->verbosity_four)
	{
		ft_printf("P %4d | %s ", process->id, "fork");
		ft_printf("%d (%d)\n", ARGS[0].arg, position);
	}
	if (FLAGS->v && FLAGS->verbosity_sixteen)
		pc_movements(core, process);
}

int						command_fork(t_core *core, t_process *process)
{
	int			value;

	value = 0;
	if (ARGS[0].type == DIR_CODE)
	{
		value = ARGS[0].arg % IDX_MOD;
		fork_process(&core->process, process, value);
		FLAGS->visual ? 0 : print_flag_v(core, process, value);
	}
	return (1);
}
