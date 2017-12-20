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

	int i = 0;
	while (i + 1 < MEM_SIZE)
	{
		if (g_op_tab[get_value_from_map(core.map, i, 1) - 1].codage_octal)
		{
			printf("command : %s\tpc : %x\tindex : %d\n", g_op_tab[get_value_from_map(core.map, i, 1) - 1].command, core.map[i], i);
			// printf("next index = %d\n", get_next_index(get_value_from_map(core.map, i, 1) - 1, get_value_from_map(core.map, i + 1, 1)));
			i += (2 + get_next_index(get_value_from_map(core.map, i, 1) - 1, get_value_from_map(core.map, i + 1, 1)));
		}
		else
		{
			printf("command : %s\tpc : %x\tindex : %d\n", g_op_tab[get_value_from_map(core.map, i, 1) - 1].command, core.map[i], i);
			i += (1 + g_sizes[get_value_from_map(core.map, i, 1) - 1][2]);
		}
	}
	return (0);
}
