/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemchuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 15:47:55 by bsemchuk          #+#    #+#             */
/*   Updated: 2018/03/12 16:13:50 by bsemchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int			is_label_valid_char(char *label)
{
	int		is;
	int		need;

	is = ft_strspn(LABEL_CHARS, label);
	need = (int)ft_strlen(label);
	if (is == need && is)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

/*
**	Label validation
*/

int			validate_remember_label(char *label, t_champion *champion)
{
	if (is_label_valid_char(label) == EXIT_SUCCESS)
	{
		label_name_into_list(label, champion);
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}

int			count_args(char **deintegrated)
{
	int	i;

	i = 0;
	while (deintegrated[i])
		i++;
	return (i);
}

/*
**	На вході отримуємо вказівник на першу команду
**	тут ми визначаємо команду і валідуємо її аргументи
*/

int			treat_command(t_line *tline, t_champion *champion)
{
	count_args((char **)tline->args);
	write(champion->fdout, &g_op_tab[(unsigned char)
			tline->command_index].opcode, 1);
	return (flush_arguments(tline, champion));
}
