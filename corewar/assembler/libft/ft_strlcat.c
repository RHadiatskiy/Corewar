/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemchuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 17:02:46 by bsemchuk          #+#    #+#             */
/*   Updated: 2017/01/03 16:55:12 by bsemchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdio.h>

size_t	ft_strlcat(char *dest, const char *str, size_t n)
{
	size_t	i;
	size_t	d;
	size_t	s;

	i = 0;
	d = ft_strlen(dest);
	s = ft_strlen(str);
	if (n >= d)
	{
		while (str[i] && d < n - 1)
			dest[d++] = str[i++];
		dest[d] = '\0';
		return ((unsigned long)(s - i) + (unsigned long)d);
	}
	return ((unsigned long)s + (unsigned long)n);
}
