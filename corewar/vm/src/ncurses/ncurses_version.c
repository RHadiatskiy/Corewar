/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ncurses_version.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daleksan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 11:50:56 by daleksan          #+#    #+#             */
/*   Updated: 2018/03/07 11:51:01 by daleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/vm.h"

void	print_const_part(t_core *core)
{
	attrset(A_NORMAL | A_BOLD);
	mvprintw(6, 200, "Speed : %d", core->speed_num);
	mvprintw(45, 200, "CYCLE_TO_DIE : %d", core->cycle_to_die);
	mvprintw(45 + 2, 200, "CYCLE_DELTA : 50");
	mvprintw(45 + 4, 200, "NBR_LIVES : 21");
	mvprintw(45 + 6, 200, "MAX_CHECKS : %d", core->max_checks);
	mvprintw(62, 201, "Q to fasten speed in pause mode");
	mvprintw(63, 201, "W to slowen speed in pause mode");
	mvprintw(64, 201, "Press ESC to exit program");
	refresh();
}

int		fullfill_players_on_map(int players_num, t_player *players,
		t_core *core)
{
	int	y;
	int	pl;

	pl = 1;
	y = 8;
	attrset(A_NORMAL | A_BOLD);
	mvprintw(y, 200, "Cycle : %d", CYCLE);
	mvprintw(y + 3, 200, "Processes : %d", core->process->id);
	while (pl < players_num + 1 && pl < 5)
	{
		mvprintw(y + 7, 200, "Player %d :", players->number * -1);
		attron(COLOR_PAIR(players->number));
		mvprintw(y + 7, 212, "%-.37s", players->header->prog_name);
		attroff(COLOR_PAIR(players->number));
		mvprintw(y + 8, 202, "Last live : ");
		mvprintw(y + 8, 230, "%d", core->process->last_live);
		mvprintw(y + 9, 202, "Lives in current period : ");
		mvprintw(y + 9, 230, "%d", players->lives);
		y += 5;
		pl++;
		players = players->next;
	}
	print_const_part(core);
	refresh();
	return (0);
}

void	draw_map(int players, t_core *core)
{
	curs_set(0);
	nodelay(stdscr, TRUE);
	noecho();
	keypad(stdscr, true);
	create_borders();
	fullfill_map(core, players);
	fullfill_players_on_map(players, core->players, core);
	pause_vm(core);
}

int		ncurses_version(t_core *core)
{
	int	num;

	initscr();
	core->clr = initiate_color();
	num = get_players_size(core->players);
	draw_map(num, core);
	return (0);
}
