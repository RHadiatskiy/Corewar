/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_comments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemchuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 15:41:47 by bsemchuk          #+#    #+#             */
/*   Updated: 2018/01/10 15:41:48 by bsemchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	delete_comments(unsigned char *line)
{
	char	*comment;

	if ((comment = ft_strchr((char *)line, COMMENT_CHAR)))
		*comment = '\0';
}
