/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemchuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 13:42:36 by bsemchuk          #+#    #+#             */
/*   Updated: 2017/10/23 13:44:20 by bsemchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LISTS_H
# define LISTS_H
# include <stdlib.h>
# include <memory.h>

typedef struct		s_llist
{
	void			*data;
	struct s_llist	*next;
}					t_llist;

void				ft_ldcpushf(t_llist **head_ref,
											void *new_data, size_t size);
void				ft_ldcpushb(t_llist **head_ref,
											void *new_data, size_t size);
void				*ft_ldpop(t_llist **head_ref);

void				ft_lrev(t_llist **head_ref);

void				ft_ldela(t_llist *head);

t_llist				*ft_adj(unsigned v1);

#endif
