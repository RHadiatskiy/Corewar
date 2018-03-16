/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pchar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daleksan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 13:34:24 by daleksan          #+#    #+#             */
/*   Updated: 2017/04/04 13:35:35 by daleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pstr(char *str, int len)
{
	if (len > 0)
	{
		write(1, &str, len);
		return (len);
	}
	else
	{
		write(1, &str, ft_strlen(str));
	}
	return (ft_strlen(str));
	
}

int	ft_pchar(int i, char c)
{
	int j;

	j = 0;
	while (j < i)
	{
		write(1, &c, 1);
		j++;
	}
	return (j);
}
