/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 19:22:16 by rhadiats          #+#    #+#             */
/*   Updated: 2018/02/15 19:22:17 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/vm.h"

void					fork_process(t_process **processes,
										t_process *process, int value)
{
	t_process		*cp_process;

	if ((cp_process = (t_process *)malloc(sizeof(t_process))))
	{
		cp_process->pc = (process->pc + value) % MEM_SIZE;
		cp_process->pc += cp_process->pc < 0 ? MEM_SIZE : 0;
		cp_process->player = process->player;
		cp_process->reg = process->reg;
		cp_process->id = (*processes)->id + 1;
		cp_process->cycle = process->cycle;
		cp_process->carry = process->carry;
		cp_process->is_live = process->is_live;
		cp_process->cycles_to_exec = process->cycles_to_exec;
		cp_process->args = process->args;
		cp_process->next = (*processes);
		(*processes) = cp_process;
	}
}
