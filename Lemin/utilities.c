/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afollin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/08 19:55:09 by afollin           #+#    #+#             */
/*   Updated: 2016/03/08 19:55:11 by afollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "lemin.h"

void		display_cell(t_cell *cell)
{
	t_nigh		*t;

	ft_putstr("Cell:	name: ");
	ft_putstr(cell->name);
	ft_putstr(" , x: ");
	ft_putnbr(cell->pos_x);
	ft_putstr(" , y: ");
	ft_putnbr(cell->pos_y);
	if (cell->nighs != NULL)
	{
		ft_putstr(" , nighs: [");
		if ((t = cell->nighs) == NULL)
			ft_putstr("NOTHING");
		while (t)
		{
			ft_putstr(t->cell->name);
			if (t->next != NULL)
				ft_putstr(", ");
			t = t->next;
		}
		ft_putstr("]");
	}
	ft_putstr("\n");
	return ;
}

void		display_res4(t_resources *res, t_path *tmp, t_trail *tmp2)
{
	ft_putendl("^^^^^^^^^^^");
	tmp = res->final_paths;
	if (tmp == NULL)
	{
		ft_putendl("NO PATHS");
		return ;
	}
	while (tmp != NULL)
	{
		tmp2 = tmp->trails;
		ft_putstr("Path:	(size: ");
		ft_putnbr(tmp->size);
		ft_putstr(")	");
		while (tmp2)
		{
			ft_putstr(tmp2->cell->name);
			if (tmp2->next)
				ft_putstr(" -> ");
			tmp2 = tmp2->next;
		}
		ft_putstr("\n");
		tmp = tmp->next;
	}
	ft_putendl("^^^^^^^^^^^");
}

void		display_res3(t_resources *res, t_path *tmp, t_trail *tmp2)
{
	ft_putendl("=========");
	tmp = res->paths;
	if (tmp == NULL)
	{
		ft_putendl("NO PATHS");
		return ;
	}
	while (tmp != NULL)
	{
		tmp2 = tmp->trails;
		ft_putstr("Path:	(size: ");
		ft_putnbr(tmp->size);
		ft_putstr(")	");
		while (tmp2)
		{
			ft_putstr(tmp2->cell->name);
			if (tmp2->next)
				ft_putstr(" -> ");
			tmp2 = tmp2->next;
		}
		ft_putstr("\n");
		tmp = tmp->next;
	}
	ft_putendl("=========");
}

void		display_res2(t_resources *res)
{
	t_tube		*tmp2;

	ft_putendl("=========");
	tmp2 = res->tubes;
	if (tmp2 == NULL)
		ft_putendl("NO TUBE");
	else
	{
		while (tmp2 != NULL)
		{
			ft_putstr("Tube:		");
			ft_putstr(tmp2->cell_one->name);
			ft_putstr("  ---  ");
			ft_putendl(tmp2->cell_two->name);
			tmp2 = tmp2->next;
		}
	}
	ft_putendl("=========");
	display_res3(res, NULL, NULL);
	display_res4(res, NULL, NULL);
	ft_putendl("*******************");
}

void		display_res(t_resources *res)
{
	t_cell		*tmp;

	tmp = res->cells;
	ft_putstr("*********************************\nnb_ant: ");
	ft_putnbr(res->nb_ant);
	ft_putstr("\nSTART: ");
	if (res->start != NULL)
		display_cell(res->start);
	else
		ft_putendl("NO START");
	ft_putstr("END: ");
	if (res->end != NULL)
		display_cell(res->end);
	else
		ft_putendl("NO END");
	ft_putendl("=========");
	if (tmp == NULL)
		ft_putendl("NO CELL");
	while (tmp != NULL)
	{
		display_cell(tmp);
		tmp = tmp->next;
	}
	ft_putendl("=========");
	display_res2(res);
}
