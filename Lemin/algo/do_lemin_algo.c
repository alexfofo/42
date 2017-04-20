/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_lemin_algo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afollin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 18:00:12 by afollin           #+#    #+#             */
/*   Updated: 2016/03/07 18:00:13 by afollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "lemin.h"

void	switch_path(t_path *p1, t_path *p2)
{
	t_trail		*tmp_trail;
	int			tmp_size;

	tmp_trail = p1->trails;
	tmp_size = p1->size;
	p1->trails = p2->trails;
	p1->size = p2->size;
	p2->trails = tmp_trail;
	p2->size = tmp_size;
}

int		sort_paths(t_resources *resources)
{
	t_path		*tmp;
	int			nb_path;
	int			i;

	nb_path = 0;
	i = 0;
	if (!resources->paths || !resources->paths->next)
		return (0);
	tmp = resources->paths;
	while (tmp && ++nb_path > 0)
		tmp = tmp->next;
	while (++i < nb_path)
	{
		tmp = resources->paths;
		while (tmp && tmp->next)
		{
			if (tmp->size > tmp->next->size)
				switch_path(tmp, tmp->next);
			tmp = tmp->next;
		}
	}
	return (0);
}

char	*do_lemin_algo(t_resources *resources)
{
	int			sns;
	int			ens;
	int			max_way;

	if (!resources->start || !resources->end
		|| set_nighs_cells(resources) == -1)
		return ("ERROR\n");
	if (get_paths(resources, NULL, resources->start, NULL) == -1)
		return ("ERROR\n");
	if (resources->paths == NULL)
		return ("ERROR\n");
	if (sort_paths(resources) == -1)
		return ("ERROR\n");
	sns = get_size_list_nighs(resources->start->nighs);
	ens = get_size_list_nighs(resources->end->nighs);
	max_way = sns < ens ? sns : ens;
	resources->final_paths = get_final_paths(resources, max_way);
	return ("");
}
