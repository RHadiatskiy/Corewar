/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fd_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemchuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 15:23:17 by bsemchuk          #+#    #+#             */
/*   Updated: 2017/11/17 15:28:05 by bsemchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include "libft.h"

int		ft_fd_valid(int fd)
{
	if ((read(fd, 0, 0) == -1) || fd == -1)
	{
		perror("File descriptor problem");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
