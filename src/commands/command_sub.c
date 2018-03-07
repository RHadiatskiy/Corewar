/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_sub.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 18:31:27 by rhadiats          #+#    #+#             */
/*   Updated: 2018/01/04 18:31:29 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/vm.h"

static void				print_flag_v(t_core *core, t_process *process)
{
	int			i;

	i = -1;
	if (core->flags->v && core->flags->verbosity_four)
	{
		ft_printf("P%5d | %s ", process->id, "sub");
		ft_printf("r%d r%d ", process->args[0].arg, process->args[1].arg);
		ft_printf("r%d\n", process->args[2].arg);
	}
	if (FLAGS->v && FLAGS->verbosity_sixteen)
	{
		ft_printf("ADV %d ", STEP);
		ft_printf("(0x%.4x -> 0x%.4x) ", PC, PC + STEP);
		while (++i < STEP)
			ft_printf("%.2x ", MAP[PC + i]);
		ft_printf("\n");
	}
}

int						command_sub(t_core *core, t_process *process)
{
	if (ARGS[0].type == REG_CODE && ARGS[1].type == REG_CODE &&
		ARGS[2].type == REG_CODE &&
		ARGS[0].arg <= REG_NUMBER && ARGS[0].arg > 0 &&
		ARGS[1].arg <= REG_NUMBER && ARGS[1].arg > 0 &&
		ARGS[2].arg <= REG_NUMBER && ARGS[2].arg > 0)
	{
		REG[ARGS[2].arg - 1] = REG[ARGS[0].arg - 1] - REG[ARGS[1].arg - 1];
		process->carry = REG[ARGS[2].arg] ? 0 : 1;
	}
	print_flag_v(core, process);
	return (1);
}
