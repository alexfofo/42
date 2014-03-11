/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sf_save.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afollin <afollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/05 14:51:52 by afollin           #+#    #+#             */
/*   Updated: 2014/03/10 11:35:25 by afollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin2.h"

int				set_start_end(t_game *game)
{
	if (game->i_start)
	{
		game->start = game->room->name;
		game->i_start = 0;
	}
	if (game->i_end)
	{
		game->end = game->room->name;
		game->i_end = 0;
	}
	return (0);
}

int				ft_is_str_a_link(char *str, t_link *link)
{
	while (link)
	{
		if (!(ft_strcmp(link->name, str)))
			return (1);
		link = link->next;
	}
	return (0);
}

int				sf_save_link(t_room *room, char *room_name, char *link_name)
{
	while (ft_strcmp(room_name, room->name))
		room = room->next;
	if (ft_is_str_a_link(link_name, room->tmp_link))
		return (-1);
	while (room->link != NULL)
	{
		if (room->link->next == NULL)
		{
			room->link->next = ft_new_link();
			room->link = room->link->next;
			break ;
		}
		room->link = room->link->next;
	}
	if (room->link == NULL)
	{
		room->link = ft_new_link();
		room->tmp_link = room->link;
	}
	room->link->name = ft_strdup(link_name);
	return (0);
}

t_link          *ft_new_link(void)
{
	t_link      *link;

	link = (t_link *)malloc(sizeof(t_link));
	link->name = NULL;
	link->next = NULL;
	return (link);
}
