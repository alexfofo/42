/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afollin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 23:36:11 by afollin           #+#    #+#             */
/*   Updated: 2016/03/17 23:36:12 by afollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "lemin.h"

int			get_size_list_nighs(t_nigh *list)
{
	int			i;

	i = 0;
	while (list)
	{
		++i;
		list = list->next;
	}
	return (i);
}

t_path		*create_path_node(t_trail *trail, int sz)
{
	t_path		*path;

	path = (t_path *)malloc(sizeof(t_path));
	path->trails = trail;
	path->size = sz;
	path->used = 0;
	path->next = NULL;
	return (path);
}

t_trail		*create_trail_node(t_cell *cell)
{
	t_trail		*tr;

	tr = (t_trail *)malloc(sizeof(t_trail));
	tr->cell = cell;
	tr->next = NULL;
	return (tr);
}

void		free_dbl_tab(char **tab)
{
	int			i;

	i = -1;
	while (tab && tab[++i])
		free(tab[i]);
	free(tab);
	return ;
}
