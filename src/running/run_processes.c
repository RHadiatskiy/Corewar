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

void					run_processes(t_core *core)
{
	t_process		*process;

	while (core->current_cycle < core->cycle_to_die)
	{
		if (FLAGS->v && FLAGS->verbosity_two)
			printf("It is now cycle %d\n", core->cycle);
		if (core->flags->dump && core->cycle == core->flags->dump_cycle)
		{
			print_map(core);
			printf("cycle: %d\n", core->cycle);
			break ;
		}
		process = core->process ? core->process : NULL;
		while (process)
		{
			run_player(core, process);
			process = process->next;
		}
		core->cycle++;
		core->current_cycle++;
	}
}
