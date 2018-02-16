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
	if (FLAGS->v && FLAGS->verbosity_four)
	{
		printf("P%5d | %s ", process->id, "lldi");
		printf("%d %d r%d\n", farg, sarg, ARGS[2].arg);
		printf("%8c -> load from %d + %d = ", '|', farg, sarg);
		printf("%d (with pc and mod ", offset);
		printf("%d)\n", (process->pc + offset) % MEM_SIZE);
	}
}

int						command_lldi(t_core *core, t_process *process)
{
	int		first_arg;
	int		second_arg;
	int		offset;

	first_arg = ARGS[0].type == IND_CODE ?
	get_value_from_map(MAP, ARGS[0].arg, 4) : 0;
	if (ARGS[0].arg <= REG_NUMBER && ARGS[0].arg > 0)
		first_arg = ARGS[0].type == REG_CODE ? REG[ARGS[0].arg - 1] : first_arg;
	first_arg = ARGS[0].type == DIR_CODE ? ARGS[0].arg : first_arg;
	second_arg = ARGS[1].type == REG_CODE ? REG[ARGS[1].arg - 1] : 0;
	second_arg = ARGS[1].type == DIR_CODE ? ARGS[1].arg : second_arg;
	offset = (first_arg + second_arg) % MEM_SIZE;
	if (ARGS[2].arg <= REG_NUMBER && ARGS[2].arg > 0)
	{
		REG[ARGS[2].arg - 1] = ARGS[2].type == REG_CODE ?
		offset : REG[ARGS[2].arg - 1];		
	}
	print_flag_v(core, process, first_arg, second_arg);
	return (1);
}