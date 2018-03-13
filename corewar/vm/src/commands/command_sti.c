/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_sti.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 18:34:49 by rhadiats          #+#    #+#             */
/*   Updated: 2018/01/04 18:34:50 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/vm.h"

static void				print_flag_v(t_core *core, t_process *process,
									int sag, int tag)
{
	int		offset;

	offset = ((sag + tag) % IDX_MOD);
	if (FLAGS->v && FLAGS->verbosity_four &&
		ARGS[0].arg <= REG_NUMBER && ARGS[0].arg > 0 &&
		((ARGS[1].type == REG_CODE &&
			ARGS[1].arg <= REG_NUMBER && ARGS[1].arg > 0) ||
			ARGS[1].type == DIR_CODE || ARGS[1].type == IND_CODE) &&
		((ARGS[2].type == REG_CODE &&
			ARGS[2].arg <= REG_NUMBER && ARGS[2].arg > 0) ||
			ARGS[2].type == DIR_CODE))
	{
		ft_printf("P%5d | %s ", process->id, "sti");
		ft_printf("r%d %d %d\n", ARGS[0].arg, sag, tag);
		ft_printf("%8c -> store to %d + %d = ", '|', sag, tag);
		ft_printf("%d (with pc and mod ", sag + tag);
		ft_printf("%d)\n", (process->pc + offset) % MEM_SIZE);
	}
	if (FLAGS->v && FLAGS->verbosity_sixteen)
		pc_movements(core, process);
}

static int				get_value_ind(unsigned char *map, int pc, int arg)
{
	int		index;

	index = (pc + (arg % IDX_MOD)) % MEM_SIZE;
	index += index < 0 ? MEM_SIZE : 0;
	return (get_value_from_map(map, index, 4));
}

int						command_sti(t_core *core, t_process *process)
{
	int		sarg;
	int		targ;
	int		offset;

	sarg = ARGS[1].type == IND_CODE ?
	(short)(get_value_ind(MAP, PC, ARGS[1].arg)) : 0;
	if (ARGS[1].arg <= REG_NUMBER && ARGS[1].arg > 0)
		sarg = ARGS[1].type == REG_CODE ? REG[ARGS[1].arg - 1] : 0;
	sarg = ARGS[1].type == DIR_CODE ? ARGS[1].arg : sarg;
	if (ARGS[2].arg <= REG_NUMBER && ARGS[2].arg > 0)
		targ = ARGS[2].type == REG_CODE ? REG[ARGS[2].arg - 1] : 0;
	targ = ARGS[2].type == DIR_CODE ? ARGS[2].arg : targ;
	offset = ((PC + ((sarg + targ) % IDX_MOD)) % MEM_SIZE);
	offset += offset < 0 ? MEM_SIZE : 0;
	if (ARGS[0].arg <= REG_NUMBER && ARGS[0].arg > 0 &&
		((ARGS[1].type == REG_CODE &&
			ARGS[1].arg <= REG_NUMBER && ARGS[1].arg > 0) ||
			ARGS[1].type == DIR_CODE || ARGS[1].type == IND_CODE) &&
		((ARGS[2].type == REG_CODE &&
			ARGS[2].arg <= REG_NUMBER && ARGS[2].arg > 0) ||
			ARGS[2].type == DIR_CODE))
		put_value_on_the_map(core, offset, REG[ARGS[0].arg - 1], process);
	print_flag_v(core, process, sarg, targ);
	return (1);
}
