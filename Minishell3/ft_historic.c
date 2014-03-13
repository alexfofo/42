/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_historic.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afollin <afollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/07 15:05:28 by afollin           #+#    #+#             */
/*   Updated: 2014/02/07 18:32:03 by afollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_minishell3.h"

t_sl			*ft_listdup(t_sl *list)
{
	t_sl		*new;
	t_sl		*move;

	if (!(new = ft_list_new_elem(list->c)))
		return (NULL);
	move = new;
	list = list->next;
	while (list)
	{
		if (!(move->next = ft_list_new_elem(list->c)))
			return (NULL);
		move->next->prev = move;
		move = move->next;
		list = list->next;
	}
	return (new);
}

static t_hl		*ft_hlist_new_elem(t_sl **list)
{
	t_hl		*new;
	t_sl		*tmp;
	t_sl		*move;

	if (!(new = (t_hl *)malloc(sizeof(*new))))
		return (NULL);
	if (!(new->hist = ft_list_new_elem((*list)->c)))
		return (NULL);
	move = new->hist;
	tmp = *list;
	*list = (*list)->next;
	free((void *)tmp);
	while (*list)
	{
		if (!(move->next = ft_list_new_elem((*list)->c)))
			return (NULL);
		move = move->next;
		tmp = *list;
		*list = (*list)->next;
		free((void *)tmp);
	}
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

static void		ft_move_hist(t_hl **hlist, int *cursor, t_sl **list, int flag)
{
	if ((*hlist)->next && flag == 1)
		*hlist = (*hlist)->next;
	else if ((*hlist)->prev && flag == -1)
		*hlist = (*hlist)->prev;
	*list = ft_listdup((*hlist)->hist);
	*cursor = ft_slist_len(*list);
}

int				ft_historic(char *buf, t_sl **list, t_save *save, t_hl **hlist)
{
	if (KEY_ARROW_UP(buf) && *hlist && save->hist_nb < save->hlen)
	{
		if (save->hist_nb)
			ft_move_hist(hlist, &(save->cursor), list, 1);
		else
			ft_move_hist(hlist, &(save->cursor), list, 0);
		++(save->hist_nb);
	}
	else if (KEY_ARROW_DOWN(buf) && *hlist)
	{
		if (save->hist_nb > 1)
			ft_move_hist(hlist, &save->cursor, list, -1);
		else
		{
			*list = NULL;
			save->cursor = 0;
		}
		--(save->hist_nb);
	}
	else
		return (1);
	return (0);
}

int				ft_in_history(t_hl **hlist, t_sl **list)
{
	t_hl	*new_elem;
	t_sl	*move;

	if (!*list)
		return (0);
	move = ft_listdup(*list);
	if (!(new_elem = ft_hlist_new_elem(&move)))
		return (-1);
	if (!*hlist)
		*hlist = new_elem;
	else
	{
		new_elem->next = *hlist;
		(*hlist)->prev = new_elem;
		*hlist = new_elem;
	}
	return (0);
}
