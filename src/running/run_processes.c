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
	int				i;

	i = 0;
	while (core->cycle < core->cycle_to_die)
	{
		process = core->process ? core->process : NULL;
		while (process)
		{
			run_player(core, process);
			process = process->next;
		}
		core->cycle++;
	}
}
