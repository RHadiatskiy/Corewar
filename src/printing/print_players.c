/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_players.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 17:22:06 by rhadiats          #+#    #+#             */
/*   Updated: 2018/01/08 17:22:07 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/vm.h"

void					print_champ(t_core *core)
{
	printf("Contestant %d, \"%s\", has won !\n", core->champ->number,
												core->champ->header->prog_name);
}

void					print_champ_visual(t_core *core)
{
	int 	y;

	y = 53;
	attrset(A_NORMAL);
	attron(A_BOLD);
	mvprintw(y, 200, "The winner is : ");
	attron(COLOR_PAIR(core->champ->number));
	mvprintw(y, 216, "%s", core->champ->header->prog_name);
	attroff(COLOR_PAIR(core->champ->number));
	mvprintw(y + 2, 200, "Press any key to quit.");
	attroff(A_BOLD);
	while (getch() == -1)
		;
	endwin();
}

void					print_players(t_player *players)
{
	t_player	*tmp_player;

	tmp_player = players ? players : NULL;
	if (tmp_player)
	{
		printf("Introducing contestants...\n");
		while (tmp_player)
		{
			printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n", \
				tmp_player->number, tmp_player->header->prog_size, \
				tmp_player->header->prog_name, tmp_player->header->comment);
			tmp_player = tmp_player->next;
		}
	}
}
