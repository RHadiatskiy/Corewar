/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   offset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemchuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 15:42:01 by bsemchuk          #+#    #+#             */
/*   Updated: 2018/03/12 16:13:28 by bsemchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include "../includes/asm.h"

int			where_is_my_offset(int fd, off_t *offset)
{
	off_t	off;

	assert(offset);
	off = lseek(fd, 0L, SEEK_CUR);
	if (off == -1)
		return (EXIT_FAILURE);
	*offset = off;
	return (EXIT_SUCCESS);
}
