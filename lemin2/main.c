/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afollin <afollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 14:09:03 by afollin           #+#    #+#             */
/*   Updated: 2014/03/11 12:48:01 by afollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin2.h"

int			main(void)
{
	t_game		*game;

	game = NULL;
	game = ft_save_input(game);
	/* faire un last check pour verifier quon a bien toutes les
	 * infos necessaire comme un start et un end pa exemple*/
	game = ft_find_trail(game);
	return (0);
}

t_game		*ft_find_trail(t_game *game)
{
/*	t_trail		trail;*/
	int			nb_trail_max;
	t_room		*start;
	t_room		*end;
	t_link		*path;
	t_link		*beg;

	path = (t_link *)malloc(sizeof(t_link));
	path->name = ft_strdup(game->start);
	beg = path;
	nb_trail_max = ft_find_nb_trail_max(game->tmp_room, game->start, game->end);
	ft_putstr_fd("nb_trail_max = ", 2);
	ft_putnbr_fd(nb_trail_max, 2);
	ft_putstr_fd("\n", 2);
	start = game->tmp_room;
	while (ft_strcmp(start->name, game->start))
			start = start->next;
	end = game->tmp_room;
	while (ft_strcmp(end->name, game->end))
			end = end->next;
	if (ft_find_path(game, start, end, &path) == 1)
	{
		ft_print_path(game, beg);
	}
	else
		ft_putendl_fd("no trail", 2);
	return (game);
}

/*
** Cette fonction est a supprimer
** Elle permet juste dafficher les link pour une room donnee
*/
static void		ft_display_links(t_link *link)
{
	ft_putstr_fd("\033[1;33m liens: ", 2);
	while (link)
	{
		ft_putstr_fd(link->name, 2);
		ft_putstr_fd(" - ", 2);
		link = link->next;
	}
}

static void		ft_print(t_game *game)
{
	t_room		*tmproom;

	tmproom = game->tmp_room;
	ft_putendl_fd("\033[33m\n Etat general apres avoir save\033[0m", 2);
	ft_putstr("nb ant: ");
	ft_putnbr(game->nb_ant);
	ft_putstr("\n");
	ft_putstr("char start: ");
	ft_putendl(game->start);
	ft_putstr("char end: ");
	ft_putendl(game->end);
	while (tmproom != NULL)
	{
		ft_putstr("room: ");
		ft_putstr(tmproom->name);
		ft_putstr(" . ");
		ft_putnbr(tmproom->coord_x);
		ft_putstr(" . ");
		ft_putnbr(tmproom->coord_y);
		if (tmproom->tmp_link)
			ft_display_links(tmproom->tmp_link);
		ft_putstr("\n\033[0m");
		tmproom = tmproom->next;
	}
}

t_game		*ft_save_input(t_game *game)
{
	char		*line;
	int			index;

	ft_init_vars(&index, &line, &game);
	while (index < 3 && get_next_line(0, &line))
	{
		if (!(is_comment(line)))
		{
			if (!(ft_strcmp(line, "")))
			{
				ft_putendl_fd("I dont like empty line", 2);
				exit(0);
			}
			index = ft_check_line(index, line, game);
			if (index >= 0)
				index = ft_save_line(index, line, game);
			if (index == -1)
			{
				if (!(ft_strcmp(line + 2, "start")))
					game->i_start = 1;
				else
					game->i_end = 1;
			}
			if (index < 0)
				index *= -1;
		}
	}
	ft_print(game);
	return(game);
}

int			ft_init_vars(int *index, char **line, t_game **game)
{
	*index = 0;
	*line = NULL;
	(*game) = (t_game *)malloc(sizeof(t_game));
	(*game)->nb_ant = 0;
	(*game)->i_start = 0;
	(*game)->i_end = 0;
	(*game)->start = NULL;
	(*game)->end = NULL;
	(*game)->room = NULL;
	(*game)->tmp_room = NULL;
	return (0);
}
