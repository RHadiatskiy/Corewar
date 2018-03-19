/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemchuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 11:35:15 by bsemchuk          #+#    #+#             */
/*   Updated: 2017/01/03 19:41:18 by bsemchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int			h;
	int			n;

	h = 0;
	n = 0;
	if (needle[n] == '\0')
	{
		return ((char *)haystack);
	}
	while (haystack[h] != '\0')
	{
		n = 0;
		while (needle[n] == haystack[h + n])
		{
			n++;
			if (needle[n] == '\0')
			{
				return ((char *)&haystack[h]);
			}
		}
		h++;
	}
	return (NULL);
}
