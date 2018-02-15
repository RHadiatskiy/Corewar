/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_or.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 18:32:35 by rhadiats          #+#    #+#             */
/*   Updated: 2018/01/04 18:32:41 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/vm.h"

static void				print_flag_v(t_core *core, t_process *process,
									int farg, int sarg)
{
	if (FLAGS->v && FLAGS->verbosity_four)
	{
		printf("P%5d | %s ", process->id, "or");
		printf("%d %d r%d\n", farg, sarg, ARGS[2].arg);
	}
}

int						command_or(t_core *core, t_process *process)
{
	int		first_arg;
	int		second_arg;
	
	// printf("command or\n");
	first_arg = ARGS[0].type == IND_CODE ?
	get_value_from_map(MAP, ARGS[0].arg % IDX_MOD, 4) : 0;
	first_arg = ARGS[0].type == REG_CODE ? REG[ARGS[0].arg - 1] : first_arg;
	first_arg = ARGS[0].type == DIR_CODE ? ARGS[0].arg : first_arg;
	second_arg = ARGS[1].type == IND_CODE ?
	get_value_from_map(MAP, ARGS[1].arg % IDX_MOD, 4) : 0;
	second_arg = ARGS[1].type == REG_CODE ? REG[ARGS[1].arg - 1] : second_arg;
	second_arg = ARGS[1].type == DIR_CODE ? ARGS[1].arg : second_arg;
	if (ARGS[2].arg > 0 && ARGS[2].arg <= REG_NUMBER && ARGS[2].type == REG_CODE)
	{
		REG[ARGS[2].arg - 1] = first_arg | second_arg;
		process->carry = REG[ARGS[2].arg - 1] ? 0 : 1;
		print_flag_v(core, process, first_arg, second_arg);
	}
	return (1);
}
