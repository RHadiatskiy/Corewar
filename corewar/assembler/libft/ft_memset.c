/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemchuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 20:00:23 by bsemchuk          #+#    #+#             */
/*   Updated: 2017/01/03 16:46:00 by bsemchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	ch;
	char			*bb;

	ch = (unsigned char)c;
	bb = (char *)b;
	while (len)
	{
		*bb = ch;
		bb++;
		len--;
	}
	return (b);
}
