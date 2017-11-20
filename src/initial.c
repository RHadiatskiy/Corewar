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

char					*init_map(void)
{
	char	*map;

	map = NULL;
	if (!(map = (char *)malloc(sizeof(char) * MEM_SIZE)))
		return (NULL);
	else
		ft_bzero(map, MEM_SIZE);
	return (map);
}
