/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_all_info_we_can_into_array_of_tlines.          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemchuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 15:37:44 by bsemchuk          #+#    #+#             */
/*   Updated: 2018/03/12 15:39:28 by bsemchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

/*
**	Спочатку line обрізається зі сторін, потім видаляються
**	коми, після чого розбивається на двувимірний масив
**	Якщо режим дебагу увімкнений, виводиться інформація
**	(line, deintegrated)Після чого треба зробити вибір,
**	якщо перший елемент NAME_COMMAND || COMMENT_COMMAND,
**	то обробляємо як сказано, якщо немає нульового елементу,
**	то вважаємо її пустою, в іншому випадку спробуємо обробити
**	її як інструкцію після чого видаляємо виділену память,
**	окрім line -- він видаляється там де і виділяється
*/

int		get_all_info_we_can_into_array_of_tlines(t_line *tline)
{
	deintegrate_split_trim(tline);
	get_label_if_present(tline);
	get_command_index_and_label_args_pointer(tline);
	get_parg_and_pparg(tline);
	if (get_bytes_needed(tline) == EXIT_FAILURE)
	{
		ft_printf("Can not count size of id %d line: %s\n",
				tline->id, tline->line_content);
		return (EXIT_FAILURE);
	}
	print_debug(tline);
	return (EXIT_SUCCESS);
}
