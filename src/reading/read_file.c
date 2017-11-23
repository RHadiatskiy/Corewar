/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 16:11:54 by rhadiats          #+#    #+#             */
/*   Updated: 2017/11/23 16:11:55 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/vm.h"

int						read_file(t_core *core, char *av)
{
	int					fd;
	unsigned int		len;
	unsigned char		*data;

	if ((fd = open(av, O_RDONLY)) < 0)
		perror ("can't open the file");
	len = lseek(fd, 0, SEEK_END);
	lseek(fd, 0, SEEK_SET);
	if (!(data = (unsigned char *)malloc(sizeof(unsigned char) * len + 1)))
		perror ("can't allocate a memory");
	if (!(read(fd, data, len)))
		perror ("can't reed the file");
	add_player(core->players, data, len);
	free(data);
	close(fd);
	return (1);
}
