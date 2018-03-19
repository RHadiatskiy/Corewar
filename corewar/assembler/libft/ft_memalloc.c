/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemchuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 19:37:16 by bsemchuk          #+#    #+#             */
/*   Updated: 2017/01/03 16:42:36 by bsemchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*ret;

	ret = (char *)malloc(size);
	if (ret == NULL)
		return (NULL);
	ft_bzero(ret, size);
	return ((void *)ret);
}
