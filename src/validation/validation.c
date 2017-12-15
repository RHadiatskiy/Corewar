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

int						magic_error(char *dir)
{
	printf("Error: %s has an invalid header\n", dir);
	return (0);
}

int						prog_size_error(char *dir, int len)
{
	len < 0 ? printf("Error: File champs is too small to be a champion\n") : \
	printf("Error: File %s has too large a code (%d bytes > 682 bytes)\n", \
		dir, len);
	return (0);
}

int						validation(t_core *core, char *av)
{
	int			ret;

	ret = 1;
	if ((ret = read_file(core, av)) != 1)
	{
		ret == -1 ? printf("Can't read source file %s\n", av) : 0;
		ret == -2 ? printf("can't allocate a memory for %s\n", av) : 0;
		ret == -3 ? printf("can't read the file %s\n", av) : 0;
		return (0);
	}
	return (ret);
}
