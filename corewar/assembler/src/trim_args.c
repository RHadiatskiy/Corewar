/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemchuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 18:52:54 by bsemchuk          #+#    #+#             */
/*   Updated: 2018/03/11 18:53:11 by bsemchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void				trim_args(const t_line *tline)
{
	int				i;
	unsigned char	*dummy;

	i = 0;
	while (tline->args[i])
	{
		dummy = tline->args[i];
		tline->args[i] = (unsigned char *)
			ft_strtrim((const char *)tline->args[i]);
		free(dummy);
		i++;
	}
}
