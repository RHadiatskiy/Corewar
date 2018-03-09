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

static void				reading_source_error(char *av)
{
	ft_putstr_fd("Can't read source file ", 2);
	ft_putstr_fd(av, 2);
	ft_putstr_fd("\n", 2);
}

static void				allocation_error(char *av)
{
	ft_putstr_fd("can't allocate a memory for ", 2);
	ft_putstr_fd(av, 2);
	ft_putstr_fd("\n", 2);
}

static void				reading_file_error(char *av)
{
	ft_putstr_fd("can't read the file ", 2);
	ft_putstr_fd(av, 2);
	ft_putstr_fd("\n", 2);
}

int						validation(t_core *core, char *av)
{
	int			ret;

	ret = 1;
	if ((ret = read_file(core, av)) != 1)
	{
		ret == -1 ? reading_source_error(av) : 0;
		ret == -2 ? allocation_error(av) : 0;
		ret == -3 ? reading_file_error(av) : 0;
		return (0);
	}
	return (ret);
}
