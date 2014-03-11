/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afollin <afollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 14:09:03 by afollin           #+#    #+#             */
/*   Updated: 2014/03/11 17:48:40 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin2.h"

int			main(void)
{
	t_game		*game;

	game = NULL;
	if ((game = ft_save_input(game)) == NULL)
		return (-1);
	if (!(game->start) || !(game->end))
		return (-1);
	game = ft_find_trail(game);
	return (0);
}

t_game		*ft_find_trail(t_game *game)
{
	t_room		*start;
	t_room		*end;
	t_link		*path;
	t_link		*beg;

	path = (t_link *)malloc(sizeof(t_link));
	path->name = ft_strdup(game->start);
	beg = path;
	start = game->tmp_room;
	while (ft_strcmp(start->name, game->start))
			start = start->next;
	end = game->tmp_room;
	while (ft_strcmp(end->name, game->end))
			end = end->next;
	if (ft_find_path(game, start, end, &path) == 1)
		ft_print_path(game, beg);
	else
		ft_putendl_fd("no trail", 2);
	return (game);
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
				return (NULL);
			}
			index = ft_check_line(index, line, game);
			if (index >= 0)
				index = ft_save_line(index, line, game);
			if (index == -1 && !(ft_strcmp(line + 2, "start")))
				game->i_start = 1;
			else if (index == -1)
				game->i_end = 1;
			if (index < 0)
				index *= -1;
		}
	}
	return (game = (index == 5) ? NULL : game);
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
