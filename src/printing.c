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

#include "../include/corewar.h"

void					print_map(unsigned char *map)
{
	int			x;
	int			y;

	x = -1;
	while (++x < sqrt(MEM_SIZE) && (x * y < MEM_SIZE))
	{
		y = -1;
		while (++y < sqrt(MEM_SIZE) && (x * y < MEM_SIZE))
			ft_printf("%.2x ", *map++);
		ft_printf("\n");
	}
}

void					print_data(unsigned char *data, unsigned int len)
{
	int			x;
	int			y;

	x = -1;
	while (++x < (int)len / (FORMAT))
	{	
		y = -1;
		while (++y < FORMAT)
			ft_printf("%.2x ", *data++);
		ft_printf("\n");
	}
	ft_printf("\n");
}
