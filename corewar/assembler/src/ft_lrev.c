/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lrev.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemchuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 18:47:34 by bsemchuk          #+#    #+#             */
/*   Updated: 2018/03/11 18:48:57 by bsemchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lists.h"
#include "../includes/asm.h"

/*
**	ft_lrev	-- реверс списка
*/

void			ft_lrev(t_llist **head_ref)
{
	t_llist *curr;
	t_llist *next;
	t_llist *prev;

	curr = *head_ref;
	prev = NULL;
	while (curr)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
}
