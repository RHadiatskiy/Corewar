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

	while (core->current_cycle < core->cycle_to_die + 1)
	{
		if (core->flags->v && core->flags->verbosity == 2)
			printf("It is now cycle %d\n", core->cycle);
		process = core->process ? core->process : NULL;
		while (process)
		{
			run_player(core, process);
			process = process->next;
		}
		if (core->current_cycle == core->cycle_to_die)
		{
			core->cycle_to_die -= CYCLE_DELTA;
			core->current_cycle = 1;
			if (core->flags->v && core->flags->verbosity == 2)
				printf("Cycle to die is now %d\n", core->cycle_to_die);
		}
		core->cycle++;
		core->current_cycle++;
	}
}
