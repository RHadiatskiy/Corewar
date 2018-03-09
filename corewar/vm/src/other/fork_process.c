/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 19:22:16 by rhadiats          #+#    #+#             */
/*   Updated: 2018/02/15 19:22:17 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/vm.h"

static void				copy_process(t_process *new, t_process *old, int value)
{
	int		i;

	i = -1;
	new->pc = (old->pc + value) % MEM_SIZE;
	new->pc += new->pc < 0 ? MEM_SIZE : 0;
	new->player = old->player;
	while (++i < REG_NUMBER)
		new->reg[i] = old->reg[i];
	new->carry = old->carry;
	new->is_live = old->is_live;
	new->cycles_to_exec = old->cycles_to_exec;
	i = -1;
	while (++i < MAX_ARGS_NUMBER)
	{
		new->args[i].arg = old->args[i].arg;
		new->args[i].type = old->args[i].type;
	}
}

void					fork_process(t_process **processes,
										t_process *process, int value)
{
	t_process		*cp_process;

	if (process)
	{
		cp_process = init_process();
		copy_process(cp_process, process, value);
		cp_process->id = (*processes)->id + 1;
		cp_process->next = (*processes);
		(*processes) = cp_process;
	}
}
