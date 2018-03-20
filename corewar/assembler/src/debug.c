/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemchuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 15:41:42 by bsemchuk          #+#    #+#             */
/*   Updated: 2018/03/20 18:56:51 by bsemchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static void	print_deintegrated(unsigned char **deintegrated_line)
{
	int		i;

	i = 0;
	while (deintegrated_line[i])
	{
		ft_printf("{%s}", deintegrated_line[i]);
		i++;
	}
}

static void	print_argtype(t_arg_type argtype[4])
{
	int		i;

	i = 0;
	while (i < 4)
		ft_printf("[%i] ", argtype[i++]);
	ft_printf("\n");
}

void		print_debug(t_line *line)
{
	if (g_is_debug)
	{
		ft_printf("vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv\n");
		ft_printf("%-20s: [%s]\n", "Line content:", line->line_content);
		ft_printf("%-20s: [%s]\n", "Trimmed:", line->line_content_trim);
		ft_printf("%-20s: [%s]\n", "Nocommas:", line->line_content_nocommas);
		ft_printf("%-20s: [%s]\n", "Parg:", line->parg);
		ft_printf("%-20s: [%d]\n", "Command index", line->command_index);
		ft_printf("%-20s: [", "Deintegrated");
		print_deintegrated(line->deintegrated_line);
		ft_printf("]\n");
		ft_printf("%-20s: [", "Args");
		if (line->args)
			print_deintegrated(line->args);
		ft_printf("]\n");
		ft_printf("%-20s: [%s]\n", "Label:", line->label);
		if (line->cmd)
			ft_printf("%-20s: [%s]\n", "cmd", line->cmd[0]);
		ft_printf("%-20s: [%d]\n", "Bytes needed", line->bytes_needed);
		ft_printf("%-20s: [%d]\n", "line id", line->id);
		ft_printf("%-20s: [%d]\n", "codage", line->command_codage);
		print_argtype(line->argtype);
		ft_printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
	}
}
