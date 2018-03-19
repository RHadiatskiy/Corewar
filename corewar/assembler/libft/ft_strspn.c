/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemchuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 12:29:57 by bsemchuk          #+#    #+#             */
/*   Updated: 2017/05/31 17:16:51 by bsemchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	function skips all chars in control string if presented in
**	second argument, otherwise if char is not specified in
**	second argument, number of match is returned
*/

int		ft_strspn(const char *control, const char *s2)
{
	const char		*tmp;
	unsigned int	skip;

	skip = 0;
	if (!s2 || !control)
		return (0);
	tmp = control;
	while (*control)
	{
		if (*control == *s2)
		{
			skip++;
			s2++;
			control = tmp;
		}
		else if (!*control)
			return (skip);
		else
			control++;
	}
	return (skip);
}
