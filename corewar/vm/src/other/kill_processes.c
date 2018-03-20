/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 17:17:08 by rhadiats          #+#    #+#             */
/*   Updated: 2018/03/19 20:21:06 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/vm.h"

static void				free_process(t_core *core, t_process *process)
{
	if (core->flags->v && core->flags->verbosity_eight)
	{
		ft_printf("Process %d hasn't lived for", process->id);
		ft_printf(" %d cycles ", (process->cycle) - process->last_live);
		ft_printf("(CTD %d)\n", core->cycle_to_die);
	}
	process->reg ? free(process->reg) : 0;
	process->args ? free(process->args) : 0;
	process ? free(process) : 0;
	core->count_processes ? core->count_processes-- : 0;
}

static void				free_kill_proc(int i)
{
	if (i <= 20)
		system("afplay -t 0.8 src/sounds/gunshot.mp3");
	else
		system("afplay -t 1 src/sounds/explosion.mp3");
}

static void				set_live_off(t_process **current, t_process **prew)
{
	(*current)->is_live = 0;
	(*prew) = (*current);
}

void					kill_processes(t_core *core)
{
	t_process		*prew;
	t_process		*current;
	t_process		*next;
	int				i;

	prew = NULL;
	current = core->process ? core->process : NULL;
	next = core->process->next ? core->process->next : NULL;
	while (current)
	{
		if (!current->is_live && !(i = 0))
		{
			free_process(core, current);
			if (prew)
				prew->next = next;
			else
				core->process = next;
			i++;
		}
		else
			set_live_off(&current, &prew);
		current = next;
		next = next ? next->next : NULL;
	}
	(FLAGS->visual && i > 0) ? free_kill_proc(i) : 0;
}
