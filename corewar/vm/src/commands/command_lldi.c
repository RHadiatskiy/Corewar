/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_lldi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 18:36:20 by rhadiats          #+#    #+#             */
/*   Updated: 2018/01/04 18:36:22 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/vm.h"

static void				print_flag_v(t_core *core, t_process *process,
									int farg, int sarg)
{
	int		offset;

	offset = farg + sarg;
	if (FLAGS->v && FLAGS->verbosity_four &&
		((ARGS[0].type == REG_CODE &&
			ARGS[0].arg <= REG_NUMBER && ARGS[0].arg > 0) ||
			ARGS[0].type == DIR_CODE || ARGS[0].type == IND_CODE) &&
		((ARGS[1].type == REG_CODE && ARGS[1].arg <= REG_NUMBER &&
			ARGS[1].arg > 0) || ARGS[1].type == DIR_CODE) &&
		ARGS[2].arg > 0 && ARGS[2].arg <= REG_NUMBER)
	{
		ft_printf("P %4d | %s ", process->id, "lldi");
		ft_printf("%d %d r%d\n", farg, sarg, ARGS[2].arg);
		ft_printf("%8c -> load from %d + %d = ", '|', farg, sarg);
		ft_printf("%d (with pc and mod ", farg + sarg);
		ft_printf("%d)\n", (process->pc + offset) % MEM_SIZE);
	}
	if (FLAGS->v && FLAGS->verbosity_sixteen)
		pc_movements(core, process);
}

static int				get_value_from_ind(unsigned char *map, int arg)
{
	int		index;

	index = arg % MEM_SIZE;
	index += index < 0 ? MEM_SIZE : 0;
	return (get_value_from_map(map, index, 4));
}

int						command_lldi(t_core *core, t_process *process)
{
	int		farg;
	int		sarg;
	int		offset;

	farg = ARGS[0].type == IND_CODE ? get_value_from_ind(MAP, ARGS[0].arg) : 0;
	if (ARGS[0].arg <= REG_NUMBER && ARGS[0].arg > 0)
		farg = ARGS[0].type == REG_CODE ? REG[ARGS[0].arg - 1] : farg;
	farg = ARGS[0].type == DIR_CODE ? ARGS[0].arg : farg;
	sarg = ARGS[1].type == REG_CODE ? REG[ARGS[1].arg - 1] : 0;
	sarg = ARGS[1].type == DIR_CODE ? ARGS[1].arg : sarg;
	offset = (farg + sarg) % MEM_SIZE;
	offset += offset < 0 ? MEM_SIZE : 0;
	if (ARGS[2].arg <= REG_NUMBER && ARGS[2].arg > 0 &&
		ARGS[2].type == REG_CODE &&
		((ARGS[0].type == REG_CODE &&
			ARGS[0].arg <= REG_NUMBER && ARGS[0].arg > 0) ||
			ARGS[0].type == DIR_CODE || ARGS[0].type == IND_CODE) &&
		((ARGS[1].type == REG_CODE && ARGS[1].arg <= REG_NUMBER &&
			ARGS[1].arg > 0) || ARGS[1].type == DIR_CODE))
	{
		REG[ARGS[2].arg - 1] = get_value_from_map(MAP, offset, 4);
		process->carry = REG[ARGS[2].arg - 1] ? 0 : 1;
	}
	FLAGS->visual ? 0 : print_flag_v(core, process, farg, sarg);
	return (1);
}
