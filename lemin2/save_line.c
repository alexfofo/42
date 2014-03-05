/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afollin <afollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 15:38:02 by afollin           #+#    #+#             */
/*   Updated: 2014/03/05 16:35:58 by afollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin2.h"

static int		ft_save_ant(char *line, t_game *game)
{
	game->nb_ant = ft_atoi(line);
	return (0);
}

static int		ft_save_rooms(char *line, t_game *game)
{
	char		**split;

	if (game->room == NULL)
	{
		game->room = ft_new_room();
		game->tmp_room = game->room;
	}
	else
	{
		game->room->next = ft_new_room();
		game->room = game->room->next;
	}
	split = ft_strsplit(line, ' ');
	game->room->name = ft_strdup(split[0]);
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
	game->room->coord_x = ft_atoi(split[1]);
	game->room->coord_y = ft_atoi(split[2]);
	free(split[0]);
	free(split[1]);
	free(split[2]);
	free(split);
	split = NULL;
	return (0);
}

static int		ft_save_links(char *line, t_game *game)
{
	char		*lk1;
	char		*lk2;
	t_room		*tmproom;
	
	lk1 = ft_get_name(line, '-', 0);
	lk2 = ft_get_name(line, '-', 1);
	tmproom = game->tmp_room;
	while (ft_strcmp(lk1, tmproom->name))
		tmproom = tmproom->next;
	while (tmproom->link != NULL)
	{
		if (tmproom->link->next == NULL)
		{
			tmproom->link->next = ft_new_link();
			tmproom->link = tmproom->link->next;
			break ;
		}
		tmproom->link = tmproom->link->next;
	}
	if (tmproom->link == NULL)
	{
		tmproom->link = ft_new_link();
		tmproom->tmp_link = tmproom->link;
	}
	tmproom->link->name = lk2;
	tmproom = game->tmp_room/* free il faudra */;
/*	while (ft_strcmp(lk2, tmproom->name))
		tmproom = tmproom->next;
	while (tmproom->link != NULL)
		tmproom->link = tmproom->link->next;
	tmproom->link = ft_new_link();*/
/**/while (ft_strcmp(lk2, tmproom->name))
		tmproom = tmproom->next;
	while (tmproom->link != NULL)
	{
		if (tmproom->link->next == NULL)
		{
			tmproom->link->next = ft_new_link();
			tmproom->link = tmproom->link->next;
			break ;
		}
		tmproom->link = tmproom->link->next;
	}
	if (tmproom->link == NULL)
	{
		tmproom->link = ft_new_link();
		tmproom->tmp_link = tmproom->link;
	}/**//*la partie en com au dessu pourrai remplacer la partie entre comm*/
	tmproom->link->name = lk1;/* free il faudra */
	return (0);
}

int				ft_save_line(int index, char *line, t_game *game)
{
	if (index == 0)
	{
		ft_save_ant(line, game);
		index++;
	}
	else if (index == 1)
		ft_save_rooms(line, game);
	else if (index == 2)
		ft_save_links(line, game);
	return (index);
}
