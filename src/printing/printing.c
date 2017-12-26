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

void					print_map(t_core *core)
{
	unsigned char		*t_map;
	int					x;
	int					y;
	int					count;

	x = -1;
	count = 0;
	t_map = core->map;
	print_players(core->players);
	while (++x < sqrt(MEM_SIZE) && (x * y < MEM_SIZE))
	{
		y = -1;
		printf("Ox%.4x : ", count);
		while (++y < sqrt(MEM_SIZE) && (x * y < MEM_SIZE))
		{
			if (*t_map && core->flags->clr)
				printf("%s%.2x%s ", CYAN, *t_map++, RESET);
			else
				printf("%.2x ", *t_map++);
			count++;
		}
		printf("\n");
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
	t_player	*tmp_player;

	tmp_player = players ? players : NULL;
	if (tmp_player)
	{
		printf("Introducing contestants...\n");
		while (tmp_player)
		{
			printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n", \
				tmp_player->number, tmp_player->header->prog_size, \
				tmp_player->header->prog_name, tmp_player->header->comment);
			tmp_player = tmp_player->next;
		}
	}
}

int						print_usage(void)
{
	printf("Usage: ./corewar [-d n_cycles] [[-n number] <champion1.cor>] <...>\n");
	printf("\t-d n_cycles\t: dumping the memory on the standard output at the end of nbr_cycles\n");
	printf("\t-n number\t: sets the number of the next player\n");
	return (0);
}

void					print_debug(t_core *core)
{
	int				i;
	int				cmd;
	
	i = 0;
	cmd = 0;
	while (i + 1 < MEM_SIZE)
	{
		cmd = get_value_from_map(core->map, i, 1);
		if (cmd != 0 && g_op_tab[cmd - 1].codage_octal)
		{
			printf("command : %s\t\tpc : %x\tindex : %d\tnext index = %d\n", g_op_tab[cmd - 1].command, core->map[i], i,
				get_next_index(get_value_from_map(core->map, i, 1) - 1, get_value_from_map(core->map, i + 1, 1)));
			i += (2 + get_next_index(cmd - 1, get_value_from_map(core->map, i + 1, 1)));
		}
		else if (cmd != 0 && !g_op_tab[cmd - 1].codage_octal)
		{
			printf("command : %s\t\tpc : %x\tindex : %d\tnext index = %d\n", g_op_tab[cmd - 1].command, core->map[i], i,
				get_next_index(get_value_from_map(core->map, i, 1) - 1, get_value_from_map(core->map, i + 1, 1)));
			i += (1 + g_sizes[cmd - 1][2]);
		}
		else
		{
			printf("command hasn't found\tpc : %x\tindex : %d\n", core->map[i], i);
			i++;
		}
	}
}
