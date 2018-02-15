/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_xor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 18:33:09 by rhadiats          #+#    #+#             */
/*   Updated: 2018/01/04 18:33:10 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/vm.h"

static void				print_flag_v(t_core *core, t_process *process,
									int farg, int sarg)
{
	if (FLAGS->v && FLAGS->verbosity_four)
	{
		printf("P%5d | %s ", process->id, "xor");
		printf("%d %d r%d\n", farg, sarg, ARGS[2].arg);
	}
}

int						command_xor(t_core *core, t_process *process)
{
	int		first_arg;
	int		second_arg;

	// printf("command xor\n");
	first_arg = ARGS[0].type == IND_CODE ?
	get_value_from_map(MAP, ARGS[0].arg % IDX_MOD, 4) : 0;
	first_arg = ARGS[0].type == REG_CODE ? REG[ARGS[0].arg - 1] : first_arg;
	first_arg = ARGS[0].type == DIR_CODE ? ARGS[0].arg : first_arg;
	second_arg = ARGS[1].type == IND_CODE ?
	get_value_from_map(MAP, ARGS[1].arg % IDX_MOD, 4) : 0;
	second_arg = ARGS[1].type == REG_CODE ? REG[ARGS[1].arg - 1] : second_arg;
	second_arg = ARGS[1].type == DIR_CODE ? ARGS[1].arg : second_arg;
	REG[ARGS[2].arg - 1] = ARGS[2].type == REG_CODE ?
	first_arg ^ second_arg : REG[ARGS[2].arg - 1];
	process->carry = REG[ARGS[2].arg - 1] ? 0 : 1;
	print_flag_v(core, process, first_arg, second_arg);
	return (1);
}
