/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchcpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemchuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 08:47:16 by bsemchuk          #+#    #+#             */
/*   Updated: 2017/02/15 09:03:33 by bsemchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchcpy(char *dest, char *src, char ch)
{
	char	*found;

	if (!dest || !src)
		return (NULL);
	found = dest;
	while (*src && *src != ch)
		*dest++ = *src++;
	return (found);
}
