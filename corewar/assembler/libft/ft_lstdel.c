/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemchuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/24 20:16:11 by bsemchuk          #+#    #+#             */
/*   Updated: 2017/01/03 16:40:21 by bsemchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del) (void *, size_t))
{
	t_list	*t;

	if (*alst)
	{
		while (*alst)
		{
			t = (*alst);
			del((*alst)->content, (*alst)->content_size);
			*alst = (*alst)->next;
			free(t);
			t = NULL;
		}
	}
}
