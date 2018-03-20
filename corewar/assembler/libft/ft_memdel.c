/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemchuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 21:04:34 by bsemchuk          #+#    #+#             */
/*   Updated: 2017/05/31 17:13:32 by bsemchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_memdel(void **ap)
{
	int i;

	i = 0;
	if (ap)
	{
		while (ap[i])
			i++;
		while (ap[i])
			free(ap[i--]);
		free(*ap);
		*ap = NULL;
	}
}