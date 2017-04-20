/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afollin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 16:41:32 by afollin           #+#    #+#             */
/*   Updated: 2016/03/07 16:41:34 by afollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "lemin.h"

int				go_gnl(int i, char **line)
{
	if (*line)
	{
		ft_bzero(*line, ft_strlen(*line));
		free(*line);
	}
	return (get_next_line(i, line));
}

void			init_resources(t_resources **resources)
{
	(*resources) = (t_resources *)malloc(sizeof(t_resources));
	(*resources)->nb_ant = 0;
	(*resources)->cells = NULL;
	(*resources)->tubes = NULL;
	(*resources)->start = NULL;
	(*resources)->end = NULL;
	(*resources)->paths = NULL;
	(*resources)->final_paths = NULL;
	return ;
}

t_resources		*check_syntax_and_get_resources(void)
{
	char		*line;
	t_resources	*resources;
	int			parsing_step;
	int			(*p[3]) (char *line, t_resources *resources);
	int			flag;

	line = NULL;
	init_resources(&resources);
	parsing_step = 0;
	p[0] = step_get_nb_ant;
	p[1] = step_get_cells;
	p[2] = step_get_tubes;
	while (go_gnl(0, &line))
	{
		ft_putendl(line);
		if ((flag = (*p[parsing_step])(line, resources)) == 1)
			++parsing_step;
		else if (!ft_strlen(line) || flag == -1)
			break ;
	}
	return (resources);
}

int				main(void)
{
	t_resources		*resources;
	char			*error_to_print;

	resources = check_syntax_and_get_resources();
	error_to_print = do_lemin_algo(resources);
	if (ft_strlen(error_to_print))
	{
		ft_putstr_fd(error_to_print, 2);
		return (-1);
	}
	print_walk(resources);
	return (0);
}
