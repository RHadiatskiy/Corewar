/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 20:44:11 by rhadiats          #+#    #+#             */
/*   Updated: 2017/11/22 20:44:14 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/vm.h"

void					print_map(unsigned char *map)
{
	unsigned char		*t_map;
	int					x;
	int					y;

	x = -1;
	t_map = map;
	while (++x < sqrt(MEM_SIZE) && (x * y < MEM_SIZE))
	{
		y = -1;
		while (++y < sqrt(MEM_SIZE) && (x * y < MEM_SIZE))
			if (*t_map)
				printf("%s%.2x%s ", CYAN, *t_map++, RESET);
			else
				printf("%.2x ", *t_map++);
		printf("\n");
	}
}

void					print_data(t_player *players)
{
	t_player			*t_player;
	unsigned char		*t_data;
	int					x;
	int					y;

	t_player = players;
	while (t_player)
	{
		x = (int)t_player->size % (FORMAT) == 0 ? -1 : -2;
		t_data = t_player->data;
		while (++x < (int)t_player->size / (FORMAT))
		{
			y = -1;
			while (++y < FORMAT)
			{
				if (*t_data)
					printf("%s%.2x%s ", RED, *t_data++, RESET);
				else
					printf("%.2x ", *t_data++);
			}
			printf("\n");
		}
		printf("\n");
		t_player = t_player->next;
	}
}

void					print_prog_attr(char *data, unsigned int len)
{
	int					x;
	int					y;

	if (data)
	{
		x = (int)len % (FORMAT) == 0 ? -1 : -2;
		while (++x < (int)(len / FORMAT))
		{
			y = -1;
			while (++y < (int)FORMAT)
			{
				if (*data)
					printf("%s%.2x%s ", GREEN, *data++, RESET);
				else
					printf("%.2x ", *data++);
			}
			printf("\n");
		}
	}
}

void					print_header(t_header *header, unsigned int size)
{
	if (header)
	{
		header->magic ? printf("MAGIC : %x\n\n", header->magic) : 0;
		header->prog_name ? print_prog_attr(header->prog_name, (PROG_NAME_LENGTH)) : 0;
		header->comment ? print_prog_attr(header->comment, (COMMENT_LENGTH)) : 0;
		header->prog ? print_prog_attr(header->prog, size - ((PROG_NAME_LENGTH) + (COMMENT_LENGTH) + 16)) : 0;
	}
}

void					print_headers(t_player *players)
{
	t_player			*t_player;

	t_player = players ? players : NULL;
	while (t_player)
	{
		printf("------------------PLAYER ID %d------------------\n", t_player->id);
		print_header(t_player->header, t_player->size);
		t_player = t_player->next;
		printf("-----------------------------------------------\n\n");
	}
}

void					print_players(t_player *players)
{
	t_player	*tmp;

	tmp = players;
	printf("--------------PLAYERS--------------\n");
	while (tmp)
	{
		printf("ID:\t\t%d\n", tmp->id);
		printf("LEN:\t\t%d\n", tmp->size);
		tmp = tmp->next;
		printf("-----------------------------------\n");
	}
}
