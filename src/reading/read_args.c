/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 17:53:22 by rhadiats          #+#    #+#             */
/*   Updated: 2017/12/15 17:53:24 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/vm.h"

int						read_args(t_core *core, int ac, char **av)
{
	int					iter;

	iter = 1;
	if (ac < 2)
	{
		write(1, "usage: ...\n", 11);
		return (0);
	}		
	else if (ac > MAX_PLAYERS + 1)
	{
		write (1, "Too many champions\n", 19);
		return (0);
	}
	while (iter < ac && iter <= MAX_PLAYERS)
		if (!validation(core, av[iter++]))
			exit (0);
	return (1);
}
