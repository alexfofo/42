/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_final_paths.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afollin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 00:20:36 by afollin           #+#    #+#             */
/*   Updated: 2016/03/18 00:20:37 by afollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lemin.h"

int			p1_has_cell_in_p2(t_path *p1, t_path *p2, char *sn, char *en)
{
	t_trail		*tmp1;
	t_trail		*tmp2;

	tmp1 = p1->trails;
	while (tmp1)
	{
		tmp2 = p2->trails;
		while (tmp2)
		{
			if (!ft_strcmp(tmp1->cell->name, tmp2->cell->name))
			{
				if (ft_strcmp(tmp1->cell->name, sn)
					&& ft_strcmp(tmp1->cell->name, en))
					return (1);
			}
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
	return (0);
}

int			p_has_cell_in_aop(t_path *p, t_path **aop, int sz, t_resources *r)
{
	int			i;
	t_path		*tmp;

	i = -1;
	tmp = aop[0];
	while (++i < sz)
	{
		if (aop[i] == NULL)
			return (0);
		if (p1_has_cell_in_p2(p, aop[i], r->start->name, r->end->name))
			return (1);
	}
	return (0);
}

void		reset_array(t_path **arr, int sz)
{
	int		i;

	i = -1;
	while (++i < sz)
		arr[i] = NULL;
}

t_path		*create_lop(t_path **aop, int sz)
{
	int		i;
	t_path	*ret;
	t_path	*ret_fin;

	i = -1;
	while (++i < sz)
	{
		if (i == 0)
		{
			ret = create_path_node((aop[i])->trails, (aop[i])->size);
			ret_fin = ret;
		}
		else
		{
			ret->next = create_path_node((aop[i])->trails, (aop[i])->size);
			ret = ret->next;
		}
	}
	return (ret_fin);
}

t_path		*get_final_paths(t_resources *resources, int mw)
{
	t_path		*new_p[mw];
	t_path		*tmp_p;
	int			i;

	i = 0;
	reset_array(new_p, mw);
	if ((tmp_p = resources->paths) == NULL || mw == 0)
		return (NULL);
	while (i < mw)
	{
		if (!p_has_cell_in_aop(tmp_p, new_p, mw, resources))
			new_p[i++] = tmp_p;
		tmp_p = tmp_p->next;
		if (tmp_p == NULL)
		{
			if (i >= mw)
				break ;
			tmp_p = (new_p[0])->next;
			if (tmp_p == NULL && --mw > -1)
				tmp_p = resources->paths;
			reset_array(new_p, mw);
			i = 0;
		}
	}
	return (create_lop(new_p, mw));
}
