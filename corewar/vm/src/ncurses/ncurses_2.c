/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ncurses_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daleksan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 11:47:36 by daleksan          #+#    #+#             */
/*   Updated: 2018/03/07 11:47:51 by daleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/vm.h"

void		cycles_to_die_refresh(int cycle_to_die)
{
	int		y;

	y = 45;
	attrset(A_NORMAL | A_BOLD);
	mvprintw(y, 215, "          ");
	mvprintw(y, 215, "%d", cycle_to_die);
	refresh();
}

char		*initiate_color(void)
{
	char	*clr;
	int		i;

	start_color();
	init_color(COLOR_MAGENTA, 192, 192, 192);
	init_color(COLOR_YELLOW, 700, 700, 0);
	init_pair(10, COLOR_WHITE, COLOR_MAGENTA);
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	init_pair(2, COLOR_BLUE, COLOR_BLACK);
	init_pair(3, COLOR_RED, COLOR_BLACK);
	init_pair(4, COLOR_YELLOW, COLOR_BLACK);
	init_pair(5, COLOR_WHITE, COLOR_BLACK);
	init_pair(6, COLOR_BLACK, COLOR_GREEN);
	init_pair(7, COLOR_BLACK, COLOR_BLUE);
	init_pair(8, COLOR_BLACK, COLOR_RED);
	init_pair(9, COLOR_BLACK, COLOR_YELLOW);
	init_pair(16, COLOR_MAGENTA, COLOR_MAGENTA);
	init_pair(11, COLOR_MAGENTA, COLOR_BLACK);
	clr = malloc(4096);
	i = 0;
	while (i < 4096)
		clr[i++] = 11;
	return (clr);
}

int			choose_players_color(t_player *players, char *clr, int players_num)
{
	int		pl;
	int		size;
	int		i;
	int		j;

	pl = 1;
	i = 0;
	size = 4096 / players_num;
	while (players)
	{
		attrset(A_NORMAL);
		j = i;
		while (j - i < (int)players->header->prog_size)
			clr[j++] = pl;
		players = players->next;
		i += size;
		pl++;
	}
	return (0);
}

int			create_borders(void)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (x < COL + 8)
	{
		mvaddch(0, x, ' ' | COLOR_PAIR(10));
		mvaddch(ROW - 1, x++, ' ' | COLOR_PAIR(10));
	}
	while (y < ROW)
	{
		mvaddch(y, 0, ' ' | COLOR_PAIR(10));
		mvaddch(y, COL - 45, ' ' | COLOR_PAIR(10));
		mvaddch(y++, COL + 8, ' ' | COLOR_PAIR(10));
	}
	refresh();
	return (0);
}

int			fullfill_map(t_core *core, int players)
{
	int		x;
	int		y;
	int		i;

	x = 0;
	y = 2;
	i = 0;
	attron(COLOR_PAIR(10));
	attron(A_BOLD);
	mvprintw(0, 95, "COREWAR");
	attroff(A_BOLD);
	choose_players_color(core->players, core->clr, players);
	attrset(A_NORMAL);
	while (i < 4096)
	{
		x += 3;
		attron(COLOR_PAIR(core->clr[i]));
		mvprintw(y, x, "%02x", core->map[i]);
		attrset(A_NORMAL);
		if (x > COL - 50 && !(x = 0))
			y++;
		i++;
	}
	refresh();
	return (0);
}
