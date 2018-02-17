/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_ldi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 18:34:20 by rhadiats          #+#    #+#             */
/*   Updated: 2018/01/04 18:34:21 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/vm.h"

static void				print_flag_v(t_core *core, t_process *process,
									int farg, int sarg)
{
	int		offset;
	int		i;

	i = -1;
	offset = ((farg + sarg) % IDX_MOD);
	if (FLAGS->v && FLAGS->verbosity_four)
	{
		printf("P%5d | %s ", process->id, "ldi");
		printf("%d %d r%d\n", farg, sarg, ARGS[2].arg);
		printf("%8c -> load from %d + %d = ", '|', farg, sarg);
		printf("%d (with pc and mod ", offset);
		printf("%d)\n", (process->pc + offset) % MEM_SIZE);
	}
	if (FLAGS->v && FLAGS->verbosity_sixteen)
	{
		printf("ADV %d ", STEP);
		printf("(0x%.4x -> 0x%.4x) ", PC, PC + STEP);
		while (++i < STEP)
			printf("%.2x ", MAP[PC + i]);
		printf("\n");
	}
}

int						command_ldi(t_core *core, t_process *process)
{
	int		first_arg;
	int		second_arg;
	int		offset;

	first_arg = ARGS[0].type == IND_CODE ?
	get_value_from_map(MAP, ARGS[0].arg % IDX_MOD, 4) : 0;
	if (ARGS[0].arg <= REG_NUMBER && ARGS[0].arg > 0)
		first_arg = ARGS[0].type == REG_CODE ? REG[ARGS[0].arg - 1] : first_arg;
	first_arg = ARGS[0].type == DIR_CODE ? ARGS[0].arg : first_arg;
	second_arg = ARGS[1].type == REG_CODE ? REG[ARGS[1].arg - 1] : 0;
	second_arg = ARGS[1].type == DIR_CODE ? ARGS[1].arg : second_arg;
	offset = ((first_arg + second_arg) % IDX_MOD) % MEM_SIZE;
	if (ARGS[2].arg <= REG_NUMBER && ARGS[2].arg > 0)
	{
		REG[ARGS[2].arg - 1] = ARGS[2].type == REG_CODE ?
		offset : REG[ARGS[2].arg - 1];		
	}
	print_flag_v(core, process, first_arg, second_arg);
	return (1);
}
