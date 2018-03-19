/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_bytes_needed.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemchuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 17:51:17 by bsemchuk          #+#    #+#             */
/*   Updated: 2018/03/11 18:04:17 by bsemchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int		get_bytes_needed(t_line *tline)
{
	int	i;

	i = 0;
	if (tline->command_index > -1)
		tline->bytes_needed++;
	if (tline->command_index > -1 &&
			g_op_tab[(unsigned char)tline->command_index].codage)
		tline->bytes_needed++;
	if (tline->args)
		while (tline->args[i])
		{
			if (tline->args[i][0] == DIRECT_CHAR)
				tline->bytes_needed += g_op_tab[(unsigned char)
					tline->command_index].labelsize;
			else if (tline->args[i][0] == 'r')
				tline->bytes_needed++;
			else if (ft_isdigit(tline->args[i][0]) == YES ||
					tline->args[i][0] == '-' || tline->args[i][0] == LABEL_CHAR)
				tline->bytes_needed += 2;
			else
				return (EXIT_FAILURE);
			i++;
		}
	return (EXIT_SUCCESS);
}
