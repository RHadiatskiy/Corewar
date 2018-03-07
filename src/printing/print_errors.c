/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 21:08:54 by rhadiats          #+#    #+#             */
/*   Updated: 2017/12/28 21:08:57 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/vm.h"

int						print_magic_error(char *dir)
{
	ft_printf("Error: %s has an invalid header\n", dir);
	return (0);
}

int						print_prog_size_error(char *dir, int len)
{
	len < 0 ? ft_printf("Error: File champs is too small to be a champion\n") : \
	ft_printf("Error: File %s has too large a code (%d bytes > 682 bytes)\n", \
		dir, len);
	return (0);
}

int						print_usage(void)
{
	ft_printf("Usage: ./corewar [ -d N -v N ] ");
	ft_printf("[-n number] <champion1.cor> <...>\n");
	ft_printf("    -n number\t: Sets the number of the next player\n");
	ft_printf("    --color\t: Sets the color to output\n");
	ft_printf("    -a\t\t: Prints output from \"aff\" (Default is to hide it)\n");
	ft_printf("#### TEXT OUTPUT MODE ");
	ft_printf("##########################################################\n");
	ft_printf("    -d N\t: Dumps memory after N cycles then exits\n");
	ft_printf("    -v N\t: Verbosity levels, can be added together ");
	ft_printf("to enable several\n");
	ft_printf("\t\t  - 0 : Show only essentials\n");
	ft_printf("\t\t  - 1 : Show lives\n");
	ft_printf("\t\t  - 2 : Show cycles\n");
	ft_printf("\t\t  - 4 : Show operations (Params are NOT litteral ...)\n");
	ft_printf("\t\t  - 8 : Show deaths\n");
	ft_printf("\t\t  - 16 : Show PC movements (Except for jumps)\n");
	ft_printf("#### NCURSES OUTPUT MODE ");
	ft_printf("#######################################################\n");
	ft_printf("    --visual\t: Ncurses output mode\n");
	return (0);
}
