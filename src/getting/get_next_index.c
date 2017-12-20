/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_index.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 21:22:59 by rhadiats          #+#    #+#             */
/*   Updated: 2017/12/20 21:23:00 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/vm.h"

int						get_next_index(int command, int value)
{
	int			index;

	index = 0;
	index += g_sizes[command][value >> 6];
	index += g_sizes[command][value >> 4 & 3];
	index += g_sizes[command][value >> 2 & 3];
	index += g_sizes[command][value & 3];
	return (index);
}