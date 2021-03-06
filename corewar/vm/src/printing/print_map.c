/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 17:20:17 by rhadiats          #+#    #+#             */
/*   Updated: 2018/01/08 17:20:18 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/vm.h"

void					print_map(t_core *core)
{
	unsigned char		*t_map;
	int					x;
	int					y;
	int					count;

	x = -1;
	count = 0;
	t_map = core->map;
	while (++x < sqrt(MEM_SIZE) && (x * y < MEM_SIZE))
	{
		y = -1;
		ft_printf("0x%.4x : ", count);
		while (++y < sqrt(MEM_SIZE) && (x * y < MEM_SIZE))
		{
			if (*t_map && core->flags->color)
				ft_printf("%s%.2x%s ", CYAN, *t_map++, RESET);
			else
				ft_printf("%.2x ", *t_map++);
			count++;
		}
		ft_printf("\n");
	}
}
