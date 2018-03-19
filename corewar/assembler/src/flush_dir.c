/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flush_dir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemchuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 17:01:11 by bsemchuk          #+#    #+#             */
/*   Updated: 2018/03/12 22:49:11 by bsemchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static int	dir_value_to_file(char *arg,
		t_champion *champion, t_lab u, char size)
{
	if (size)
	{
		if (size != 4 && size != 2)
			ft_printf("Size of %s wasn't calculated\n", arg);
		else if (size == 4)
			ft_write_value_big_e4(champion->fdout, u.res);
		else if (size == 2)
			ft_write_value_big_e2(champion->fdout, u.sres);
		return (EXIT_SUCCESS);
	}
	perror("Size of dir argument is wrong!\n");
	return (EXIT_FAILURE);
}

int			flush_dir(char *arg, t_champion *champion, char i, unsigned id)
{
	t_lab	u;
	char	size;

	u.res = 0;
	u.sres = 0;
	size = g_op_tab[(int)i].labelsize;
	arg = arg + 1;
	if (ft_isdigit(arg[0]) || arg[0] == '-')
	{
		u.sres = (unsigned short)ft_atoi(arg);
		u.res = ft_atoi(arg);
	}
	else if (arg[0] == LABEL_CHAR)
	{
		return (flush_dir_char(arg, champion, id));
	}
	else
	{
		return (EXIT_FAILURE);
	}
	return (dir_value_to_file(arg, champion, u, size));
}
