/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_st.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 18:30:30 by rhadiats          #+#    #+#             */
/*   Updated: 2018/01/04 18:30:32 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/vm.h"

static void				print_flag_v(t_core *core, t_process *process, int pos)
{
	int		offset;

	offset = pos - process->pc;
	if (FLAGS->v && FLAGS->verbosity_four)
	{
		printf("P%5d | %s ", process->id, "st");
		printf("r%d %d\n", ARGS[0].arg, offset);
	}
}

int						command_st(t_core *core, t_process *process)
{
	int			position;

	// printf("command st\n");
	position = (process->pc + ARGS[1].arg) % MEM_SIZE;
	if (ARGS[1].type == IND_CODE)
	{
		if (ARGS[0].arg < REG_NUMBER)
			put_value_on_the_map(MAP, position, REG[ARGS[0].arg - 1]);
	}
	else if (ARGS[1].type == REG_CODE)
	{
		if (ARGS[0].arg < REG_NUMBER)
			REG[ARGS[1].arg - 1] = REG[ARGS[0].arg - 1];
	}
	print_flag_v(core, process, position);
	return (1);
}
