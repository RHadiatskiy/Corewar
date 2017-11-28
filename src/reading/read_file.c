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

int						read_args(t_core *core, int ac, char **av)
{
	int					iter;

	iter = 1;
	if (ac < 2 || ac > MAX_PLAYERS + 1)
	{
		write (1, "invalid number of parameters\n", 29);
		return (0);
	}
	while (iter < ac && iter <= MAX_PLAYERS)
		if (!validation(core, av[iter++]))
			exit (0);
	return (1);
}

int						read_file(t_core *core, char *av)
{
	int					fd;
	unsigned int		len;
	unsigned char		*data;
	t_header			*header;

	if ((fd = open(av, O_RDONLY)) < 0)
		return (-1);
	len = lseek(fd, 0, SEEK_END);
	lseek(fd, 0, SEEK_SET);
	if (!(data = (unsigned char *)malloc(sizeof(unsigned char) * len + 1)))
		return (-2);
	if (!(read(fd, data, len)))
		return (-3);
	if (!(header = parse_header(data, len)))
		return (-4);
	else
		add_player(core->players, header, data, len);
	close(fd);
	return (1);
}
