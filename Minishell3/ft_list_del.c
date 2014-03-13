/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_del.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afollin <afollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/07 15:06:11 by afollin           #+#    #+#             */
/*   Updated: 2014/02/07 15:06:12 by afollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_minishell3.h"

static void		ft_list_del_elem_2(t_sl **list, int cursor)
{
	t_sl		*tmp;
	t_sl		*move;
	int			i;

	move = *list;
	if (cursor == 0)
		*list = (*list)->next;
	else
	{
		i = -1;
		while (++i < cursor - 1)
			move = move->next;
		tmp = move;
		move = move->next;
		tmp->next = move->next;
		if (move->next)
			(move->next)->prev = tmp;
	}
	(*list)->prev = NULL;
	move->prev = NULL;
	move->next = NULL;
	free((void *)move);
}

void			ft_list_del_elem(t_sl **list, int cursor)
{
	if (!(*list)->next)
	{
		free((void *)*list);
		*list = NULL;
	}
	else
		ft_list_del_elem_2(list, cursor);
}
