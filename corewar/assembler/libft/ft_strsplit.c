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

static size_t		ft_countwords(char const *s, char c)
{
	size_t			i;
	size_t			w;

	i = 0;
	w = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
		{
			w++;
			i++;
		}
		else
			i++;
	}
	return (w);
}

static char			**ft_copyarray(char **d, char const *s, char c)
{
	size_t			count;
	size_t			i;
	size_t			j;

	count = 0;
	i = 0;
	while (s[count])
	{
		j = 0;
		while (s[count] == c && s[count])
			count++;
		if (s[count] != c && s[count])
		{
			while (s[count] != c && s[count])
				d[i][j++] = s[count++];
			d[i][j] = '\0';
			i++;
		}
	}
	return (d);
}

static char			**ft_countallocate(char **tab, char const *s, char c)
{
	size_t			count;
	size_t			i;
	size_t			chars;

	i = 0;
	count = 0;
	while (s[count] != '\0')
	{
		chars = 0;
		while (s[count] == c && s[count] != '\0')
			count++;
		while (s[count] != c && s[count] != '\0')
		{
			chars++;
			count++;
		}
		if (chars != 0)
		{
			tab[i] = (char *)malloc(sizeof(char) * chars + 1);
			i++;
		}
	}
	return (tab);
}

char				**ft_strsplit(char const *s, char c)
{
	size_t	words;
	char	**dst;

	if (s)
	{
		words = ft_countwords(s, c);
		dst = (char **)malloc(sizeof(char *) * (words + 1));
		if (dst)
		{
			dst = ft_countallocate(dst, s, c);
			dst = ft_copyarray(dst, s, c);
			dst[words] = NULL;
			return (dst);
		}
	}
	return (NULL);
}
