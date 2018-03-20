/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_players.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 17:33:43 by rhadiats          #+#    #+#             */
/*   Updated: 2017/12/28 17:33:44 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/vm.h"

static void				runing_processes(t_core *core, t_process *process)
{
	FLAGS->visual ? clear_counter(core, process) : 0;
	process->cycle++;
	run_processes(core, process);
	FLAGS->visual ? check_processes(core) : 0;
	FLAGS->visual ? draw_counter(core, process) : 0;
}

void					run_players(t_core *core)
{
	t_process		*process;

	while (core->current_cycle <= core->cycle_to_die)
	{
		process = core->process ? core->process : NULL;
		if (FLAGS->v && FLAGS->verbosity_two && CYCLE && !FLAGS->visual)
			ft_printf("It is now cycle %d\n", CYCLE);
		while (process)
		{
			runing_processes(core, process);
			process = process->next;
		}
		FLAGS->visual ? cycle_refresh(core) : 0;
		(FLAGS->visual && core->current_cycle % 75 == 0) ? refre_map(core) : 0;
		if (FLAGS->dump && CYCLE == FLAGS->dump_cycle && !FLAGS->visual)
		{
			print_map(core);
			break ;
		}
		CYCLE++;
		core->current_cycle++;
	}
}
