/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afollin <afollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 14:09:03 by afollin           #+#    #+#             */
/*   Updated: 2014/03/04 18:26:00 by afollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin2.h"

int			main(void)
{
	ft_save_input();
	return (0);
}

t_game		ft_save_input(void)
{
	t_game		game;
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
			index = ft_check_line(index, line);
			if (index >= 0)
				index = ft_save_line(index, line, &game);
			if (index == -1)
			{
				if (!(ft_strcmp(line + 2, "start")))
					game.i_start = 1;
				else
					game.i_end = 1;
			}
			if (index < 0)
				index *= -1;
/*			ft_putstr("                        line:");
			ft_putstr(line);
			ft_putendl(".");*/
		}
	}
		ft_putstr("nb ant: ");
		ft_putnbr(game.nb_ant);
		ft_putstr("\n");
		ft_putnbr(game.i_start);
		ft_putstr("char start: ");
		ft_putendl(game.start);
		ft_putstr("char end: ");
		ft_putendl(game.end);
		while (game.tmp_room)
		{
			ft_putstr("room: ");
			ft_putstr(game.tmp_room->name);
			ft_putstr(" . ");
			ft_putnbr(game.tmp_room->coord_x);
			ft_putstr(" . ");
			ft_putnbr(game.tmp_room->coord_y);
			ft_putstr("\n");
			game.tmp_room = game.tmp_room->next;
		}
	return(game);
}

int			ft_init_vars(int *index, char **line, t_game *game)
{
	*index = 0;
	*line = NULL;
	game->nb_ant = 0;
	game->i_start = 0;
	game->i_end = 0;
	game->start = NULL;
	game->end = NULL;
	game->room = NULL;
	game->tmp_room = NULL;
	return (0);
}
