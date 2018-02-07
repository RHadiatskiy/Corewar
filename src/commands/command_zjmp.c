/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_zjmp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 18:33:53 by rhadiats          #+#    #+#             */
/*   Updated: 2018/01/04 18:33:55 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/vm.h"

static void				print_flag_v(t_core *core, t_process *process,
									char *result, int position)
{
	if (core->flags->v && core->flags->verbosity_four)
	{
		printf("P%5d | %s ", process->id, "zjmp");
		printf("%d %s\n", position, result);
	}
	free(result);
}

int						command_zjmp(t_core *core, t_process *process)
{
	char	*result;
	int		position;

	result = process->carry ? ft_strdup("OK") : ft_strdup("FAILED");
	position = ARGS[0].arg % MEM_SIZE;
	process->pc = (process->pc + position) % MEM_SIZE;
	print_flag_v(core, process, result, position);
	return (1);
}
