/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strachr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemchuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 19:43:38 by bsemchuk          #+#    #+#             */
/*   Updated: 2017/05/17 22:15:09 by bsemchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strachr(const char *format, const char *where)
{
	const char		*temp;
	const char		*res;

	res = where;
	temp = format;
	while (*where)
	{
		while (*format)
		{
			if (*format == *where)
				return ((where - res) + 1);
			format++;
		}
		format = temp;
		where++;
	}
	return (-1);
}
