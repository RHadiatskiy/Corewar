/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemchuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 16:56:53 by bsemchuk          #+#    #+#             */
/*   Updated: 2017/01/03 16:55:58 by bsemchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char *found;
	char *ret;

	if (s)
	{
		found = (char *)malloc(sizeof(char) * (ft_strmlen((char *)s)));
		ret = found;
		if (found)
		{
			while (*s)
			{
				*found++ = f(*s++);
			}
			*found = '\0';
			return (ret);
		}
	}
	return (0);
}
