/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_raw_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemchuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 16:27:15 by bsemchuk          #+#    #+#             */
/*   Updated: 2018/03/12 16:13:05 by bsemchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

/*
**	Разбиваем по пробелам или запятым
**	Цю функцію ми використовуємо в ft_strmap
*/

char		ft_replace_commas(unsigned char a)
{
	if (a == ',')
		return (' ');
	return (a);
}

int			is_header(unsigned char *line)
{
	if ((ft_strequ(COMMENT_CMD_STRING, (const char *)line))
			|| ft_strequ(NAME_CMD_STRING, (const char *)line))
		return (YES);
	return (NO);
}

/*
**	Отримуємо розбиту стрічку, першим елементом повинна
**	бути команда яка присутня в глобальній структурі, знайти яку
**	можна у файлі op.c, якщо нульовий елемент закінчується на
**	LABEL_CHAR, то вважається за лейбл і перевіряється на
**	наявність недозволених знаків, якщо команда, то
**	перевіряється чи то справді команда (одна з ор.с) чи якийсь шлак,
**	ну, або ж помилка, опечатка, касатка, гггг
*/

int			treat_instruction(t_line *tline, t_champion *header)
{
	return (treat_command(tline, header));
}

void		get_label_if_present(t_line *tline)
{
	if (ft_endswithchar((const char *)
				tline->deintegrated_line[0], LABEL_CHAR) == YES)
		tline->label = (unsigned char *)
			ft_strsub((const char *)tline->deintegrated_line[0], 0,
			ft_strlen((const char *)(tline->deintegrated_line[0])) - 1);
}
