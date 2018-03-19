/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_straddprefix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemchuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 19:12:15 by bsemchuk          #+#    #+#             */
/*   Updated: 2017/05/31 17:12:46 by bsemchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_straddprefix(char *what, char *to)
{
	char	*d;

	if (!what || !to)
		return (NULL);
	d = (char *)malloc(sizeof(char) * ((ft_strlen(what)) + ft_strlen(to)) + 1);
	ft_strcpy(d, what);
	ft_strcpy(&d[(ft_strlen(what))], to);
	free(to);
	return (d);
}
