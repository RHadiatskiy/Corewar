/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemchuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 19:49:10 by bsemchuk          #+#    #+#             */
/*   Updated: 2017/05/17 22:16:08 by bsemchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_size(intmax_t n)
{
	int size;

	size = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		size++;
	while (n != 0)
	{
		n /= 10;
		size++;
	}
	return (size);
}

static void	ft_write(char *src, intmax_t n, int counter)
{
	int		index;

	index = counter;
	src[index] = '\0';
	if (n < 0)
	{
		src[0] = '-';
		n = -n;
		counter--;
	}
	while (counter)
	{
		src[--index] = (n % 10) + '0';
		n = n / 10;
		counter--;
	}
}

char		*ft_itoa(intmax_t n)
{
	int		size;
	char	*ret;

	size = ft_count_size(n);
	ret = (char *)malloc(sizeof(char) * size + 1);
	if (!ret)
		return (NULL);
	ft_write(ret, n, size);
	return (ret);
}
