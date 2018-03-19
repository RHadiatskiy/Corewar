/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemchuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 15:31:33 by bsemchuk          #+#    #+#             */
/*   Updated: 2017/04/06 15:34:29 by bsemchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnchr(char *start, char *end, char aim)
{
	while (start != end && *start)
	{
		if (*start == aim)
			return (start);
		start++;
	}
	return (NULL);
}
