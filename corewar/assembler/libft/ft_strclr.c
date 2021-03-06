/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemchuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 21:57:34 by bsemchuk          #+#    #+#             */
/*   Updated: 2017/05/05 18:18:02 by bsemchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strclr(char *s)
{
	int		i;
	char	*ss;

	if (s)
	{
		ss = s;
		i = 0;
		while (ss[i++])
			;
		while (i-- != 0)
			ss[i] = '\0';
	}
}
