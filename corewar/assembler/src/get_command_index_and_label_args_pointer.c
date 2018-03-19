/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_command_index_and_label_args_pointer.          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemchuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 18:17:34 by bsemchuk          #+#    #+#             */
/*   Updated: 2018/03/11 18:18:42 by bsemchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	get_command_index_and_label_args_pointer(t_line *tline)
{
	int command_position;

	command_position = 0;
	tline->command_index = -1;
	if (ft_endswithchar((const char *)
				tline->deintegrated_line[0], LABEL_CHAR) == YES)
		command_position = 1;
	if (tline->deintegrated_line[command_position])
	{
		tline->command_index =
			(char)op_index((const char *)
					tline->deintegrated_line[command_position]);
		if (tline->command_index > -1)
			tline->cmd = &tline->deintegrated_line[command_position];
	}
}
