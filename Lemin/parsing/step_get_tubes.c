/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step_get_tubes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afollin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 17:42:02 by afollin           #+#    #+#             */
/*   Updated: 2016/03/10 17:42:04 by afollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "lemin.h"

t_tube	*create_tube(char *n1, char *n2, t_resources *resources)
{
	t_tube		*tube;
	t_cell		*tmp;
	int			i;

	tube = (t_tube *)malloc(sizeof(t_tube));
	tmp = resources->cells;
	i = 0;
	while (tmp != NULL && i != 2)
	{
		if (!ft_strcmp(tmp->name, n1) || !ft_strcmp(tmp->name, n2))
		{
			if (i == 0)
				tube->cell_one = tmp;
			else if (i == 1)
				tube->cell_two = tmp;
			++i;
		}
		tmp = tmp->next;
	}
	if (i != 2)
		return (NULL);
	tube->next = NULL;
	return (tube);
}

void	add_tube_to_resources(t_tube *tube, t_resources *resources)
{
	t_tube		*tmp;
	t_tube		*tmp2;

	if (resources->tubes == NULL)
	{
		resources->tubes = tube;
		return ;
	}
	tmp = resources->tubes;
	while (tmp != NULL)
	{
		tmp2 = tmp;
		if ((!ft_strcmp(tube->cell_one->name, tmp->cell_one->name)
			&& !ft_strcmp(tube->cell_two->name, tmp->cell_two->name))
			|| (!ft_strcmp(tube->cell_one->name, tmp->cell_two->name)
			&& !ft_strcmp(tube->cell_two->name, tmp->cell_one->name)))
			return ;
		tmp = tmp->next;
	}
	tmp2->next = tube;
	return ;
}

int		cell_exists_in_cells(char *cell_name, t_resources *resources)
{
	t_cell		*tmp;

	tmp = resources->cells;
	while (tmp != NULL)
	{
		if (!ft_strcmp(tmp->name, cell_name))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int		step_get_tubes(char *line, t_resources *resources)
{
	char		**split;
	int			i;
	t_tube		*tube;
	int			flag;

	if ((flag = is_comment_or_command(line)) > 1)
		return (flag);
	else if (flag == 1)
		return (0);
	split = ft_strsplit(line, '-');
	i = 0;
	while (split && split[i])
		i++;
	if (i != 2 || !cell_exists_in_cells(split[0], resources)
		|| !cell_exists_in_cells(split[1], resources))
	{
		free_dbl_tab(split);
		return (-1);
	}
	tube = create_tube(split[0], split[1], resources);
	add_tube_to_resources(tube, resources);
	free_dbl_tab(split);
	return (0);
}
