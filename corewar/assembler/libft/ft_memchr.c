/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemchuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 14:59:39 by bsemchuk          #+#    #+#             */
/*   Updated: 2017/01/03 16:43:16 by bsemchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	ch;

	ch = (unsigned char)c;
	str = (unsigned char *)s;
	while (n--)
	{
		if (*str == ch)
		{
			return ((void *)str);
		}
		if (*str != ch)
		{
			str++;
		}
	}
	return (NULL);
}
