/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 22:40:08 by rhadiats          #+#    #+#             */
/*   Updated: 2017/11/20 22:40:10 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/corewar.h"

// static int				valid_magic(char *data)
// {
// 	(void)data;
// 	return (1);
// }

// static int				valid_prog_name(int data)
// {
// 	(void)data;
// 	return (1);
// }

// static int				valid_prog_size(int data)
// {
// 	(void)data;
// 	return (1);
// }

// static int				valid_comment(int data)
// {
// 	(void)data;
// 	return (1);
// }

int						validation(t_core *info, char *av)
{
	int					fd;

	if ((fd = open(av, O_RDONLY)) < 0)
		perror ("can't open the file");
	info->data_len = lseek(fd, 0, SEEK_END);
	lseek(fd, 0, SEEK_SET);
	if (!(info->data = (unsigned char *)malloc(sizeof(unsigned char) * info->data_len + 1)))
		perror ("can't allocate a memory");
	if (!(read(fd, info->data, info->data_len)))
		perror ("can't reed the file");

	// printd(data);
	// ft_printf("is comp: %d\n", (int)data == COREWAR_EXEC_MAGIC);
	// ft_printf("data : %x\nmagic : %x\n", (int)data, COREWAR_EXEC_MAGIC);
	parsing(info, info->data);
	print_data(info->data, info->data_len);
	close(fd);
	return (1);
}
