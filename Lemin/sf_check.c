/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sf_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afollin <afollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/07 12:06:01 by afollin           #+#    #+#             */
/*   Updated: 2014/03/12 16:54:29 by afollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lemin2.h"

int			sf_check_room_name(char *line, t_game *game)
{
	char		*name;
	char		**split;

	split = ft_strsplit(line, ' ');
	if ((split[0][0] != '-' && split[1] && split[1][0] != '-'
		&& split[2] && split[2][0] != '-' && how_much_c_in_str('-', line) > 0)
		|| (!split[1] && how_much_c_in_str('-', line) > 0))
	{
		if (game->room == NULL || game->i_start || game->i_end)
		{
			ft_putendl_fd("ERROR", 2);
			return (-5);
		}
		return (2);
	}
	name = ft_get_name(line, ' ', 0);
	if (ft_is_str_a_room(name, game->tmp_room))
	{
		ft_putendl_fd("ERROR", 2);
		gfree(name);
		return (-5);
	}
	gfree(name);
	return (0);
}

int			sf_check_coords_syntax(char *line)
{
	char		**split;

	if (how_much_c_in_str(' ', line) != 2)
	{
		ft_putendl_fd("ERROR", 2);
		return (-5);
	}
	split = ft_strsplit(line, ' ');
	if (!(split[0]) || !(split[1]) || !(split[2]))
	{
		ft_putendl_fd("ERROR", 2);
		return (-5);
	}
	if (!(is_number(split[1])) || !(is_number(split[2])))
	{
		ft_putendl_fd("ERROR", 2);
		gfree(split[0]);
		gfree(split[1]);
		gfree(split[2]);
		gfree(split);
		return (-5);
	}
	return (0);
}

int			sf_check_links(char *line, t_game *game)
{
	if (game->start == NULL)
	{
		ft_putendl_fd("ERROR", 2);
		return (-5);
	}
	if (game->end == NULL)
	{
		ft_putendl_fd("ERROR", 2);
		return (-5);
	}
	if (!(ft_strncmp(line, "END", 3)))
		return (-4);
	if (how_much_c_in_str('-', line) != 1)
	{
		ft_putendl_fd("ERROR", 2);
		return (-5);
	}
	if (how_much_c_in_str(' ', line) != 0)
	{
		ft_putendl_fd("ERROR", 2);
		return (-5);
	}
	return (0);
}

int			ft_is_str_a_room(char *str, t_room *room)
{
	while (room)
	{
		if (!(ft_strcmp(room->name, str)))
			return (1);
		room = room->next;
	}
	return (0);
}

t_room		*ft_new_room(void)
{
	t_room		*room;

	if (!(room = (t_room *)gmalloc(sizeof(t_room))))
		return (NULL);
	room->name = NULL;
	room->coord_x = -1;
	room->coord_y = -1;
	room->link = NULL;
	room->next = NULL;
	return (room);
}
