/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 20:25:57 by rhadiats          #+#    #+#             */
/*   Updated: 2017/11/20 20:25:58 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/corewar.h"

unsigned char				*init_map(void)
{
	unsigned char		*map;

	map = NULL;
	if (!(map = (unsigned char *)malloc(sizeof(unsigned char) * MEM_SIZE + 1)))
		return (NULL);
	else
		ft_bzero(map, MEM_SIZE);
	return (map);
}
