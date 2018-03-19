/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments_validation_and_codage_writing.c          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemchuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 19:01:55 by bsemchuk          #+#    #+#             */
/*   Updated: 2018/03/11 19:03:23 by bsemchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

/*
**	Тут перевірка на те чи дозволений взагалі тип аргументу який зайшов
** 	00 00 00 01 -- регістр
** 	00 00 00 10 -- прямий
** 	00 00 00 11 -- непрямий
**	01 10 11 00 -- приклад кодажу де перший
**			регістр, другий прямий, і третій аргумент непрямий, четвертого немає
*/

int			arguments_validation_and_codage_writing(t_line *tline,
					t_champion *champion)
{
	if (g_op_tab[(unsigned char)tline->command_index].argsmax != tline->nargs)
		return (EXIT_FAILURE);
	if (tline->nargs != (unsigned)(ft_nchar(tline->parg, SEPARATOR_CHAR) + 1))
		return (EXIT_FAILURE);
	if (argtypes_into_tline(tline) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (validate_arguments_types(tline) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (get_codage_to_tline(tline, champion) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
