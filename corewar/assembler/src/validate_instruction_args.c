/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vaidate_instruction_args.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemchuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 15:42:18 by bsemchuk          #+#    #+#             */
/*   Updated: 2018/03/11 19:04:11 by bsemchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int		validate_ind(char *argument, t_champion *champion)
{
	if (argument[0] == LABEL_CHAR)
		return (label_exists(argument, champion));
	else
		return (is_string_valid_int(argument));
}

int		validate_dir(char *argument, t_champion *champion)
{
	argument++;
	if (argument[0] == LABEL_CHAR)
		return (label_exists(argument, champion));
	if (argument[0] == '-' || ft_isdigit(argument[0]) == YES)
		return (is_string_valid_int(argument));
	return (EXIT_FAILURE);
}

int		validate_reg(char *argument)
{
	argument++;
	if (argument[0] == '-')
		return (EXIT_FAILURE);
	return (is_string_valid_int(argument));
}

int		validate_arg(unsigned char arg_type_flag,
		char *argument, t_champion *champion)
{
	if (!arg_type_flag)
		return (EXIT_FAILURE);
	if (arg_type_flag & T_IND)
		return (validate_ind(argument, champion));
	else if (arg_type_flag & T_DIR)
		return (validate_dir(argument, champion));
	else if (arg_type_flag & T_REG)
		return (validate_reg(argument));
	perror("Unsupported type of an argument\n");
	return (EXIT_FAILURE);
}
