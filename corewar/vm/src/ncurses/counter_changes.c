/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counter_changes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daleksan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 11:58:57 by daleksan          #+#    #+#             */
/*   Updated: 2018/03/07 11:58:59 by daleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/vm.h"

void	exit_mode(void)
{
	endwin();
	exit(1);
}

int		position(int pc, int *x, int *y)
{
	if (pc > 4095 || pc < 0)
		return (0);
	*x = (pc % 64) * 3 + 3;
	*y = (pc / 64) + 2;
	return (1);
}

void	draw_counter(t_core *core, t_process *process)
{
	int	x;
	int	y;

	position(PC, &x, &y);
	attron(COLOR_PAIR(core->clr[PC] + 5));
	mvprintw(y, x, "%02x", core->map[PC]);
	attroff(COLOR_PAIR(core->clr[PC] + 5));
	attrset(A_NORMAL);
	refresh();
}

void	clear_counter(t_core *core, t_process *process)
{
	int	x;
	int	y;

	position(PC, &x, &y);
	attrset(A_NORMAL);
	attron(COLOR_PAIR(core->clr[PC]));
	mvprintw(y, x, "%02x", core->map[PC]);
	attroff(COLOR_PAIR(core->clr[PC]));
	refresh();
}
