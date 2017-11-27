/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 22:31:16 by rhadiats          #+#    #+#             */
/*   Updated: 2017/11/20 22:31:30 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/vm.h"

static unsigned int				parse_magic(void *data, unsigned int len, unsigned int size)
{
	unsigned int		magic;

	magic = 0;
	if (len < size)
		magic = get_value_from_file(data, 0, len);
	if (magic != COREWAR_EXEC_MAGIC)
	{
		write(1, "invalid magic\n", 14);
		return (0);
	}
	return (magic);
}

static unsigned char			*parse_name(void *data, unsigned int len, unsigned int size)
{
	unsigned int		start;
	unsigned int		i;
	unsigned char		*name;
	unsigned char		*t_data;

	start = sizeof(unsigned int);
	i = 0;
	name = NULL;
	t_data = (unsigned char *)data;
	if (len < size)
	{
		while (start < len && start < size)
			name[i++] = t_data[start++];
	}
	return (name);
}

// static unsigned char			*parse_comment(unsigned char *data, unsigned int len, unsigned int size)
// {
// 	unsigned char		*comment;
// 	unsigned int		i;
// 	unsigned int		start;

// 	start = sizeof(unsigned int) + (PROG_NAME_LENGTH) + 1;
// 	i = 0;
// 	comment = NULL;
// 	if (len < size)
// 	{
// 		while (start < len && start < size)
// 			comment[i++] = data[start++];
// 	}
// 	return (comment);
// }

// static unsigned char			*parse_prog(unsigned char *data, unsigned int len, unsigned int size)
// {
// 	unsigned char		*prog;
// 	unsigned int		i;
// 	unsigned int		start;

// 	start = sizeof(unsigned int) + (PROG_NAME_LENGTH) + (COMMENT_LENGTH) + 2;
// 	i = 0;
// 	prog = NULL;
// 	if (len < size)
// 	{
// 		while (start < len && start < size)
// 			prog[i++] = data[start++];
// 	}
// 	return (prog);
// }

// void					parsing(t_core *core)
// {
// 	t_player		*tmplay;
// 	unsigned char	*t_map;
// 	unsigned char	*t_data;
// 	int				i;
// 	int				j;

// 	tmplay = core->players;
// 	t_map = core->map;
// 	while (tmplay)
// 	{
// 		i = -1;
// 		j = ((MEM_SIZE) / get_players_size(core->players)) * (tmplay->id - 1);
// 		t_data = tmplay->data;
// 		while (++i < (int)tmplay->data_len)
// 		{
// 			if (i >= (PROG_NAME_LENGTH) + (COMMENT_LENGTH) + 16)
// 				// res = (res << 8) | (((char *)buf)[j++] & 0x000000ff)
// 				t_map[j++] = tmplay->data[i];
// 		}
// 		tmplay = tmplay->next;
// 	}
// }

void						*parse_header(header_t *header, void *data, unsigned int size)
{
	t_header		*header;
	unsigned int	magic;
	unsigned char	*name;
	// unsigned char	*comment;
	// unsigned char	*prog;

	header = NULL;
	magic = parse_magic(data, 4, size);
	name = parse_name(data, (PROG_NAME_LENGTH) + 1, size);
	// comment = parse_comment(data, (COMMENT_LENGTH) + 1, size);
	// prog = parse_prog(data, size - ((PROG_NAME_LENGTH) + (COMMENT_LENGTH) + 16), size);
	// header = init_header(magic, name, comment, prog);
	return (header);
}