/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnmcpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemchuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 18:55:00 by bsemchuk          #+#    #+#             */
/*   Updated: 2017/05/17 15:57:36 by bsemchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnmcpy(const char *src, size_t len)
{
	char	*aim;
	char	*tmp;

	if (!src)
		return (0);
	aim = (char *)malloc(sizeof(char) * (int)len + 1);
	if (!aim)
		return (NULL);
	tmp = aim;
	while (len-- && *src)
		*aim++ = *src++;
	*aim = '\0';
	return (tmp);
}
