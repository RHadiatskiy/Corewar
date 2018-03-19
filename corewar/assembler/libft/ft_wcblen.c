/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcblen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemchuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 19:30:55 by bsemchuk          #+#    #+#             */
/*   Updated: 2017/05/31 17:10:43 by bsemchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_size(wint_t character)
{
	if (character <= 127)
		return (1);
	if (character <= 2047)
		return (2);
	if (character < 0xFFFF)
		return (3);
	return (4);
}

size_t			ft_wcblen(wchar_t *src)
{
	size_t	i;
	int		len;

	len = 0;
	i = 0;
	if (!src)
		return (i);
	while (src[i])
		len += ft_size(src[i++]);
	return (len);
}
