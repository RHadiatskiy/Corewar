/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_whitespace.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemchuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 17:50:56 by bsemchuk          #+#    #+#             */
/*   Updated: 2018/03/11 17:50:57 by bsemchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

static size_t	ft_strslen(const char *s1, const char *s2)
{
	size_t	i;
	size_t	ii;

	i = 0;
	ii = 0;
	if (*s1 && *s2)
	{
		while (s1[i])
			i++;
		while (s2[ii])
			ii++;
		return (i + ii + 1);
	}
	return (0);
}

char			*ft_strjoin_whitespace(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*ret;

	i = 0;
	j = 0;
	if (s1 && s2)
	{
		ret = (char *)malloc(sizeof(char) * ft_strslen(s1, s2) + 1);
		if (ret)
		{
			while (s1[i])
			{
				ret[i] = s1[i];
				i++;
			}
			ret[i++] = ' ';
			while (s2[j])
				ret[i++] = s2[j++];
			ret[i] = '\0';
			return (ret);
		}
	}
	return (NULL);
}
