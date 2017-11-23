/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 16:41:23 by rhadiats          #+#    #+#             */
/*   Updated: 2017/11/23 16:41:25 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/vm.h"

void					add_player(t_player *players, unsigned char *data, \
	unsigned int data_len)
{
	t_player		*player;
	t_player		*to_end;

	to_end = players;
	if (players->id == 0)
	{
		players->id = 1;
		players->data = data;
		players->data_len = data_len;
	}
	else if ((player = (t_player *)malloc(sizeof(t_player))))
	{
		while (to_end->next)
			to_end = to_end->next;
		player->id = to_end->id + 1;
		player->data = data;
		player->data_len = data_len;
		to_end->next = player;
		player->next = NULL;
	}
}