/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemchuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 17:28:29 by bsemchuk          #+#    #+#             */
/*   Updated: 2017/01/03 16:56:59 by bsemchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*found;
	size_t	i;

	i = 0;
	if (s)
	{
		found = (char *)malloc((sizeof(char) * ft_strmlen((char *)s)));
		if (found)
		{
			while (s[i])
			{
				found[i] = f(i, s[i]);
				i++;
			}
			found[i] = '\0';
			return (found);
		}
	}
	return (0);
}
