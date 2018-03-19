/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcsncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemchuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 17:13:49 by bsemchuk          #+#    #+#             */
/*   Updated: 2017/05/31 17:13:50 by bsemchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_wcsncpy(wchar_t *src, wchar_t *dst, size_t len)
{
	size_t i;

	i = 0;
	if (!src || !dst)
		return (0);
	while (i < len)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = L'\0';
	return (i);
}
