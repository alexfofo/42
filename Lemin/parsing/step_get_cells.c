/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step_get_cells.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afollin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 17:41:45 by afollin           #+#    #+#             */
/*   Updated: 2016/03/10 17:41:53 by afollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>
#include "libft.h"
#include "lemin.h"

t_cell	*create_cell(char *name, int x, int y)
{
	t_cell		*cell;

	cell = (t_cell *)malloc(sizeof(t_cell));
	cell->name = ft_strdup(name);
	cell->pos_x = x;
	cell->pos_y = y;
	cell->nighs = NULL;
	cell->next = NULL;
	return (cell);
}

int		add_cell_to_resources(t_cell *cell, t_resources *resources, int lf)
{
	t_cell		*tmp;
	t_cell		*tmp2;

	if (lf == 21)
		resources->start = cell;
	if (lf == 22)
		resources->end = cell;
	if (resources->cells == NULL)
	{
		resources->cells = cell;
		return (0);
	}
	tmp = resources->cells;
	while (tmp != NULL)
	{
		tmp2 = tmp;
		if (!ft_strcmp(tmp->name, cell->name))
			return (-1);
		if (tmp->pos_x == cell->pos_x && tmp->pos_y == cell->pos_y)
			return (-1);
		tmp = tmp->next;
	}
	tmp2->next = cell;
	return (0);
}

bool	str_is_an_int_valid(char *s)
{
	int			val;
	char		*val_str;

	val = ft_atoi(s);
	val_str = ft_itoa(val);
	if (ft_strcmp(s, val_str))
	{
		free(val_str);
		return (0);
	}
	free(val_str);
	return (1);
}

int		fill_resource_with_cell(char *line, t_resources *resources, int lf)
{
	char		**split;
	int			i;
	t_cell		*cell;

	split = ft_strsplit(line, ' ');
	i = 0;
	while (split && split[i])
		i++;
	if (i != 3)
	{
		free_dbl_tab(split);
		return (-1);
	}
	if (ft_strchr(split[0], '-'))
		return (-1);
	if (!str_is_an_int_valid(split[1]) || !str_is_an_int_valid(split[2]))
		return (-1);
	cell = create_cell(split[0], ft_atoi(split[1]), ft_atoi(split[2]));
	free_dbl_tab(split);
	return (add_cell_to_resources(cell, resources, lf));
}

int		step_get_cells(char *line, t_resources *resources)
{
	static int			flag = 0;
	int					last_flag;

	last_flag = flag;
	flag = is_comment_or_command(line);
	if (flag > 0)
	{
		if (flag > 20 && last_flag > 20)
			return (-1);
		if (last_flag > 20)
			flag = last_flag;
		if ((flag == 21 && resources->start != NULL)
			|| (flag == 22 && resources->end != NULL))
			return (-1);
		return (0);
	}
	if (step_get_tubes(line, resources) == 0)
	{
		if (last_flag > 20)
			return (-1);
		return (1);
	}
	if (fill_resource_with_cell(line, resources, last_flag) == -1)
		return (-1);
	return (0);
}
