/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delete_deintegrated.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemchuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 21:57:16 by bsemchuk          #+#    #+#             */
/*   Updated: 2017/11/20 21:57:30 by bsemchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_delete_deintegrated(char **deintegrated)
{
	int				i;

	i = 0;
	while (deintegrated[i])
		free(deintegrated[i++]);
	free(deintegrated);
}
