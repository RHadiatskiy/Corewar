/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 20:25:57 by rhadiats          #+#    #+#             */
/*   Updated: 2017/11/20 20:25:58 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/vm.h"

unsigned char			*init_map(void)
{
	unsigned char		*map;

	map = NULL;
	if (!(map = (unsigned char *)malloc(sizeof(unsigned char) * MEM_SIZE + 1)))
		return (NULL);
	else
		ft_bzero(map, MEM_SIZE);
	return (map);
}

t_player				*init_players(void)
{
	t_player			*player;

	if (!(player = (t_player *)malloc(sizeof(t_player))))
		return (NULL);
	player->id = 0;
	player->number = 0;
	player->size = 0;
	player->header = NULL;
	player->next = NULL;
	return (player);
}

t_header				*init_header(unsigned int magic, char *name, char *comment, char *prog)
{
	t_header			*header;

	if (!(header = (t_header *)malloc(sizeof(t_header))))
		return (NULL);
	header->magic = magic;
	header->prog_name = name;
	header->comment = comment;
	header->prog = prog;
	header->prog_size = 0;
	return (header);
}

t_process				*init_process(void)
{
	t_process			*process;

	if (!(process = (t_process *)malloc(sizeof(t_process))))
		return (NULL);
	process->pc = -1;
	process->reg = (int *)malloc(sizeof(int) * REG_NUMBER);
	ft_bzero(process->reg, REG_NUMBER);
	process->carry = 0;
	process->next = NULL;
	return (process);
}

t_flags					*init_flags(void)
{
	t_flags				*flags;

	if (!(flags = (t_flags *)malloc(sizeof(t_flags))))
		return (NULL);
	flags->dump = 0;
	flags->dump_cycle = 0;
	flags->number = 0;
	flags->n = 0;
	return (flags);
}

t_core					*init_core(void)
{
	t_core				*core;

	if (!(core = (t_core *)malloc(sizeof(t_core))))
		return (NULL);
	core->map = init_map();
	core->cycle = 0;
	core->cycle_to_die = CYCLE_TO_DIE;
	core->players = init_players();
	core->process = init_process();
	core->flags = init_flags();
	return (core);
}