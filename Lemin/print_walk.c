/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_walk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afollin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 00:42:36 by afollin           #+#    #+#             */
/*   Updated: 2016/03/19 00:42:37 by afollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "lemin.h"

t_ant		*create_ant(int id)
{
	t_ant	*ant;

	ant = (t_ant *)malloc(sizeof(t_ant));
	ant->id = id;
	ant->cur_path = NULL;
	ant->cur_trail = NULL;
	ant->next = NULL;
	return (ant);
}

int			nb_ant_handled_in_n_turn(t_path *path_it, t_path *cur)
{
	int			n;
	int			ret;

	n = cur->size - 1;
	ret = 0;
	while (path_it != cur)
	{
		ret += (n - (path_it->size - 2));
		path_it = path_it->next;
	}
	return (ret);
}

int			chose_path(t_ant *ant, t_resources *resources)
{
	t_path		*path_it;
	int			ant_left;

	ant_left = resources->nb_ant - ant->id + 1;
	path_it = resources->final_paths;
	while (path_it && path_it->used)
		path_it = path_it->next;
	if (path_it == NULL)
		return (0);
	if (ant_left <= nb_ant_handled_in_n_turn(resources->final_paths, path_it))
		return (0);
	ant->cur_path = path_it;
	ant->cur_trail = path_it->trails->next;
	path_it->used = 1;
	ft_putstr("L");
	ft_putnbr(ant->id);
	ft_putstr("-");
	ft_putstr(ant->cur_trail->cell->name);
	ft_putstr(" ");
	return (1);
}

int			ants_step_foreward(t_ant *ants_save, t_ant *last_ant)
{
	t_ant		*tmp;
	int			ret;

	ret = 0;
	tmp = ants_save;
	ft_putstr("\n");
	while (tmp != last_ant)
	{
		tmp->cur_path->used = 0;
		if (tmp->cur_trail->next)
		{
			tmp->cur_trail = tmp->cur_trail->next;
			ret = 1;
			ft_putstr("L");
			ft_putnbr(tmp->id);
			ft_putstr("-");
			ft_putstr(tmp->cur_trail->cell->name);
			ft_putstr(" ");
		}
		tmp = tmp->next;
	}
	return (ret);
}

void		print_walk(t_resources *resources)
{
	int			index_ant;
	t_ant		*ant;
	t_ant		*ants_save;

	index_ant = 0;
	while (++index_ant <= resources->nb_ant)
	{
		if (index_ant == 1)
		{
			ant = create_ant(index_ant);
			ants_save = ant;
		}
		else
		{
			ant->next = create_ant(index_ant);
			ant = ant->next;
		}
		if (chose_path(ant, resources) == 0)
		{
			ants_step_foreward(ants_save, ant);
			chose_path(ant, resources);
		}
	}
	while (ants_step_foreward(ants_save, NULL))
		;
}
