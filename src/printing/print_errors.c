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
	printf("Error: %s has an invalid header\n", dir);
	return (0);
}

int						print_prog_size_error(char *dir, int len)
{
	len < 0 ? printf("Error: File champs is too small to be a champion\n") : \
	printf("Error: File %s has too large a code (%d bytes > 682 bytes)\n", \
		dir, len);
	return (0);
}

int						print_usage(void)
{
	printf("Usage: ./corewar [-d n_cycles] ");
	printf("[[-n number] <champion1.cor>] <...>\n");
	printf("\t-d n_cycles\t: dumping the memory on the standard ");
	printf("output at the end of nbr_cycles\n");
	printf("\t-n number\t: sets the number of the next player\n");
	return (0);
}
