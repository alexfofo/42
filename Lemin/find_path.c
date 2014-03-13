/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afollin <afollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/11 11:51:50 by afollin           #+#    #+#             */
/*   Updated: 2014/03/12 16:53:22 by afollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lemin2.h"

int			ft_check_p(char *name, t_link *p)
{
	t_link	*move;

	move = p;
	while (move)
	{
		if (!ft_strcmp(move->name, name))
			return (0);
		move = move->prev;
	}
	return (1);
}

int			ft_find_path2(t_game *game, t_room *move, t_room *end, t_link **p)
{
	t_link		*rem;
	t_link		*new;
	t_room		*new_start;

	if (!(rem = NULL) && !(new = NULL) && !(new_start = NULL)
		&& move->tmp_link
		&& (!ft_strcmp(move->tmp_link->name, game->start)
			|| ((*p)->prev && !ft_strcmp(move->tmp_link->name,
										 (*p)->prev->name))))
		move->tmp_link = move->tmp_link->next;
	if (!move->tmp_link || ft_check_p(move->tmp_link->name, *p) == 0
		|| !(new = ft_new_link()))
		return (0);
	new->name = ft_strdup(move->tmp_link->name);
	rem = *p;
	new->prev = *p;
	(*p)->next = new;
	(*p) = (*p)->next;
	new_start = game->tmp_room;
	while (ft_strcmp(new_start->name, move->tmp_link->name))
		new_start = new_start->next;
	if (ft_find_path(game, new_start, end, p) == 1)
		return (1);
	*p = rem;
	return (2);
}
void		ft_find_little_path(t_game *game, t_link **p)
{
	t_link	*move;
	t_room	*start;

	start = game->tmp_room;
	while (ft_strcmp(start->name, game->start))
		start = start->next;
	move = *p;
	while (move->next)
		move = move->next;
	while (start->tmp_link->next)
		start->tmp_link = start->tmp_link->next;
	while (move->prev && ft_check_p(move->name, start->tmp_link))
		move = move->prev;
	if (*p == move)
		*p = (*p)->next;
	else
		*p = move;
}

int			ft_find_path(t_game *game, t_room *start, t_room *end, t_link **p)
{
	int			ret;

	ret = 0;
	if (start && start != end)
	{
		if (ft_check_p(end->name, start->tmp_link) == 0)
		{
			while (ft_strcmp(start->tmp_link->name, end->name))
				start->tmp_link = start->tmp_link->next;
		}
		while (start->tmp_link)
		{
			if ((ret = ft_find_path2(game, start, end, p)) == 0
				|| ret == 1)
				return (ret);
			start->tmp_link = start->tmp_link->next;
		}
	}
	if (start == end)
		return (1);
	return (0);
}
