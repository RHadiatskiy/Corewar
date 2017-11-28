/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 22:40:08 by rhadiats          #+#    #+#             */
/*   Updated: 2017/11/20 22:40:10 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/vm.h"

// static int				valid_magic(char *data)
// {
// 	(void)data;
// 	return (1);
// }

// static int				valid_prog_name(int data)
// {
// 	(void)data;
// 	return (1);
// }

// static int				valid_prog_size(int data)
// {
// 	(void)data;
// 	return (1);
// }

// static int				valid_comment(int data)
// {
// 	(void)data;
// 	return (1);
// }

int						validation(t_core *core, char *av)
{
	int			ret;

	ret = 1;
	if ((ret = read_file(core, av)) != 1)
	{
		ret == -1 ? write (1, "can't open the file\n", 20) : 0;
		ret == -2 ? write (1, "can't allocate a memory\n", 24) : 0;
		ret == -3 ? write (1, "can't reed the file\n", 20) : 0;
		ret == -4 ? write (1, "invalid magic\n", 14) : 0;
		return (0);
	}
	return (ret);
}
