/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_verbosity.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 21:13:30 by rhadiats          #+#    #+#             */
/*   Updated: 2018/01/06 21:13:32 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/vm.h"

void					read_verbosity(t_core *core)
{
	if (core->flags->verbosity / 16 && !core->flags->verbosity_sixteen)
	{
		core->flags->verbosity_sixteen = 1;
		core->flags->verbosity %= 16;
			}
	if (core->flags->verbosity / 8 && !core->flags->verbosity_eight)
	{
		core->flags->verbosity_eight = 1;
		core->flags->verbosity %= 8;
	}
	if (core->flags->verbosity / 4 && !core->flags->verbosity_four)
	{
		core->flags->verbosity_four = 1;
		core->flags->verbosity %= 4;
	}
	if (core->flags->verbosity / 2 && !core->flags->verbosity_two)
	{
		core->flags->verbosity_two = 1;
		core->flags->verbosity %= 2;
	}
	if (core->flags->verbosity / 1 && !core->flags->verbosity_one)
	{
		core->flags->verbosity_one = 1;
		core->flags->verbosity %= 1;
	}
}
