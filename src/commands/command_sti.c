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

int						command_sti(t_core *core, t_process *process)
{
	printf("command: %s\t\t", g_op_tab[10].command);
	printf("pc: %x\t", core->map[process->pc]);
	printf("index: %d\t", process->pc);
	printf("cycle: %d\t", core->cycle);
	printf("process: %d\t\n", process->reg[0]);
	return (0);
}
