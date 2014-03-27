/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fill_obj2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afollin <afollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 17:52:05 by afollin           #+#    #+#             */
/*   Updated: 2014/03/27 18:30:09 by afollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "rt.h"
#include "libft.h"

int			ft_fill_cylinder(int fd, t_obj *tobj)
{
	char		*line;
	int			i;
	static int	wich = 0;
	t_cyl		*ttcyw;

	i = -1;
	if (!(((t_cyl ***)tobj->type)[CYLINDER][wich] = (t_cyl *)\
			malloc(sizeof(t_cyl))))
		return (-1);
	ttcyw = ((t_cyl ***)tobj->type)[CYLINDER][wich];
	while (++i < 5)
	{
		if (get_next_line(fd, &line) <= 0 || line[0] == '#')
		{
			ft_putstr_fd("Hay un problema con el cylindro", 2);
			return (-1);
		}
		ttcyw->sf = i == 0 ? ft_get_color(line) : ttcyw->sf;
		ttcyw->em = i == 1 ? ft_get_color(line) : ttcyw->em;
		ttcyw->c = i == 2 ? ft_get_vect(line) : ttcyw->c;
		ttcyw->r = i == 3 ? atof(line) : ttcyw->r;
		ttcyw->flag = i == 4 ? *line : ttcyw->flag;
	}
	wich++;
	return (0);
}
