/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_filename_extension.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemchuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 17:20:30 by bsemchuk          #+#    #+#             */
/*   Updated: 2018/03/11 17:35:01 by bsemchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static int	is_extension_valid(char *file_extension)
{
	if (ft_strncmp(file_extension, ASM_IN_EXTENSION,
				ft_strlen((ASM_OUT_EXTENSION) + 1)) != 0)
	{
		perror("Wrong file extension");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int			change_filename_extension(char *path, char **new_name)
{
	char	*file_extension;
	char	**d;
	int		i;

	i = 0;
	if (!new_name)
		return (EXIT_FAILURE);
	d = ft_strsplit(path, '/');
	if (d)
		while (d[i])
			i++;
	file_extension = ft_strrchr(d[i - 1], '.');
	if (!file_extension)
	{
		perror("No file extension");
		return (EXIT_FAILURE);
	}
	file_extension = ft_strrchr(path, '.');
	if (is_extension_valid(file_extension) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	file_extension[0] = '\0';
	*new_name = ft_strjoin(path, ASM_OUT_EXTENSION);
	ft_delete_deintegrated(d);
	return (EXIT_SUCCESS);
}
