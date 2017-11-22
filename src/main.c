/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 20:10:17 by rhadiats          #+#    #+#             */
/*   Updated: 2017/11/20 20:10:18 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/corewar.h"

int				main(int argc, char **argv)
{
	int			i;
	t_core		core;

	i = 1;
	while (i < argc && i < MAX_PLAYERS)
		if (!validation(argv[i++]))
			write(1, "error\n", 6);
	core.map = init_map();
	// print_map(core.map);

	return (0);
}
