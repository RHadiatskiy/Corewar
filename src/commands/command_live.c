/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 18:16:16 by rhadiats          #+#    #+#             */
/*   Updated: 2017/12/16 18:16:17 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/vm.h"

int						command_live(t_core *core, t_process *process)
{
	printf("command: %s\t\t", g_op_tab[0].command);
	printf("pc: %x\t", core->map[process->pc]);
	printf("index: %d\t", process->pc);
	printf("cycle: %d\t", core->cycle);
	printf("process: %d\t\n", process->reg[0]);
	return (0);
}
