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

void					run(t_core *core)
{
	FLAGS->visual ? ncurses_version(core) : print_players(core->players);
	while (core->players_lives != 0)
	{
		if (core->players_lives >= NBR_LIVE || !core->max_checks)
		{
			core->max_checks = MAX_CHECKS;
			core->cycle_to_die -= CYCLE_DELTA;
			if (FLAGS->v && FLAGS->verbosity_two && !FLAGS->visual)
				ft_printf("Cycle to die is now %d\n", core->cycle_to_die);
			FLAGS->visual ? cycles_to_die_refresh(core->cycle_to_die) : 0;
		}
		core->players_lives = 0;
		(FLAGS->dump && FLAGS->dump_cycle  == 0 && !FLAGS->visual) ?
		print_map(core) : 0;
		(FLAGS->dump && FLAGS->dump_cycle == CYCLE && !FLAGS->visual) ?
		0 : run_players(core);
		reset_players_lives(core->players);
		kill_processes(core);
		core->current_cycle = 1;
		core->max_checks--;
	}
	if (FLAGS->visual)
		print_champ_visual(core);
	else
		FLAGS->dump ? 0 : print_champ(core);
}
