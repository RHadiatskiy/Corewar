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

unsigned int			get_players_size(t_player *players)
{
	t_player		*iter;
	unsigned int	size;			

	size = 0;
	iter = players;
	while (iter)
	{
		size++;
		iter = iter->next;
	}
	return (size);
}

unsigned int			get_value_from_file(void *buf, unsigned int start, unsigned int len)
{
	unsigned int	res;

	res = 0;
	if (start < len)
	{
		while (start < len)
			res = (res << 8) | (((char *)buf)[start++] & 0x000000ff);
	}
	return (res);
}
