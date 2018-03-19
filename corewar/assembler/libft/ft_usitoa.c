/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usitoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemchuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 19:49:10 by bsemchuk          #+#    #+#             */
/*   Updated: 2017/05/31 17:14:15 by bsemchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_size(uintmax_t n)
{
	int size;

	size = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		size++;
	}
	return (size);
}

static void	ft_write(char *src, uintmax_t n, int counter)
{
	int		index;

	index = counter;
	src[index] = '\0';
	while (counter)
	{
		src[--index] = (n % 10) + '0';
		n = n / 10;
		counter--;
	}
}

char		*ft_usitoa(intmax_t n)
{
	int			size;
	char		*ret;

	n = (n < 0) ? (uintmax_t)-n : (uintmax_t)n;
	size = ft_count_size((uintmax_t)n);
	ret = (char *)malloc(sizeof(char) * size + 1);
	if (!ret)
		return (NULL);
	ft_write(ret, (uintmax_t)n, size);
	return (ret);
}
