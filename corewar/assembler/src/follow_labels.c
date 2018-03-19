/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remember_all_labels.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemchuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 15:41:54 by bsemchuk          #+#    #+#             */
/*   Updated: 2018/03/11 17:50:24 by bsemchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

/*
**	Підраховуємо кількість рядків і записуємо лейбли в структуру
*/

int		remember_all_labels_and_count_lines(t_champion *champion)
{
	char		*line;
	char		**deintegrated;

	while ((line = get_raw_line_fd(champion->fdin)))
	{
		champion->lines_count++;
		deintegrated = ft_split_whitespace(line);
		if (ft_endswithchar(deintegrated[FIRST_ITEM], LABEL_CHAR))
		{
			deintegrated[FIRST_ITEM][ft_strlen(
					deintegrated[FIRST_ITEM]) - 1] = '\0';
			if (validate_remember_label(deintegrated[FIRST_ITEM], champion)
					== EXIT_FAILURE)
				return (EXIT_FAILURE);
		}
		ft_delete_deintegrated(deintegrated);
		free(line);
	}
	return (EXIT_SUCCESS);
}
