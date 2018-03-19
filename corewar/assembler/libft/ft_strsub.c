/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemchuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 00:40:50 by bsemchuk          #+#    #+#             */
/*   Updated: 2017/01/03 17:08:13 by bsemchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*ret;
	unsigned long	i;

	if (s)
	{
		i = 0;
		ret = (char *)malloc(sizeof(char) * len + 1);
		if (ret)
		{
			while (i < len)
			{
				ret[i] = s[start + i];
				i++;
			}
			ret[i] = '\0';
			return (ret);
		}
	}
	return (NULL);
}
