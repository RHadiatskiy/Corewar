/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 17:58:46 by rhadiats          #+#    #+#             */
/*   Updated: 2017/12/28 17:58:47 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/vm.h"

void					add_process(t_process *processes, int start_pc)
{
	t_process		*proc;
	t_process		*to_end;

	to_end = processes;
	if (processes->pc == -1)
	{
		processes->pc = 0;
		processes->reg[0] = -1;
	}
	else
	{
		proc = init_process();
		while (to_end->next)
			to_end = to_end->next;
		proc->pc = start_pc;
		proc->reg[0] = -((to_end->reg[0] * -1) + 1);
		to_end->next = proc;
		proc->next = NULL;
	}
}
