/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_szero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 21:06:01 by rhadiats          #+#    #+#             */
/*   Updated: 2017/11/20 21:06:02 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_szero(void *s, size_t n)
{
	size_t				i;
	unsigned char		*c;

	i = 0;
	c = (unsigned char *)s;
	while (i < n && c)
		c[i++] = '0';
}
