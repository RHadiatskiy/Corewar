/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argtypes_into_tline.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemchuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 16:48:06 by bsemchuk          #+#    #+#             */
/*   Updated: 2018/03/11 16:49:01 by bsemchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int		argtypes_into_tline(t_line *tline)
{
	int argument;

	argument = 0;
	while (tline->args[argument])
	{
		if (tline->args[argument][0] == 'r')
			tline->argtype[argument] |= T_REG;
		else if (ft_isdigit(tline->args[argument][0]) \
				|| tline->args[argument][0] == '-')
			tline->argtype[argument] |= T_IND;
		else if (tline->args[argument][0] == DIRECT_CHAR)
			tline->argtype[argument] |= T_DIR;
		else if (tline->args[argument][0] == LABEL_CHAR)
			tline->argtype[argument] |= T_LAB | T_IND;
		else
			return (EXIT_FAILURE);
		argument++;
	}
	return (EXIT_SUCCESS);
}
