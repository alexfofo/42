/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afollin <afollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 14:43:39 by afollin           #+#    #+#             */
/*   Updated: 2014/03/11 12:54:28 by afollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
			ft_putstr_fd(line, 2);
			ft_putendl_fd(": I don't understand", 2);
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

	if ((i = sf_check_links(line, game)))/*check some case d'error*/
		return (i);
	name = ft_get_name(line, '-', 0);/*premier mot*/
	tmproom = game->tmp_room;
	if (ft_is_str_a_room(name, tmproom))
	{
		free(name);/* il faut free tmproom aussi 0.0 */
		name = ft_get_name(line, '-', 1);/*deuxieme mot*/
		tmproom = game->tmp_room;
		if (ft_is_str_a_room(name, tmproom))/* il faut free tmproom */
		{
			free(name);
			return (2);
		}
	}
	ft_putstr_fd("You want to link a room wich is not existing\n", 2);
	ft_putendl_fd("You must be some kind of retard...", 2);
	ft_putendl_fd("Go play in the garden baby", 2);
	return (-5);
}

int					ft_check_line(int index, char *line, t_game *game)
{
	if (index == 0)
	{
		if (!(is_number(line)) || *line == '0')
		{
			ft_putstr_fd("Error about the number of ant\n", 2);
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
