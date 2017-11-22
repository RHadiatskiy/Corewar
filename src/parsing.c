/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 22:31:16 by rhadiats          #+#    #+#             */
/*   Updated: 2017/11/20 22:31:30 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/corewar.h"

void					parsing(t_core *info, char *data)
{
	int			i;
	int			j;

	i = -1;
	j = 0;
	while (++i < (MEM_SIZE))
	{
		if (i >= (PROG_NAME_LENGTH) + (COMMENT_LENGTH) + 16)
			info->map[j++] = (int)data[i];
	}
}
