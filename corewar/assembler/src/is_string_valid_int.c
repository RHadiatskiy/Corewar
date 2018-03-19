/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_string_valid_int.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemchuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 18:42:55 by bsemchuk          #+#    #+#             */
/*   Updated: 2018/03/11 18:43:03 by bsemchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int				is_string_valid_int(const char *argument)
{
	unsigned	i;

	i = 0;
	if (argument[i] == '-')
		i++;
	while (ft_isdigit(argument[i]))
		i++;
	if (ft_strlen(argument) == i)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}
