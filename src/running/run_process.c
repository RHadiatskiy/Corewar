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

// void					run_process(t_core *core)
// {
// 	t_process		*processes;

// 	processes = core->process ? core->process : NULL;
// 	while (processes)
// 	{
// 		while (processes->pc < core->cycle_to_die)
// 		{

// 		}
// 		process = process->next;
// 	}
// }

void					load_processes(t_core *core)
{
	t_player		*iter;
	unsigned int	size;

	size = get_players_size(core->players);
	iter = core->players ? core->players : NULL;
	while (iter)
	{
		add_process(core->process, ((MEM_SIZE) / size) * (iter->id - 1));
		iter = iter->next;
	}
}
