/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_add.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 18:30:59 by rhadiats          #+#    #+#             */
/*   Updated: 2018/01/04 18:31:00 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/vm.h"

static void				print_flag_v(t_core *core, t_process *process)
{
	if (core->flags->v && core->flags->verbosity_four)
	{
		printf("P%5d | %s ", process->id, "add");
		printf("r%d r%d ", process->args[0].arg, process->args[1].arg);
		printf("r%d\n", process->args[2].arg);
	}
}

int						command_add(t_core *core, t_process *process)
{
	process->carry = (REG[ARGS[2].arg] =
								REG[ARGS[0].arg] + REG[ARGS[1].arg]) ? 0 : 1;
	print_flag_v(core, process);
	return (1);
}
