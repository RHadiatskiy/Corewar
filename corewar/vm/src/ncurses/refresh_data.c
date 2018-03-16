/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daleksan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 11:54:35 by daleksan          #+#    #+#             */
/*   Updated: 2018/03/07 11:54:37 by daleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/vm.h"

void			key_code(t_core *core, int ch)
{
	attrset(A_NORMAL | A_BOLD);
	if (ch == 113)
	{
		if (core->speed_num < 19)
		{
			core->speed /= 2;
			core->speed_num++;
			mvprintw(6, 208, "        ");
			mvprintw(6, 208, "%d", core->speed_num);
		}
	}
	if (ch == 119)
	{
		if (core->speed_num > 0)
		{
			core->speed *= 2;
			core->speed_num--;
			mvprintw(6, 208, "       ");
			mvprintw(6, 208, "%d", core->speed_num);
		}
	}
	if (ch == 27)
		exit_mode();
}

void			pause_vm(t_core *core)
{
	int			ch;

	while (1)
	{
		ch = getch();
		attron(COLOR_PAIR(4));
		mvprintw(3, 217, "                           ");
		mvprintw(3, 217, "** PAUSED **");
		if (ch == 32)
		{
			mvprintw(3, 217, "             ");
			mvprintw(3, 217, "** RUNNING **");
			attroff(COLOR_PAIR(4));
			break ;
		}
		if (ch == 113 || ch == 119 || ch == 27)
			key_code(core, ch);
	}
}

void			cycle_refresh(t_core *core)
{
	int			y;
	int			ch;

	y = 8;
	attrset(A_NORMAL | A_BOLD);
	mvprintw(y, 208, "%d", CYCLE);
	refresh();
	usleep(core->speed);
	ch = getch();
	if (ch == 27)
		exit_mode();
	else if (ch == 32)
		pause_vm(core);
}

void			check_processes(t_core *core)
{
	int			i;
	t_process	*tmp;

	i = 0;
	tmp = core->process ? core->process : NULL;
	while (tmp)
	{
		++i;
		tmp = tmp->next;
	}
	attron(A_BOLD);
	mvprintw(11, 212, "          ");
	mvprintw(11, 212, "%d", i);
	attroff(A_BOLD);
	refresh();
}

int				refre_map(t_core *core)
{
	int			x;
	int			y;
	int			i;

	x = 0;
	y = 2;
	i = 0;
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
