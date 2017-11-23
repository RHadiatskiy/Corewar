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
	if (!read_file(core, av))
		return (0);
	// print_data(core->data, core->data_len);

	return (1);
}
