/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_players_size.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 17:16:01 by rhadiats          #+#    #+#             */
/*   Updated: 2017/11/23 17:16:02 by rhadiats         ###   ########.fr       */
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
