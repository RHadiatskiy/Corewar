/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pc_movements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 18:23:47 by rhadiats          #+#    #+#             */
/*   Updated: 2018/03/09 18:23:49 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/vm.h"

void					pc_movements(t_core *core, t_process *process)
{
	int			i;

	i = -1;
	ft_printf("ADV %d ", STEP);
	ft_printf("(0x%.4x -> 0x%.4x) ", PC % MEM_SIZE, (PC % MEM_SIZE) + STEP);
	while (++i < STEP)
		ft_printf("%.2x ", MAP[(PC + i) % MEM_SIZE]);
	ft_printf("\n");
}
