/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemchuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 05:38:40 by bsemchuk          #+#    #+#             */
/*   Updated: 2017/02/08 05:58:29 by bsemchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	total_size;
	size_t	i;
	void	*ret;
	char	*make;

	i = 0;
	total_size = size * count;
	ret = (void *)malloc(size * count);
	make = ret;
	while (i < total_size)
		make[i++] = '\0';
	return (ret);
}
