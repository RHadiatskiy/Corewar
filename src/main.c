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
	t_core			*core;

	core = init_core();
	if (read_args(core, argc, argv))
	{
		load_processes(core);
		insert_to_map(core);
		core->flags->dump ? print_map(core) : 0;

		// print_debug(core);
		// print_processes(core->process);
	}
	return (0);
}
