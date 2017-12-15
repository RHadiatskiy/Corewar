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
	if (!read_args(&core, argc, argv))
		return (0);
	insert_to_map(&core);
	// print_headers(core.players);
	// print_data(core.players);
	print_map(core.map);
	init_game(&core);
	return (0);
}
