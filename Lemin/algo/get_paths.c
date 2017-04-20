/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_trails.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afollin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 18:01:04 by afollin           #+#    #+#             */
/*   Updated: 2016/03/15 18:01:05 by afollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "lemin.h"

void	add_to_resources(t_resources *resources, t_trail *new_path, int sz)
{
	t_path		*tmp;

	if (resources->paths == NULL)
		resources->paths = create_path_node(new_path, sz);
	else
	{
		tmp = resources->paths;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = create_path_node(new_path, sz);
	}
}

void	save_path(t_trail *tr_it, t_resources *resources)
{
	t_trail		*new_path;
	t_trail		*new_it;
	int			i;

	if (tr_it == NULL || resources == NULL)
		return ;
	new_path = NULL;
	new_it = NULL;
	i = 0;
	while (tr_it)
	{
		++i;
		if (new_path == NULL)
		{
			new_path = create_trail_node(tr_it->cell);
			new_it = new_path;
		}
		else
			new_it->next = create_trail_node(tr_it->cell);
		tr_it = tr_it->next;
		if (new_it->next != NULL)
			new_it = new_it->next;
	}
	add_to_resources(resources, new_path, i);
}

int		trail_contains(t_trail *trail, t_cell *cell)
{
	t_trail		*tmp;

	tmp = trail;
	if (tmp == NULL)
		return (0);
	while (tmp)
	{
		if (!ft_strcmp(tmp->cell->name, cell->name))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	cut_last_node(t_trail *trail)
{
	t_trail		*tmp;

	tmp = trail;
	if (tmp == NULL)
		return ;
	if (!tmp->next)
	{
		tmp->cell = NULL;
		free(tmp);
		return ;
	}
	while (tmp->next->next)
		tmp = tmp->next;
	tmp->next->cell = NULL;
	free(tmp->next);
	tmp->next = NULL;
}

int		get_paths(t_resources *res, t_trail *trail, t_cell *cell, t_nigh *tmp2)
{
	t_trail		*tmp;

	tmp = trail;
	while (tmp && tmp->next)
		tmp = tmp->next;
	if (tmp == NULL)
		trail = create_trail_node(cell);
	else
		tmp->next = create_trail_node(cell);
	if (!ft_strcmp(cell->name, res->end->name))
	{
		save_path(trail, res);
		return (1);
	}
	tmp2 = cell->nighs;
	while (tmp2)
	{
		if (!trail_contains(trail, tmp2->cell))
		{
			get_paths(res, trail, tmp2->cell, NULL);
			cut_last_node(trail);
		}
		tmp2 = tmp2->next;
	}
	return (0);
}
