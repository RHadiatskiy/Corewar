/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrtombstr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemchuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 16:31:37 by bsemchuk          #+#    #+#             */
/*   Updated: 2017/05/26 17:45:44 by bsemchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_wstrtombstr(char *dst, wchar_t *wchar)
{
	unsigned	i;

	i = 0;
	while (*wchar)
		i = i + (ft_wctomb(&dst[i], *wchar++));
	return (i);
}
