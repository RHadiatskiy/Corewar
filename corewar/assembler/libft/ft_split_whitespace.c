/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemchuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 03:06:01 by bsemchuk          #+#    #+#             */
/*   Updated: 2017/01/04 21:09:38 by bsemchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		ft_countwords(char const *s)
{
	size_t			i;
	size_t			w;

	i = 0;
	w = 0;
	while (s[i])
	{
		if (ft_is_whitespace(s[i]) == EXIT_FAILURE)
			i++;
		else if (ft_is_whitespace(s[i]) == EXIT_SUCCESS &&
				(ft_is_whitespace(s[i + 1]) == EXIT_FAILURE ||
						s[i + 1] == '\0'))
		{
			w++;
			i++;
		}
		else
			i++;
	}
	return (w);
}

static char			**ft_copyarray(char **d, char const *s)
{
	size_t			count;
	size_t			i;
	size_t			j;

	count = 0;
	i = 0;
	while (s[count])
	{
		j = 0;
		while (ft_is_whitespace(s[count]) == EXIT_FAILURE && s[count])
			count++;
		if (ft_is_whitespace(s[count]) == EXIT_SUCCESS && s[count])
		{
			while (ft_is_whitespace(s[count]) == EXIT_SUCCESS && s[count])
				d[i][j++] = s[count++];
			d[i][j] = '\0';
			i++;
		}
	}
	return (d);
}

static char			**ft_countallocate(char **tab, char const *s)
{
	size_t			count;
	size_t			i;
	size_t			chars;

	i = 0;
	count = 0;
	while (s[count])
	{
		chars = 0;
		while (ft_is_whitespace(s[count]) == EXIT_FAILURE && s[count])
			count++;
		while (ft_is_whitespace(s[count]) == EXIT_SUCCESS && s[count])
		{
			chars++;
			count++;
		}
		if (chars)
		{
			tab[i] = (char *)malloc(sizeof(char) * chars + 1);
			i++;
		}
	}
	return (tab);
}

char				**ft_split_whitespace(char const *s)
{
	size_t	words;
	char	**dst;

	if (s)
	{
		words = ft_countwords(s);
		dst = (char **)malloc(sizeof(char *) * (words + 1));
		if (dst)
		{
			dst = ft_countallocate(dst, s);
			dst = ft_copyarray(dst, s);
			dst[words] = NULL;
			return (dst);
		}
	}
	return (NULL);
}
