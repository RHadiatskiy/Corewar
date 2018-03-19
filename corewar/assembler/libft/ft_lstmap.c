/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemchuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 21:16:36 by bsemchuk          #+#    #+#             */
/*   Updated: 2017/01/04 20:09:59 by bsemchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f) (t_list *elem))
{
	t_list	*ret;
	t_list	*fin;

	if (lst && f)
	{
		ret = (t_list *)malloc(sizeof(t_list));
		ret = f(lst);
		fin = ret;
		while (lst->next)
		{
			if (!ret)
				return (NULL);
			ret->next = (t_list *)malloc(sizeof(t_list));
			ret->next = f(lst->next);
			ret = ret->next;
			lst = lst->next;
		}
		return (fin);
	}
	return (NULL);
}
