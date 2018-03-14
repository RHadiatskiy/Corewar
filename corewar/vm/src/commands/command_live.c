/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 18:16:16 by rhadiats          #+#    #+#             */
/*   Updated: 2017/12/16 18:16:17 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/vm.h"

static void				print_flag_v_one(t_core *core, t_player *player)
{
	if (FLAGS->v && FLAGS->verbosity_one)
		ft_printf("Player %d (%s) is said to be alive\n",
				player->number, player->header->prog_name);
}

static void				print_flag_v_four(t_core *core, t_process *process)
{
	if (FLAGS->v && FLAGS->verbosity_four)
		ft_printf("P %4d | %s %d\n", process->id, "live", ARGS[0].arg);
}

static void				print_flag_v_sixteen(t_core *core, t_process *process)
{
	if (FLAGS->v && FLAGS->verbosity_sixteen)
		pc_movements(core, process);
}

static void				print_visual_life(t_core *core, t_player *player,
						t_process *process)
{
	int y;
	int i;

	y = 16;
	i = 1;
	if (FLAGS->visual)
	{
		while (player->number > i)
		{
			y += 5;
			i++;
		}
		attrset(A_NORMAL | A_BOLD);
		mvprintw(y, 230, "              ");
		mvprintw(y, 230, "%d", process->players_last_live);
		mvprintw(y + 1, 230, "              ");
		mvprintw(y + 1, 230, "%d", player->lives);
	}
	refresh();
}

int						command_live(t_core *core, t_process *process)
{
	t_player		*tmp;

	tmp = core->players ? core->players : NULL;
	process->is_live = 1;
	process->players_last_live = core->cycle;
	process->last_live = process->cycle;
	core->players_lives++;
	FLAGS->visual ? 0 : print_flag_v_four(core, process);
	while (tmp)
	{
		if (ARGS[0].arg * -1 == tmp->number)
		{
			tmp->lives++;
			tmp->lives_in_period++;
			FLAGS->visual ? 0 : print_flag_v_one(core, tmp);
			print_visual_life(core, tmp, process);
			core->champ = tmp;
			break ;
		}
		tmp = tmp->next;
	}
	FLAGS->visual ? 0 : print_flag_v_sixteen(core, process);
	return (1);
}
