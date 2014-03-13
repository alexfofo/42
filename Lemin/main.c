/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afollin <afollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 14:09:03 by afollin           #+#    #+#             */
/*   Updated: 2014/03/12 16:53:45 by afollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lemin2.h"

int			main(void)
{
	t_game		*game;
	t_link		*hist;

	game = NULL;
	hist = NULL;
	if ((game = ft_save_input(game, &hist)) == NULL)
	{
		cfree();
		return (-1);
	}
	if (!(game->start) || !(game->end))
	{
		cfree();
		return (-1);
	}
	game = ft_find_trail(game, hist);
	cfree();
	return (0);
}

t_game		*ft_find_trail(t_game *game, t_link *hist)
{
	t_room		*start;
	t_room		*end;
	t_link		*path;
	t_link		*beg;

	if (!(path = (t_link *)gmalloc(sizeof(t_link))))
		return (NULL);
	path->name = ft_strdup(game->start);
	beg = path;
	start = game->tmp_room;
	while (ft_strcmp(start->name, game->start))
			start = start->next;
	end = game->tmp_room;
	while (ft_strcmp(end->name, game->end))
			end = end->next;
	if (ft_find_path(game, start, end, &path) == 1)
		ft_print_path(game, beg, hist);
	else
		ft_putendl_fd("No trail", 2);
	return (game);
}

int			ft_treat_the_line(int *index, t_game **game, char *line)
{
	if (!(ft_strcmp(line, "")))
		return (ft_error("ERROR", "", -1));
	*index = ft_check_line(*index, line, *game);
	if (*index >= 0)
		*index = ft_save_line(*index, line, *game);
	if (*index == -1 && !(ft_strcmp(line + 2, "start")))
		(*game)->i_start = 1;
	else if (*index == -1)
		(*game)->i_end = 1;
	if (*index < 0)
		*index *= -1;
	return (0);
}

t_game		*ft_save_input(t_game *game, t_link **hist)
{
	char		*line;
	int			index;
	t_link		*new;

	ft_init_vars(&index, &line, &game);
	while (index < 3 && get_next_line(0, &line))
	{
		if (!(new = ft_new_link()))
			return (NULL);
		new->name = ft_strdup(line);
		if (*hist)
		{
			new->prev = *hist;
			(*hist)->next = new;
		}
		*hist = new;
		if (!(line = (char *)c_calls("trim", line)))
			return (NULL);
		if (!(is_comment(line)))
		{
			if (ft_treat_the_line(&index, &game, line) == -1)
				return (NULL);
		}
	}
	return (game = (index == 5) ? NULL : game);
}

int			ft_init_vars(int *index, char **line, t_game **game)
{
	*index = 0;
	*line = NULL;
	if (!((*game) = (t_game *)gmalloc(sizeof(t_game))))
		return (5);
	(*game)->nb_ant = 0;
	(*game)->i_start = 0;
	(*game)->i_end = 0;
	(*game)->start = NULL;
	(*game)->end = NULL;
	(*game)->room = NULL;
	(*game)->tmp_room = NULL;
	return (0);
}
