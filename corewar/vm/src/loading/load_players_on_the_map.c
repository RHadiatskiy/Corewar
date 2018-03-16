/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 22:28:39 by rhadiats          #+#    #+#             */
/*   Updated: 2017/11/28 22:28:40 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/vm.h"

void					load_players_on_the_map(t_core *core)
{
	t_player		*player;
	int				i;
	int				j;

	player = (core->players && core->players->id) ? core->players : NULL;
	while (player)
	{
		i = -1;
		j = ((MEM_SIZE) / get_players_size(core->players)) * (player->id - 1);
		if (core->map && player->header)
		{
			while (++i < (int)player->header->prog_size)
				core->map[j++] = player->header->prog[i];
		}
		player = player->next;
	}
}
