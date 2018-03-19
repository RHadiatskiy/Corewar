/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemchuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 17:49:43 by bsemchuk          #+#    #+#             */
/*   Updated: 2017/05/31 17:17:16 by bsemchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strpspn(const char *control, const char *s2)
{
	const char	*tmp;
	const char	*aim;

	aim = NULL;
	if (!s2 || !control || !*s2 || !*control)
		return (NULL);
	tmp = control;
	while (*s2)
	{
		if (*control == *s2)
		{
			aim = s2;
			return ((char *)aim);
		}
		else if (!*control)
		{
			control = tmp;
			s2++;
		}
		else
			control++;
	}
	return ((char *)aim);
}
