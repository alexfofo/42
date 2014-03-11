/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sf_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afollin <afollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/07 12:06:01 by afollin           #+#    #+#             */
/*   Updated: 2014/03/11 17:53:04 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
			ft_putendl_fd("a room is missing ;) I know you knew", 2);
			return (-5);
		}
		return (2);
	}
	name = ft_get_name(line, ' ', 0);
	if (ft_is_str_a_room(name, game->tmp_room))
	{
		ft_putstr_fd("Please each room must have a different name", 2);
		free(name);
		return (-5);
	}
	free(name);
	return (0);
}

int			sf_check_coords_syntax(char *line)
{
	char		**split;

	if (how_much_c_in_str(' ', line) != 2)
	{
		ft_putstr_fd("Nop, wrong syntax for this coord: ", 2);
		ft_putendl_fd(line, 2);
		return (-5);
	}
	split = ft_strsplit(line, ' ');
	if (!(split[0]) || !(split[1]) || !(split[2]))
	{
		ft_putstr_fd("I need 3 informations here: ", 2);
		ft_putendl_fd("name, coord x, coord y", 2);
		return (-5);
	}
	if (!(is_number(split[1])) || !(is_number(split[2])))
	{
		ft_putstr_fd("Maybe a digit is missing ...\n", 2);
		free(split[0]);
		free(split[1]);
		free(split[2]);
		free(split);
		return (-5);
	}
	return (0);
}

int			sf_check_links(char *line, t_game *game)
{
	if (game->start == NULL)
	{
		ft_putendl_fd("missing a start room", 2);
		return (-5);
	}
	if (game->end == NULL)
	{
		ft_putendl_fd("missing an end room", 2);
		return (-5);
	}
	if (!(ft_strncmp(line, "END", 3)))
		return (-4);
	if (how_much_c_in_str('-', line) != 1)
	{
		ft_putstr_fd("wrong line: ", 2);
		ft_putendl_fd(line, 2);
		return (-5);
	}
	if (how_much_c_in_str(' ', line) != 0)
	{
		ft_putendl_fd("please no spaces 0.0", 2);
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

	room = (t_room *)malloc(sizeof(t_room));
	room->name = NULL;
	room->coord_x = -1;
	room->coord_y = -1;
	room->link = NULL;
	room->next = NULL;
	return (room);
}
