/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_parg_and_pparg.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemchuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 18:19:08 by bsemchuk          #+#    #+#             */
/*   Updated: 2018/03/11 18:19:17 by bsemchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int			get_parg_and_pparg(t_line *tline)
{
	char			*first_whitespace;

	if (tline->command_index == -1)
		return (EXIT_SUCCESS);
	if (!tline->label)
		first_whitespace = ft_strjumpword((char *)tline->line_content_trim, 1);
	else
		first_whitespace = ft_strjumpword((char *)tline->line_content_trim, 2);
	tline->parg = first_whitespace;
	tline->args = (unsigned char **)ft_strsplit(tline->parg, SEPARATOR_CHAR);
	tline->nargs = (unsigned int)count_args((char **)tline->args);
	trim_args(tline);
	return (EXIT_SUCCESS);
}
