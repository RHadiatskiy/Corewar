/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_tab_f.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemchuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 15:42:07 by bsemchuk          #+#    #+#             */
/*   Updated: 2018/03/11 18:52:14 by bsemchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

/*
**	Функція повертає індекс команди, або ж -1
*/

int			op_index(const char *cmd)
{
	int		i;

	i = 0;
	while (i < 17)
	{
		if (ft_strequ((const char *)g_op_tab[i].command, cmd))
			return (i);
		i++;
	}
	return (-1);
}
