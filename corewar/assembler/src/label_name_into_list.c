/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label_name_into_list.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemchuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 18:44:15 by bsemchuk          #+#    #+#             */
/*   Updated: 2018/03/11 18:44:30 by bsemchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

/*
**	"forks:" -- приклад лейбла, він не повинен тримати в собі інших знаків окрім
**	тих, які позначені в хедері op.h, в цій функції валідується лейбл
*/

int			label_name_into_list(char *label_in_line, t_champion *champion)
{
	char	*label_name;
	t_label	tlabel;

	ft_bzero(&tlabel, sizeof(tlabel));
	label_name = ft_strsub(label_in_line, 0, ft_strlen(label_in_line));
	tlabel.name = label_name;
	ft_ldcpushb(&champion->labels, &tlabel, sizeof(t_label));
	return (EXIT_SUCCESS);
}
