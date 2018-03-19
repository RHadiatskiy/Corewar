/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemchuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 15:16:37 by bsemchuk          #+#    #+#             */
/*   Updated: 2018/03/19 19:15:29 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int			g_is_debug = 0;

static int	are_flags_included(char **argv, int *i)
{
	if (ft_strequ(argv[(*i)], DEBUG_ARG) || ft_strequ(argv[(*i)], DEBUG_ARG1))
	{
		g_is_debug = 1;
		(*i)++;
		return (2);
	}
	if (ft_strequ(argv[(*i)], VERSION_ARG) ||
			ft_strequ(argv[(*i)], VERSION_ARG1))
	{
		ft_putstr("Assembler by bsemchuk and daleksan. Version 2.02 final\n");
		(*i)++;
		return (2);
	}
	if (ft_strequ(argv[(*i)], HELP_ARG) || ft_strequ(argv[(*i)], HELP_ARG1))
	{
		ft_putstr("Use -d or -debug to see debug information\n");
		ft_putstr("Use -v or -version to see assembler version\n");
		ft_putstr("Use -h or -help to see usage\n");
		ft_putstr("Usage: ./asm [and there .cor file] or whatever define is\n");
		(*i)++;
		return (2);
	}
	return (0);
}

int			main(int argc, char **argv)
{
	t_champion	*header;
	int			i;

	i = 1;
	if (argc == 1)
		ft_putstr("Try ./asm -h for help\n");
	while (i < argc)
	{
		header = ft_calloc(1, sizeof(t_champion));
		header->fdin = -1;
		if ((are_flags_included(argv, &i)) == 2)
			continue ;
		header->fdin = open(argv[i], O_RDONLY);
		if (ft_fd_valid(header->fdin) == EXIT_SUCCESS)
		{
			if (read_lines(argv[i], header) == EXIT_FAILURE)
				return (finish_header(header));
		}
		close(header->fdin);
		finish_header(header);
		i++;
	}
	return (EXIT_SUCCESS);
}
