/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deintegrate_split_trim.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemchuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 15:44:09 by bsemchuk          #+#    #+#             */
/*   Updated: 2018/03/12 15:44:32 by bsemchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	deintegrate_split_trim(t_line *tline)
{
	tline->line_content_trim = (unsigned char *)\
		ft_strtrim((const char *)tline->line_content);
	tline->line_content_nocommas = (unsigned char *)\
		ft_strmap((const char *)tline->line_content_trim,\
				(char (*)(char))ft_replace_commas);
	tline->deintegrated_line = (unsigned char **)\
		ft_split_whitespace((const char *)tline->line_content_nocommas);
}
