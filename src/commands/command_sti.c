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
	int offset;

	offset = ((sag + tag) % IDX_MOD);
	if (FLAGS->v && FLAGS->verbosity_four)
	{
		printf("P%5d | %s ", process->id, "sti");
		printf("r%d %d %d\n", ARGS[0].arg, sag, tag);
		printf("%8c -> store to %d + %d = ", '|', sag, tag);
		printf("%d (with pc and mod ", offset);
		printf("%d)\n", (process->pc + offset) % MEM_SIZE);
	}
}

int						command_sti(t_core *core, t_process *process)
{
	int		second_arg;
	int		third_arg;
	int		offset;

	second_arg = ARGS[1].type == IND_CODE ?
	(short)(get_value_from_map(MAP, ARGS[1].arg, 4)) : 0;
	second_arg = ARGS[1].type == REG_CODE ? REG[ARGS[1].arg - 1] : 0;
	second_arg = ARGS[1].type == DIR_CODE ? ARGS[1].arg : second_arg;
	third_arg = ARGS[2].type == REG_CODE ? REG[ARGS[2].arg - 1] : 0;
	third_arg = ARGS[2].type == DIR_CODE ? ARGS[2].arg : third_arg;
	offset = (process->pc + ((second_arg + third_arg) % IDX_MOD) % MEM_SIZE);
	put_value_on_the_map(MAP, offset, REG[ARGS[0].arg - 1]);
	print_flag_v(core, process, second_arg, third_arg);
	return (1);
}
