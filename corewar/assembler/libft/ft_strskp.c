/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strskp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemchuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 20:18:34 by bsemchuk          #+#    #+#             */
/*   Updated: 2017/04/01 19:39:37 by bsemchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strskp(char c, char *src)
{
	if (!src)
		return (NULL);
	while (*src)
	{
		if (*src == c)
			return (src);
		else
			src++;
	}
	return (NULL);
}
