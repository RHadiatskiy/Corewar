/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 15:47:10 by rhadiats          #+#    #+#             */
/*   Updated: 2018/01/08 15:47:12 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/vm.h"

void				check_processes(t_core *core)
{
	int i;
	int y;
	t_process *tmp;

	i = 0;
	tmp = core->process ? core->process : NULL;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	y = 11;
	mvprintw(y, 212, "          ");
	mvprintw(y, 212, "%d", i);
	refresh();
}

void					run(t_core *core)
{
	FLAGS->visual ? ncurses_version(core) : 0;
	while (core->players_lives != 0)
	{
		core->players_lives = 0;
		FLAGS->dump && FLAGS->dump_cycle == 0 ? print_map(core) : 0;
		FLAGS->dump && FLAGS->dump_cycle == CYCLE ? 0 : run_processes(core);
		reset_players_lives(core->players);
		kill_processes(core);
		check_processes(core);
		core->current_cycle = 1;
		core->max_checks--;
		if (core->players_lives >= NBR_LIVE || !core->max_checks)
		{
			core->max_checks = MAX_CHECKS;
			core->cycle_to_die -= CYCLE_DELTA;
			
			if (FLAGS->v && FLAGS->verbosity_two)
				printf("Cycle to die is now %d\n", core->cycle_to_die);
			FLAGS->visual ? cycles_to_die_refresh(core->cycle_to_die) : 0;
		}
	}
	if (FLAGS->visual)
		print_champ_visual(core);
	else
		FLAGS->dump ? 0 : print_champ(core);
}
