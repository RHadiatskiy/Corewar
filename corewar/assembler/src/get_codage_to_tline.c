/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_codage_to_tline.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemchuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 18:04:33 by bsemchuk          #+#    #+#             */
/*   Updated: 2018/03/11 18:17:03 by bsemchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static int			set_argtype(t_line *tline,
		unsigned char *atype, int argument)
{
	if (tline->argtype[argument] & T_REG)
		(*atype) |= REG_CODE;
	else if (tline->argtype[argument] & T_DIR)
		(*atype) |= DIR_CODE;
	else if (tline->argtype[argument] & T_IND)
		(*atype) |= IND_CODE;
	else
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int					get_codage_to_tline(t_line *tline, t_champion *champion)
{
	int				argument;
	unsigned char	arg_type_flag;
	unsigned char	bits_to_shift;

	argument = 0;
	bits_to_shift = 6;
	while (tline->argtype[argument])
	{
		arg_type_flag = 0;
		if (set_argtype(tline, &arg_type_flag, argument) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		arg_type_flag <<= bits_to_shift;
		tline->command_codage |= arg_type_flag;
		if (validate_arg((unsigned char)tline->argtype[argument],
					(char *)tline->args[argument], champion) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		argument++;
		bits_to_shift -= 2;
	}
	return (EXIT_SUCCESS);
}
