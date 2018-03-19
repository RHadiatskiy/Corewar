/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_straposchr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemchuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 19:13:16 by bsemchuk          #+#    #+#             */
/*   Updated: 2017/04/03 19:53:15 by bsemchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_straposchr(const char *format, const char *where)
{
	unsigned int	i;

	while (*where)
	{
		while (format[i])
		{
			if (format[i] == *where)
				return (i);
			i++;
		}
		i = 0;
		where++;
	}
	return (0);
}
