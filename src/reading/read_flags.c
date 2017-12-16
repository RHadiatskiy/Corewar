/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 20:09:24 by rhadiats          #+#    #+#             */
/*   Updated: 2017/12/16 20:09:25 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/vm.h"

int						read_flags(t_core *core, char **av, int *i)
{
	int			ret;

	ret = 0;
	while (av[(*i)])
	{
		if (ft_strcmp(av[(*i)], "-d") == 0 && av[(*i) + 1])
		{
			core->flags->dump = 1;
			core->flags->dump_cycle = ft_atoi(av[++(*i)]);
			++(*i);
		}
		else if (ft_strcmp(av[(*i)], "-n") == 0 && av[(*i) + 1])
		{
			core->flags->number = 1;
			core->flags->n = ft_atoi(av[++(*i)]);
			++(*i);
		}
		else
		{
			ret = 1;
			break ;
		}
	}
	return (ret);
}
