/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basics2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afollin <afollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/04 16:00:20 by afollin           #+#    #+#             */
/*   Updated: 2014/03/11 11:25:57 by afollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin2.h"

int			ft_find_nb_trail_max(t_room *room, char *start, char *end)
{
	int			nb_trail_max;
	int			tmp;

	nb_trail_max = 0;
	if (!(ft_strcmp(start, end)))
		return (1);
	while (room && ft_strcmp(start, room->name) && ft_strcmp(end, room->name))
		room = room->next;
	nb_trail_max = ft_count_links(room->tmp_link);
	room = room->next;
	while (room && ft_strcmp(start, room->name) && ft_strcmp(end, room->name))
		room = room->next;
	if (room && ((tmp = ft_count_links(room->tmp_link)) < nb_trail_max))
			nb_trail_max = tmp;
	return (nb_trail_max);
}

int			ft_count_links(t_link *link)
{
	int			i;

	i = 0;
	while (link)
	{
		i++;
		link = link->next;
	}
	if (i)
		return (i);
	return (0);
}
