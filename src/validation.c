/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 22:40:08 by rhadiats          #+#    #+#             */
/*   Updated: 2017/11/20 22:40:10 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/corewar.h"

static int				valid_magic(char *data)
{
	(void)data;
	return (1);
}

// static int				valid_prog_name(int data)
// {
// 	(void)data;
// 	return (1);
// }

// static int				valid_prog_size(int data)
// {
// 	(void)data;
// 	return (1);
// }

// static int				valid_comment(int data)
// {
// 	(void)data;
// 	return (1);
// }

int						validation(char *av)
{
	int			fd;
	char		data[BUF_SIZE];

	if ((fd = open(av, O_RDONLY)) < 0)
		return (0);
	if (!(read(fd, data, BUF_SIZE)))
		return (0);

	if (!valid_magic(data))
		return (0);
	return (1);
}
