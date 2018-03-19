/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemchuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 14:41:49 by bsemchuk          #+#    #+#             */
/*   Updated: 2017/04/03 19:59:06 by bsemchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	char	cc;

	cc = (char)c;
	if (!str)
		return (NULL);
	if (*str == (cc))
		return ((char *)str);
	while (*str++)
	{
		if (*str == (cc))
			return ((char *)str);
	}
	return (NULL);
}
