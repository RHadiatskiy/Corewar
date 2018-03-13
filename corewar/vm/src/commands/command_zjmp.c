/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_zjmp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 18:33:53 by rhadiats          #+#    #+#             */
/*   Updated: 2018/01/04 18:33:55 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/vm.h"

static void				print_flag_v(t_core *core, t_process *process,
									short position, int pc_before)
{
	int			i;

	i = -1;
	if (FLAGS->v && FLAGS->verbosity_four)
	{
		ft_printf("P%5d | %s ", process->id, "zjmp");
		ft_printf("%d %s\n", position, process->carry ? "OK" : "FAILED");
	}
	if (FLAGS->v && FLAGS->verbosity_sixteen && !process->carry)
	{
		ft_printf("ADV %d ", STEP);
		ft_printf("(0x%.4x -> 0x%.4x) ", pc_before, pc_before + STEP);
		while (++i < STEP)
			ft_printf("%.2x ", MAP[(pc_before + i) % MEM_SIZE]);
		ft_printf("\n");
	}
}

int						command_zjmp(t_core *core, t_process *process)
{
	short		position;
	int			pc_before;

	if (ARGS[0].type == DIR_CODE)
	{
		pc_before = PC;
		position = (short)ARGS[0].arg;
		position %= MEM_SIZE;
		PC = (PC + (position % IDX_MOD)) % MEM_SIZE;
		PC += PC < 0 ? MEM_SIZE : 0;
		print_flag_v(core, process, position, pc_before);
	}
	return (1);
}
