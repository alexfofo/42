/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afollin <afollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 14:43:39 by afollin           #+#    #+#             */
/*   Updated: 2014/03/12 16:52:59 by afollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "lemin2.h"

static int			ft_check_coords(int index, char *line, t_game *game)
{
	static int		start = 0;
	static int		end = 0;
	int				i;

	if (*line == '#' && *(line + 1) == '#')
	{
		if (!(ft_strncmp((line + 2), "start", 5)) && start < 1)
			start++;
		else if (!(ft_strncmp((line + 2), "end", 3)) && end < 1)
			end++;
		else
		{
			ft_putendl_fd("ERROR", 2);
			return (-5);
		}
		return (-index);
	}
	if ((i = sf_check_room_name(line, game)))
		return (i);
	if (sf_check_coords_syntax(line))
		return (-5);
	return (index);
}

static int			ft_check_links(char *line, t_game *game)
{
	char		*name;
	t_room		*tmproom;
	int			i;

	if ((i = sf_check_links(line, game)))
		return (i);
	name = ft_get_name(line, '-', 0);
	tmproom = game->tmp_room;
	if (ft_is_str_a_room(name, tmproom))
	{
		gfree(name);
		name = ft_get_name(line, '-', 1);
		tmproom = game->tmp_room;
		if (ft_is_str_a_room(name, tmproom))
		{
			gfree(name);
			return (2);
		}
	}
	ft_putendl_fd("ERROR", 2);
	return (-5);
}

int					ft_check_line(int index, char *line, t_game *game)
{
	if (index == 0)
	{
		if (*line == '-' || ft_strlen(line) > 9
			|| !(is_number(line)) || *line == '0')
		{
			ft_putendl_fd("ERROR", 2);
			cfree();
			exit(0);
		}
		return (0);
	}
	if (index == 1)
		index = ft_check_coords(index, line, game);
	if (index == 2)
		index = ft_check_links(line, game);
	return (index);
}
