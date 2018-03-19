/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label_exists.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemchuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 18:43:14 by bsemchuk          #+#    #+#             */
/*   Updated: 2018/03/11 18:44:02 by bsemchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int			label_exists(char *label, t_champion *champion)
{
	t_llist	*dummy;

	if (label[0] == ':')
		++label;
	dummy = champion->labels;
	while (dummy)
	{
		if (ft_strequ(label, ((t_label *)dummy->data)->name))
			return (EXIT_SUCCESS);
		dummy = dummy->next;
	}
	return (EXIT_FAILURE);
}
