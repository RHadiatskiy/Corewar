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

static int				check_flag_d(t_core *core, char **av, int *i)
{
	if (ft_strcmp(av[(*i)], "-d") == 0 && av[(*i) + 1])
	{
		core->flags->dump = 1;
		core->flags->dump_cycle = ft_atoi(av[++(*i)]);
		++(*i);
		return (1);
	}
	return (0);
}

static int				check_flag_n(t_core *core, char **av, int *i)
{
	if (ft_strcmp(av[(*i)], "-n") == 0 && av[(*i) + 1])
	{
		core->flags->number = 1;
		core->flags->n = ft_atoi(av[++(*i)]);
		++(*i);
		return (1);
	}
	return (0);
}

static int				check_flags_clr(t_core *core, char **av, int *i)
{
	if (ft_strcmp(av[(*i)], "-clr") == 0)
	{
		core->flags->clr = 1;
		++(*i);
		return (1);
	}
	return (0);	
}

int						read_flags(t_core *core, char **av, int *i)
{
	int			ret;

	ret = 0;
	core->flags->number = 0;
	core->flags->n = 0;
	while (av[(*i)])
	{
		if (!check_flag_d(core, av, i) && !check_flag_n(core, av, i) && \
			!check_flags_clr(core, av, i))
		{
			ret = 1;
			break ;
		}
	}
	return (ret);
}
