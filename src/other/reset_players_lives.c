/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_players_lives.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 16:08:04 by rhadiats          #+#    #+#             */
/*   Updated: 2018/01/08 16:08:06 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/vm.h"

void				reset_players_lives(t_player *players)
{
	t_player		*tmp;
	int				y;
	int				i;

	y = 16;
	i = 1;
	tmp = players ? players : NULL;
	while (tmp)
	{
		tmp->lives = 0;
		while (tmp->number > i)
		{
			y += 5;
			i++;
		}
		attron(A_BOLD);
		mvprintw(y + 1, 230, "              ");
		mvprintw(y + 1, 230, "%d", tmp->lives);
		attroff(A_BOLD);
		tmp = tmp->next;
	}
	refresh();
}
