/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getting_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 13:20:10 by rhadiats          #+#    #+#             */
/*   Updated: 2017/11/27 13:20:11 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/vm.h"

static void	color_map_changes(t_core *core, int start, t_process *process)
{
	int		x;
	int		y;
	int		i;

	i = 0;
	position(start, &x, &y);
	while (i < 4)
	{
		if (start + i >= 4096)
		{
			x = 3;
			y = 2;
			start = 0 - i;
		}
		core->clr[start + i] = process->player * -1;
		attron(COLOR_PAIR(process->player * -1));
		attron(A_BOLD);
		mvprintw(y, x, "%02x", MAP[start + i]);
		if (x > COL - 50 && !(x = 0))
			y++;
		x += 3;
		i++;
	}
	attrset(A_NORMAL);
	refresh();
}

void		put_value_on_the_map(t_core *core, int start, int value,
			t_process *process)
{
	int		j;
	int		i;
	int		res;

	j = 4;
	while (j--)
	{
		i = 0;
		res = value;
		while (i++ < j)
			res = res >> 8;
		MAP[start % MEM_SIZE] = (res & 0x000000ff);
		start++;
	}
	FLAGS->visual ? color_map_changes(core, start - 4, process) : 0;
}
