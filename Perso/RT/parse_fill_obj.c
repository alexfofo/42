/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fill_obj.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afollin <afollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/21 15:54:08 by afollin           #+#    #+#             */
/*   Updated: 2014/03/27 18:29:35 by afollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "rt.h"
#include "libft.h"

int			ft_fill_box(int fd, t_obj *tobj)
{
	char		*line;
	int			i;
	static int	wich = 0;
	t_box		*ttbw;

	i = -1;
	if (!(((t_box ***)tobj->type)[BOX][wich] = (t_box *)\
			malloc(sizeof(t_box))))
		return (-1);
	ttbw = ((t_box ***)tobj->type)[BOX][wich];
	while (++i < 8)
	{
		if (get_next_line(fd, &line) <= 0 || line[0] == '#')
			return (-1);
		ttbw->sf = i == 0 ? ft_get_color(line) : ttbw->sf;
		ttbw->em = i == 1 ? ft_get_color(line) : ttbw->em;
		ttbw->xmin = i == 2 ? atof(line) : ttbw->xmin;
		ttbw->xmax = i == 3 ? atof(line) : ttbw->xmax;
		ttbw->ymin = i == 4 ? atof(line) : ttbw->ymin;
		ttbw->ymax = i == 5 ? atof(line) : ttbw->ymax;
		ttbw->zmin = i == 6 ? atof(line) : ttbw->zmin;
		ttbw->zmax = i == 7 ? atof(line) : ttbw->zmax;
	}
	wich++;
	return (0);
}

int			ft_fill_sphere(int fd, t_obj *tobj)
{
	char		*line;
	int			i;
	static int	wich = 0;
	t_sph		*ttsw;

	i = -1;
	if (!(((t_sph ***)tobj->type)[SPHERE][wich] = (t_sph *)\
			malloc(sizeof(t_sph))))
		return (-1);
	ttsw = ((t_sph ***)tobj->type)[SPHERE][wich];
	while (++i < 4)
	{
		if (get_next_line(fd, &line) <= 0 || line[0] == '#')
		{
			ft_putstr_fd("Hay un problema con la sphera", 2);
			return (-1);
		}
		ttsw->sf = i == 0 ? ft_get_color(line) : ttsw->sf;
		ttsw->em = i == 1 ? ft_get_color(line) : ttsw->em;
		ttsw->c = i == 2 ? ft_get_vect(line) : ttsw->c;
		ttsw->r = i == 3 ? atof(line) : ttsw->r;
	}
	wich++;
	return (0);
}

int			ft_fill_plane(int fd, t_obj *tobj)
{
	char		*line;
	int			i;
	static int	wich = 0;
	t_pla		*ttpw;

	i = -1;
	if (!(((t_pla ***)tobj->type)[PLANE][wich] = (t_pla *)\
			malloc(sizeof(t_pla))))
		return (-1);
	ttpw = ((t_pla ***)tobj->type)[PLANE][wich];
	while (++i < 4)
	{
		if (get_next_line(fd, &line) <= 0 || line[0] == '#')
		{
			ft_putstr_fd("Hay un problema con el plano", 2);
			return (-1);
		}
		ttpw->sf = i == 0 ? ft_get_color(line) : ttpw->sf;
		ttpw->em = i == 1 ? ft_get_color(line) : ttpw->em;
		ttpw->c = i == 2 ? ft_get_vect(line) : ttpw->c;
		ttpw->n = i == 3 ? ft_get_vect(line) : ttpw->n;
	}
	wich++;
	return (0);
}

int			ft_fill_disk(int fd, t_obj *tobj)
{
	char		*line;
	int			i;
	static int	wich = 0;
	t_dis		*ttdw;

	i = -1;
	if (!(((t_dis ***)tobj->type)[DISK][wich] = (t_dis *)\
			malloc(sizeof(t_dis))))
		return (-1);
	ttdw = ((t_dis ***)tobj->type)[DISK][wich];
	while (++i < 5)
	{
		if (get_next_line(fd, &line) <= 0 || line[0] == '#')
		{
			ft_putstr_fd("Hay un problema con el disco", 2);
			return (-1);
		}
		ttdw->sf = i == 0 ? ft_get_color(line) : ttdw->sf;
		ttdw->em = i == 1 ? ft_get_color(line) : ttdw->em;
		ttdw->c = i == 2 ? ft_get_vect(line) : ttdw->c;
		ttdw->n = i == 3 ? ft_get_vect(line) : ttdw->n;
		ttdw->r = i == 4 ? atof(line) : ttdw->r;
	}
	wich++;
	return (0);
}

int			ft_fill_cone(int fd, t_obj *tobj)
{
	char		*line;
	int			i;
	static int	wich = 0;
	t_con		*ttcow;

	i = -1;
	if (!(((t_con ***)tobj->type)[CONE][wich] = (t_con *)\
			malloc(sizeof(t_con))))
		return (-1);
	ttcow = ((t_con ***)tobj->type)[CONE][wich];
	while (++i < 7)
	{
		if (get_next_line(fd, &line) <= 0 || line[0] == '#')
			return (-1);
		ttcow->sf = i == 0 ? ft_get_color(line) : ttcow->sf;
		ttcow->em = i == 1 ? ft_get_color(line) : ttcow->em;
		ttcow->c = i == 2 ? ft_get_vect(line) : ttcow->c;
		ttcow->o = i == 3 ? atof(line) : ttcow->o;
		ttcow->rotx = i == 4 ? atof(line) : ttcow->rotx;
		ttcow->roty = i == 5 ? atof(line) : ttcow->roty;
		ttcow->rotz = i == 6 ? atof(line) : ttcow->rotz;
	}
	wich++;
	return (0);
}
