/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemchuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 16:40:16 by bsemchuk          #+#    #+#             */
/*   Updated: 2018/03/12 22:49:33 by bsemchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int			i;
	int			sign;
	long int	res;

	if (!str)
		return (0);
	i = 0;
	res = 0;
	sign = 0;
	while ((str[i] == '\n' || str[i] == '\t' \
			|| str[i] == ' ' || str[i] == '\v' \
			|| str[i] == '\f' || str[i] == '\r') && str)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		sign = str[i];
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return ((sign == '-') ? ((int)-res) : ((int)res));
}
