/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_nighs_cells.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afollin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 17:55:05 by afollin           #+#    #+#             */
/*   Updated: 2016/03/15 17:55:10 by afollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lemin.h"

t_nigh	*create_nigh(t_cell *cell)
{
	t_nigh		*nigh;

	nigh = (t_nigh *)malloc(sizeof(t_nigh));
	nigh->cell = cell;
	nigh->next = NULL;
	return (nigh);
}

void	add_c1_to_nighs_of_c2(t_cell *c1, t_cell *c2)
{
	t_nigh		*cells_iter;

	if ((cells_iter = c2->nighs) == NULL)
	{
		c2->nighs = create_nigh(c1);
		return ;
	}
	while (cells_iter->next != NULL)
		cells_iter = cells_iter->next;
	cells_iter->next = create_nigh(c1);
}

int		set_nighs_cells(t_resources *resources)
{
	t_tube		*tube_iter;

	if ((tube_iter = resources->tubes) == NULL)
		return (-1);
	while (tube_iter)
	{
		add_c1_to_nighs_of_c2(tube_iter->cell_one, tube_iter->cell_two);
		add_c1_to_nighs_of_c2(tube_iter->cell_two, tube_iter->cell_one);
		tube_iter = tube_iter->next;
	}
	return (0);
}
