/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 20:44:11 by rhadiats          #+#    #+#             */
/*   Updated: 2017/11/22 20:44:14 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/vm.h"

void					print_map(unsigned char *map)
{
	unsigned char		*t_map;
	int					x;
	int					y;

	x = -1;
	t_map = map;
	while (++x < sqrt(MEM_SIZE) && (x * y < MEM_SIZE))
	{
		y = -1;
		while (++y < sqrt(MEM_SIZE) && (x * y < MEM_SIZE))
			if (*t_map)
				printf("%s%.2x%s ", CYAN, *t_map++, RESET);
			else
				printf("%.2x ", *t_map++);
		printf("\n");
	}
}

void					print_data(t_player *players)
{
	t_player			*t_player;
	unsigned char		*t_data;
	int					x;
	int					y;

	t_player = players;
	while (t_player)
	{
		x = (int)t_player->data_len % (FORMAT) == 0 ? -1 : -2;
		t_data = t_player->data;
		while (++x < (int)t_player->data_len / (FORMAT))
		{
			y = -1;
			while (++y < FORMAT)
			{
				if (*t_data)
					printf("%s%.2x%s ", RED, *t_data++, RESET);
				else
					printf("%.2x ", *t_data++);
			}
			printf("\n");
		}
		printf("\n");
		t_player = t_player->next;
	}
}

void					print_players(t_player *players)
{
	t_player	*tmp;

	tmp = players;
	printf("--------------PLAYERS--------------\n");
	while (tmp)
	{
		printf("ID:\t\t%d\n", tmp->id);
		printf("LEN:\t\t%d\n", tmp->data_len);
		tmp = tmp->next;
		printf("-----------------------------------\n");
	}
}
