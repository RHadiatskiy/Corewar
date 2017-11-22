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

void					parsing(t_core *info, unsigned char *data)
{
	int			i;
	int			j;

	i = -1;
	j = 0;
	while (++i < (int)info->data_len)
	{
		if (i >= (PROG_NAME_LENGTH) + (COMMENT_LENGTH) + 16)
			// res = (res << 8) | (((char *)buf)[j++] & 0x000000ff)
			info->map[j++] = (int)data[i];
	}
}
