/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemchuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 15:03:24 by bsemchuk          #+#    #+#             */
/*   Updated: 2017/01/04 19:41:32 by bsemchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*found;
	char	cc;

	cc = (char)c;
	found = (char *)str;
	while (*str != '\0')
		str++;
	while (str >= found)
	{
		if (*str == cc)
		{
			found = (char *)str;
			return (found);
		}
		else
			str--;
	}
	return (NULL);
}
