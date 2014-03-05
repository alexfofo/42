/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afollin <afollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 14:43:39 by afollin           #+#    #+#             */
/*   Updated: 2014/03/05 15:10:50 by afollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin2.h"

int			ft_check_line(int index, char *line, t_game *game)
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

int			ft_check_coords(int index, char *line, t_game *game)
{
	static int		start = 0;
	static int		end = 0;
	char			*name;

	if (*line == '#' && *(line + 1) == '#')
	{
		if (!(ft_strncmp((line + 2), "start", 5)) && start < 1)
			start++;
		else if (!(ft_strncmp((line + 2), "end", 3)) && end < 1)
			end++;
		else
		{
			ft_putstr_fd("bad coord: ", 2);
			ft_putendl_fd(line, 2);
			return (-5);
		}
		return (-index);
	}
	if (how_much_c_in_str('-', line) > 0)
	{
		if (game->room == NULL || game->i_start || game->i_end)
		{
			ft_putendl_fd("a room is missing                     bitch", 2);
			return (-5);
		}
		return (index + 1);
	}
	if (how_much_c_in_str(' ', line) != 2)
	{
		ft_putstr_fd("nop, wrong syntaxe for this coord", 2);
		ft_putendl_fd(line, 2);
		return (-5);
	}
	/* GERER le CAS OU ON DECLARE DEUX SALLES AVEC LE MEME NAME */
	name = ft_get_name(line, ' ', 0);
	if (ft_is_str_a_room(name, game->tmp_room))
	{
		ft_putstr_fd("Please each room must have a different name    hore", 2);
		return (-5);
	}
	while (*line != ' ')
		line++;
	line++;
	if (!(ft_isdigit(*line)))
	{
		ft_putstr_fd("Maybe a digit is missing...\n", 2);
		return (-5);
	}
	while (ft_isdigit(*line))
		line++;
	line++;
	if (!(ft_isdigit(*line)))
	{
		ft_putstr_fd("Maybe a digit is missing...\n", 2);
		return (-5);
	}
	while (ft_isdigit(*line))
		line++;
	if (*line)
		return (-5);
	return (index);
}

int			ft_check_links(char *line, t_game *game)
{
	char		*name;
	t_room		*tmproom;

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
	name = ft_get_name(line, '-', 0);/*premier mot*/
/*	ft_putstr_fd("\033[34m \nLe name obtenu est : \033[0m", 2);
	ft_putstr_fd(name, 2);*/
	tmproom = game->tmp_room;
/*	while (tmproom)
	{
		if (!(ft_strcmp(tmproom->name, name)))
		{
			free(name);
			name = ft_get_name(line, '-', 1);*//*deuxieme mot*//*il manque des free*/
/*			tmproom = game->tmp_room;
			while (tmproom)
			{
				if (!(ft_strcmp(tmproom->name, name)))
					return (2);
				tmproom = tmproom->next;
			}
			ft_putstr_fd("You want to link a room wich is not existing\n", 2);
			ft_putendl_fd("You must be some kind of retard...", 2);
			ft_putendl_fd("Go play in the garden baby", 2);
		}
		tmproom = tmproom->next;
	}*/
	if (ft_is_str_a_room(name, tmproom))
	{
		free(name);/* il faut free tmproom aussi 0.0 */
		name = ft_get_name(line, '-', 1);
		tmproom = game->tmp_room;
		if (ft_is_str_a_room(name, tmproom))/* il faut free name et tmprom */
			return (2);
	}
	ft_putstr_fd("You want to link a room wich is not existing\n", 2);
	ft_putendl_fd("You must be some kind of retard...", 2);
	ft_putendl_fd("Go play in the garden baby", 2);
	return (-5);
}
