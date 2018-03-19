/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   useful.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemchuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 15:42:15 by bsemchuk          #+#    #+#             */
/*   Updated: 2018/03/11 19:01:38 by bsemchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

/*
**	while ((str[i] != '\t' || str[i] != ' ') && str[i])	// works
**		i++;
**
**	while (str[i] != '\t' || str[i] != ' ' && str[i])	// doesn't
**		i++;
*/

char		*ft_strjumpword(char *str, unsigned n)
{
	int	i;

	i = 0;
	while ((str[i] == '\t' || str[i] == ' ') && str[i])
		i++;
	while (n)
	{
		while ((str[i] != '\t' && str[i] != ' ') && str[i])
			i++;
		while ((str[i] == '\t' || str[i] == ' ') && str[i])
			i++;
		n--;
	}
	return (&str[i]);
}

int			ft_nchar(char const *str, char ch)
{
	int		i;
	int		count;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == ch)
			count++;
		i++;
	}
	return (count);
}

/*
**	Не захищена нічим команда
*/

int			ft_startswithchar(char const *line, char is)
{
	if (!line)
		return (0);
	if (line[FIRST_ITEM] == is)
		return (1);
	return (0);
}

int			ft_endswithchar(char const *line, char with)
{
	size_t	len;

	len = ft_strlen(line);
	if (!len || !line)
		return (0);
	if (line[len - 1] == with)
		return (1);
	return (0);
}

int			ft_strchindex(char const unsigned *line, unsigned char ch)
{
	int		index;

	index = 0;
	if (!line)
		return (-1);
	while (line[index])
		if (line[index++] == ch)
			return (--index);
	return (-1);
}
