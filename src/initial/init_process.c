/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 20:47:45 by rhadiats          #+#    #+#             */
/*   Updated: 2017/12/28 20:47:47 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/vm.h"

t_process				*init_process(void)
{
	t_process			*process;

	if (!(process = (t_process *)malloc(sizeof(t_process))))
		return (NULL);
	process->pc = -1;
	process->reg = (int *)malloc(sizeof(int) * REG_NUMBER);
	ft_bzero(process->reg, REG_NUMBER);
	process->carry = 0;
	process->next = NULL;
	return (process);
}