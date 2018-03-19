/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemchuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 01:40:52 by bsemchuk          #+#    #+#             */
/*   Updated: 2017/01/03 22:10:59 by bsemchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int			is_whitespace(const char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	else
		return (0);
}

static int			size_malloc(const char *s)
{
	char	*p1;
	char	*p2;

	p1 = (char *)s;
	p2 = (char *)s;
	while (*p2)
		p2++;
	while (p1 != p2)
	{
		if (is_whitespace(*p1) == 1)
			p1++;
		else
			break ;
	}
	while (p2 != s)
	{
		if (is_whitespace(*p2) == 1 || *p2 == '\0')
			p2--;
		else
			break ;
	}
	if (p2 >= p1)
		return ((p2 - p1) + 2);
	else
		return (0);
}

static const char	*start_p(const char *s)
{
	while (is_whitespace(*s) == 1)
		s++;
	return (s);
}

static const char	*end_p(const char *s)
{
	char	*limit;

	limit = (char *)s;
	while (*s)
		s++;
	while (s != limit && (is_whitespace(*s) == 1 || *s == '\0'))
	{
		s--;
	}
	return (s);
}

char				*ft_strtrim(const char *s)
{
	char	*ret;
	char	*start;
	char	*end;
	char	*crt;

	if (!s)
		return (NULL);
	if (size_malloc(s) == 0)
	{
		ret = (char *)malloc(sizeof(char));
		*ret = '\0';
	}
	else
	{
		crt = (char *)malloc(sizeof(char) * (size_malloc(s)));
		if (!crt)
			return (NULL);
		ret = crt;
		start = (char *)(start_p(s));
		end = (char *)(end_p(s));
		while (start <= end)
			*crt++ = *start++;
		*crt = '\0';
	}
	return (ret);
}
