/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemchuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/24 17:58:53 by bsemchuk          #+#    #+#             */
/*   Updated: 2017/01/03 16:41:48 by bsemchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_lstnew(void const *content, size_t size)
{
	t_list	*ret;

	ret = (void *)malloc(sizeof(t_list));
	if (content)
	{
		if (ret)
		{
			ret->content = (t_list *)malloc(size);
			ret->content = ft_memcpy(ret->content, content, size);
			ret->content_size = size;
			ret->next = NULL;
			return (ret);
		}
		return (NULL);
	}
	ret->content = NULL;
	ret->content_size = 0;
	return (ret);
}
