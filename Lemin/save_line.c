/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afollin <afollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 15:38:02 by afollin           #+#    #+#             */
/*   Updated: 2014/03/12 16:54:05 by afollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
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
		if (!(game->room = ft_new_room()))
			return (-1);
		game->tmp_room = game->room;
	}
	else
	{
		if (!(game->room->next = ft_new_room()))
			return (-1);
		game->room = game->room->next;
	}
	split = ft_strsplit(line, ' ');
	game->room->name = ft_strdup(split[0]);
	game->room->coord_x = ft_atoi(split[1]);
	game->room->coord_y = ft_atoi(split[2]);
	set_start_end(game);
	gfree(split[0]);
	gfree(split[1]);
	gfree(split[2]);
	gfree(split);
	split = NULL;
	return (0);
}

static int		ft_save_links(char *line, t_game *game)
{
	char		*lk1;
	char		*lk2;

	lk1 = ft_get_name(line, '-', 0);
	lk2 = ft_get_name(line, '-', 1);
	if (sf_save_link(game->tmp_room, lk1, lk2) == -5)
		return (-1);
	if (sf_save_link(game->tmp_room, lk2, lk1) == -5)
		return (-1);
	gfree(lk1);
	gfree(lk2);
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
	{
		if (ft_save_rooms(line, game) == -1)
			return (-5);
	}
	else if (index == 2)
	{
		if (ft_save_links(line, game) == -1)
			return (-5);
	}
	return (index);
}
