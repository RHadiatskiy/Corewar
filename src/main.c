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
	int				i;
	t_core			core;

	i = 1;
	core.map = init_map();
	core.players = init_players();
	if (!read_args(&core, argc, argv))
	{
		write(1, "error\n", 6);
		return (0);
	}
	parsing(&core);
	print_data(core.players);
	print_map(core.map);
	return (0);
}
