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

#include "../include/vm.h"

int				main(int argc, char **argv)
{
	t_core			core;

	core.map = init_map();
	core.players = init_players();
	core.process = init_process();
	core.flags = init_flags();

	if (!read_args(&core, argc, argv))
		return (0);
	insert_to_map(&core);
	core.flags->dump ? print_map(&core) : 0;
	// init_game(&core);
	// printf("%d\n", g_op_tab[1].arg[0]);
	// printf("%d\n", ft_to_bin(get_value_from_map(core.map, 1025, 1)));
	// print_debug(&core);
	return (0);
}
