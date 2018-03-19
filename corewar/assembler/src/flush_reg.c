/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flush_reg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemchuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 17:48:05 by bsemchuk          #+#    #+#             */
/*   Updated: 2018/03/11 17:48:20 by bsemchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int					flush_reg(char *arg, t_champion *champion)
{
	unsigned char	cu;
	char			*substring;

	substring = &arg[1];
	cu = (unsigned char)ft_atoi(substring);
	if (write(champion->fdout, &cu, 1) == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
