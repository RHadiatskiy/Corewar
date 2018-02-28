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

void					put_value_on_the_map(unsigned char *map, int start,
											int value)
{
	int				j;
	int				i;
	int				res;

	j = 4;
	while (j--)
	{
		i = 0;
		res = value;
		while (i++ < j)
			res = res >> 8;
		map[start] = (res & 0x000000ff);
		start++;
	}

}


// static void				color_map_live(t_core *core, t_process *process)
// {
// 	int		i;
// 	int 	x;
// 	int 	y;

// 	i = -1;
// 	position(PC, &x, &y);
// 	if (FLAGS->visual)
// 	{
// 		core->clr[PC] = process->player * -1;
// 		attron(COLOR_PAIR(process->player * -1) | A_BOLD);
// 		while (++i < STEP)
// 		{
// 			mvprintw(y, x, "%02x", MAP[PC + i]);
// 			x += 3;
// 		}
// 		attrset(A_NORMAL);
// 	}
// 	refresh();
// }
