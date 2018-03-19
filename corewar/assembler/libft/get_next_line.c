/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemchuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 13:43:24 by bsemchuk          #+#    #+#             */
/*   Updated: 2017/02/16 14:37:41 by bsemchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_text	*search_for_fd(int fd, t_text **basis)
{
	t_text	*temp;

	if (!(*basis))
		return (NULL);
	if ((*basis)->fd == fd)
		return (*basis);
	temp = (*basis)->next;
	while (temp)
	{
		if (temp->fd == fd)
			return (temp);
		temp = temp->next;
	}
	return (NULL);
}

static t_text	*create_elem(int fd, t_text **basis)
{
	t_text *new;
	t_text *temp;

	temp = *basis;
	new = (t_text *)malloc(sizeof(t_text));
	new->fd = fd;
	new->text = NULL;
	new->pos = 0;
	new->next = temp;
	*basis = new;
	return (*basis);
}

static int		copy_text_to_list(const int fd, t_text **elem)
{
	char	buff[BUFF_SIZE + 1];
	int		i;

	i = 0;
	if ((read(fd, NULL, 0)) == ERROR)
		return (ERROR);
	while ((i = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[i] = '\0';
		if ((*elem)->text)
			(*elem)->text = ft_strjoinfree((*elem)->text, buff);
		else if ((*elem)->text == NULL)
		{
			(*elem)->text = (char *)malloc(i + 1);
			ft_strcpy((*elem)->text, buff);
		}
	}
	return (FALSE);
}

static int		pay_debt(const int fd, char **line, t_text **basis)
{
	t_text	*f;
	char	*ret;
	int		i;

	i = 0;
	f = search_for_fd(fd, basis);
	if (f->text[i + f->pos] == '\0')
		return (0);
	while (f->text[i + f->pos] != '\n' && f->text[i + f->pos] != '\0')
		i++;
	ret = (char *)malloc(sizeof(char) * i + 1);
	i = 0;
	while (f->text[i + f->pos] != '\n' && f->text[i + f->pos] != '\0')
	{
		ret[i] = f->text[i + f->pos];
		i++;
	}
	ret[i] = '\0';
	if (f->text[i + f->pos] == '\0')
		--i;
	f->pos += ++i;
	*line = ret;
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static t_text	*elem;

	if (read(fd, NULL, 0) == -1)
		return (-1);
	if ((search_for_fd(fd, &elem)) == NULL)
	{
		elem = create_elem(fd, &elem);
		copy_text_to_list(fd, &elem);
	}
	if (search_for_fd(fd, &elem))
	{
		if (pay_debt(fd, line, &elem) == 0)
			return (0);
	}
	return (1);
}
