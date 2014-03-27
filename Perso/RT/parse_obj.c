/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_obj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afollin <afollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/21 15:09:18 by afollin           #+#    #+#             */
/*   Updated: 2014/03/27 20:34:27 by afollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "rt.h"
#include "libft.h"

static int		ft_count_obj(char *file, t_obj *tobj)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		if (line[0] == '#')
		{
			if (!(ft_strncmp(line + 1, "box", 3)))
				tobj->nb[BOX]++;
			if (!(ft_strncmp(line + 1, "sphere", 6)))
				tobj->nb[SPHERE]++;
			if (!(ft_strncmp(line + 1, "plane", 5)))
				tobj->nb[PLANE]++;
			if (!(ft_strncmp(line + 1, "disk", 4)))
				tobj->nb[DISK]++;
			if (!(ft_strncmp(line + 1, "cone", 4)))
				tobj->nb[CONE]++;
			if (!(ft_strncmp(line + 1, "cylinder", 8)))
				tobj->nb[CYLINDER]++;
		}
	}
	close(fd);
	return (0);
}

static int		ft_check_file(char *file)
{
	if (file)
		return (0);
/*	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		if (*line == '#')
			ft_check_obj(fd, line);
	}
	close(fd);*/
	return (0);
}

static int		ft_init_type3(t_obj *tobj)
{
	int			i;

	i = -1;
	tobj->type = malloc(sizeof(void **) * (NB_TYPE + 1));
	tobj->type[NB_TYPE] = NULL;
	while (++i < NB_TYPE)
	{
		tobj->type[i] = (void **)malloc(sizeof(void *) * (tobj->nb[i] + 1));
		tobj->type[i][tobj->nb[i]] = NULL;
	}
	return (0);
}

static int		ft_fill_objs(char *file, t_obj *tobj)
{
	int				fd;
	char			*line;
	static int		i = -1;

	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		if (line[0] == '#')
		{
			if (!(ft_strncmp(line + 1, "box", 3)))
				i = ft_fill_box(fd, tobj);
			else if (!(ft_strncmp(line + 1, "sphere", 6)))
				i = ft_fill_sphere(fd, tobj);
			else if (!(ft_strncmp(line + 1, "plane", 5)))
				i = ft_fill_plane(fd, tobj);
			else if (!(ft_strncmp(line + 1, "disk", 4)))
				i = ft_fill_disk(fd, tobj);
			else if (!(ft_strncmp(line + 1, "cone", 4)))
				i = ft_fill_cone(fd, tobj);
			else if (!(ft_strncmp(line + 1, "cylinder", 8)))
				i = ft_fill_cylinder(fd, tobj);
		}
	}
	close(fd);
	return (i);
}

int				ft_parse_obj(char *file, t_obj *tobj)
{
	tobj->nb = (int *)malloc(sizeof(int) * 6);
	ft_check_file(file);
	ft_count_obj(file, tobj);
	ft_init_type3(tobj);
	if (ft_fill_objs(file, tobj) == -1)
	{
		ft_putendl_fd("Problem at parsing", 2);
		exit(0);
	}
	return (0);
}
