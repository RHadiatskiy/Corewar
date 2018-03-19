/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_argument_types.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemchuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 19:22:10 by bsemchuk          #+#    #+#             */
/*   Updated: 2018/03/11 19:22:45 by bsemchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int			validate_arguments_types(t_line *tline)
{
	int		argument;

	argument = 0;
	while (tline->args[argument])
	{
		if (tline->argtype[argument] & \
			g_op_tab[(char unsigned)tline->command_index].argsflags[argument])
			argument++;
		else
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
