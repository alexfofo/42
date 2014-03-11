/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afollin <afollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/11 11:51:50 by afollin           #+#    #+#             */
/*   Updated: 2014/03/11 12:52:42 by afollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lemin2.h"

int			ft_find_path(t_game *game, t_room *start, t_room *end, t_link **p)
{
	t_room		*move;
	t_link		*new;
	t_room		*new_start;
	t_link		*rem;

	move = start;
	rem = NULL;
	new = NULL;
	new_start = NULL;
	if (move && move != end)
	{
		while (move->tmp_link)
		{
			if ((*p && !ft_strcmp(move->tmp_link->name, (*p)->name))
				|| !ft_strcmp(move->tmp_link->name, game->start))
				move->tmp_link = move->tmp_link->next;
			if (!move->tmp_link)
				return (0);
			new = ft_new_link();
			new->name = ft_strdup(move->tmp_link->name);
			rem = *p;
			if (*p)
			{
				(*p)->next = new;
				(*p) = (*p)->next;
			}
			else
				(*p) = new;
			new_start = game->tmp_room;
			while (ft_strcmp(new_start->name, move->tmp_link->name))
				new_start = new_start->next;
			if (ft_find_path(game, new_start, end, p) == 1)
				return (1);
			move->tmp_link = move->tmp_link->next;
			*p = rem; 
		}
	}
	if (move == end)
		return (1);
	return (0);                                                                      
}
