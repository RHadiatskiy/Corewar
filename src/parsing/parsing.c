/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 22:31:16 by rhadiats          #+#    #+#             */
/*   Updated: 2017/11/20 22:31:30 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/vm.h"

void					parsing(t_core *core)
{
	t_player	*tmplay;
	int			i;
	int			j;

	tmplay = core->players;
	while (tmplay)
	{
		i = -1;
		j = ((MEM_SIZE) / get_players_size(core->players)) * (tmplay->id - 1);
		while (++i < (int)tmplay->data_len)
		{
			if (i >= (PROG_NAME_LENGTH) + (COMMENT_LENGTH) + 16)
				// res = (res << 8) | (((char *)buf)[j++] & 0x000000ff)
				core->map[j++] = tmplay->data[i];
		}
		tmplay = tmplay->next;
	}
}
