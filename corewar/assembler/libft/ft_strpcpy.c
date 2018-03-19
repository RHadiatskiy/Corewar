/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemchuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 18:00:35 by bsemchuk          #+#    #+#             */
/*   Updated: 2017/06/27 17:23:57 by bsemchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strpcpy(char *s1, char *s2)
{
	int		len;
	char	*ret;

	len = s2 - s1;
	ret = (char *)malloc(sizeof(char) * len + 1);
	ft_strncpy(ret, s1, len);
	return (NULL);
}
