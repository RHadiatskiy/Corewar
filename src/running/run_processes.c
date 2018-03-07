/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 17:33:43 by rhadiats          #+#    #+#             */
/*   Updated: 2017/12/28 17:33:44 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/vm.h"

void				run_processes(t_core *core)
{
	t_process		*process;

	while (core->current_cycle <= core->cycle_to_die)
	{
		if (FLAGS->v && FLAGS->verbosity_two && CYCLE != 0)
			ft_printf("It is now cycle %d\n", CYCLE);
		FLAGS->visual ? cycle_refresh(core) : 0;
		process = core->process ? core->process : NULL;
		(FLAGS->visual && core->current_cycle % 75 == 0) ? refre_map(core) : 0;
		while (process)
		{
			FLAGS->visual ? clear_counter(core, process) : 0;
			process->cycle++;
			run_player(core, process);
			FLAGS->visual ? draw_counter(core, process) : 0;
			process = process->next;
		}
		if (FLAGS->dump && CYCLE == FLAGS->dump_cycle)
		{
			print_map(core);
			break ;
		}
		CYCLE++;
		core->current_cycle++;
	}
}
