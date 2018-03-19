/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemchuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 15:17:33 by bsemchuk          #+#    #+#             */
/*   Updated: 2018/03/11 18:49:08 by bsemchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lists.h"
#include "../includes/asm.h"

/*
**	Перевірити рекурсивну функцію
*/

unsigned		ft_llen(t_llist *head)
{
	if (head->next)
		return (ft_llen(head->next));
	return (0);
}

/*
**	ft_ListDataCopyPushFront
**	Приймає поінтер на інформацію яку
**	треба скопіювати і закинути в початок списку
**	Виділяє память під структуру t_llist, після чого
**	виділяє size памʼяті в елемент data.
**	після виділення памяті size байтів з data
**	копіюється до new_node->data.
**	в елемент next записує адресу попереднього початку
**	списку, тобто був head_ref, а став new_node->head_ref
**	після чого, важку тяжість head_ref бере на себе new_node,
**	оскільки head_ref означає ссилку на перший елемент,
**	а першим елементом стає наша new_node, і виходить: head_ref->old_node.
**	Якщо head_ref = NULL, то нічого не відбувається,
**	якщо ж head_ref вказує на невалідну адресу, behavior is undefined
*/

void			ft_ldcpushf(t_llist **head_ref, void *new_data, size_t size)
{
	t_llist		*new_node;

	if (head_ref)
	{
		new_node = ft_calloc(1, sizeof(t_llist));
		new_node->data = ft_calloc(1, size);
		new_node->next = (*head_ref);
		memcpy(new_node->data, new_data, size);
		*head_ref = new_node;
	}
}

/*
**  ft_ListDataCopy push Back
**	Якщо head_ref = NULL, нічого не відбувається,
**	якщо head_ref не NULL, то створюється new_node, під яку виділяється
**	памʼять у кількості size байтів, після чого size кількість байтів
**	копіюється з new_data до new_node->data, якщо
**	head_ref не вказує на NULL (є різниця між head_ref не NULL,
**	і head_ref не вказує на NULL, оскільки в функцію ми
**	передаємо адресу змінної і сама функція не повертає нічого,
**	тому єдиним варіантом є передавати адресу змінної
**	в яку можна записати адресу виділеної памяті, вона ж
**	new_node з копією нашої data; // ДОПИСАТИ
*/

void			ft_ldcpushb(t_llist **head_ref, void *new_data, size_t size)
{
	t_llist		*new_node;
	t_llist		*temp;

	if (head_ref)
	{
		new_node = (t_llist *)ft_calloc(1, sizeof(t_llist));
		new_node->data = ft_calloc(1, size);
		ft_memcpy(new_node->data, new_data, size);
		if (!*head_ref)
			*head_ref = new_node;
		else
		{
			temp = *head_ref;
			while (temp->next)
				temp = temp->next;
			temp->next = new_node;
		}
	}
}

/*
**  ft_ListData pop
**	Приймає адресу на початок ліста, поінтер на перший елемент робить
**	поінтером на другий елемент, перший елемент
**	функція звільняє, а інформацію його повертає.
*/

void			*ft_ldpop(t_llist **head_ref)
{
	t_llist		*node;
	void		*data;

	if (!head_ref || !*head_ref)
		return (NULL);
	node = *head_ref;
	*head_ref = node->next;
	data = node->data;
	free(node);
	return (data);
}

/*
**	Рекурсивне видалення списку
*/

void			ft_ldela(t_llist *head)
{
	if (head)
	{
		if (head->next)
			ft_ldela(head->next);
		free(head->data);
		free(head);
	}
}
