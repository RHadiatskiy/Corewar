/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 20:46:13 by rhadiats          #+#    #+#             */
/*   Updated: 2017/11/20 20:46:14 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/corewar.h"

void					print_map(char *map)
{
	int			x;
	int			y;

	x = 0;
	while (x < sqrt(MEM_SIZE) && (x * y < MEM_SIZE))
	{
		y = 0;
		while (y < sqrt(MEM_SIZE) && (x * y < MEM_SIZE))
			ft_printf("%.2x ", map[y++]);
		ft_printf("%.2x\n", map[y]);
		x++;
	}
}
