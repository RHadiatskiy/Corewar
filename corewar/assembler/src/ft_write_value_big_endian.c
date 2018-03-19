/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_value_big_endian.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemchuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 18:59:32 by bsemchuk          #+#    #+#             */
/*   Updated: 2018/03/12 22:48:41 by bsemchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int			ft_write_value_big_e2(int fd, unsigned short number)
{
	int		i;
	t_u		u;

	i = 1;
	u.si = number;
	while (i >= 0)
	{
		if (write(fd, &u.cu[i], 1) == -1)
			perror("Write return = -1");
		i--;
	}
	return (0);
}

int			ft_write_value_big_e4(int fd, int number)
{
	t_union	u;
	int		i;

	i = 3;
	u.i = number;
	while (i >= 0)
	{
		if (write(fd, &u.ch[i], 1) == -1)
			perror("Write return = -1");
		i--;
	}
	return (0);
}
