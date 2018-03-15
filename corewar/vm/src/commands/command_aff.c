/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_aff.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 18:37:18 by rhadiats          #+#    #+#             */
/*   Updated: 2018/01/04 18:37:19 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/vm.h"

int						command_aff(t_core *core, t_process *process)
{
	if (core->flags->aff && ARGS[0].type == REG_CODE && !FLAGS->visual)
	{
		if (ARGS[0].arg <= REG_NUMBER && ARGS[0].arg > 0)
			ft_printf("Aff: %c\n", REG[ARGS[0].arg - 1] % 256);
	}
	if (FLAGS->v && FLAGS->verbosity_sixteen && !FLAGS->visual)
		pc_movements(core, process);
	return (1);
}
