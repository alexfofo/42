/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afollin <afollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/05 13:30:34 by afollin           #+#    #+#             */
/*   Updated: 2015/02/05 13:30:35 by afollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"

#include <stdlib.h>
#include <string.h>

#include <dirent.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <grp.h>
#include <pwd.h>



char	**get_elems_to_display(char *options, char *name, int *nb_elem)
{
	char			**elem_sorted;
	DIR				*directory;
	struct dirent	*drnt;
	char			*path_name;
	int				i;

	elem_sorted = NULL;
	directory = opendir(name);
	if (directory == NULL && !ft_is_dir(name))
	{
		*nb_elem = 1;
		elem_sorted = (char **)malloc(sizeof(char *) * 2);
		elem_sorted[0] = duplicate_str(name);
		elem_sorted[1] = duplicate_str("\0");
		return elem_sorted;
	}
	else if (directory == NULL)
	{
		*nb_elem = 0;
		elem_sorted = (char **)malloc(sizeof(char *) * 1);
		elem_sorted[0] = duplicate_str("\0");
		return elem_sorted;
	}
	i = 0;
	while ((drnt = readdir(directory)) != NULL)
	{
		path_name = (char *)malloc(sizeof(char) * (ft_strlen(name)
			+ ft_strlen(drnt->d_name) + 1));
		ft_bzero(path_name, ft_strlen(path_name));
		ft_strcat(path_name, name);
		ft_strcat(path_name, drnt->d_name);
		elem_sorted = sort_option_a(options, drnt->d_name, elem_sorted, &i);
		//free(pathName);
	}
	*nb_elem = i;
	closedir(directory);
	return elem_sorted;
}

char	**sort_elems(char *options, char **elem_to_sort, char *path)
{
	int			count;

	int i = -1;
	count = 0;
	while (elem_to_sort[count] && elem_to_sort[count][0])
		++count;

	elem_to_sort = sort_in_ascii(elem_to_sort, count);
	if (options && ft_strchr(options, 't'))
		elem_to_sort = sort_option_lil_t(elem_to_sort, path, count);

	if (options && ft_strchr(options, 'r'))
		elem_to_sort = sort_option_lil_r(elem_to_sort, NULL, count);

	return elem_to_sort;
}

static char		*get_dir_name_from_full_path(char *path)
{
	int			i;
	int			flag;

	i = -1;
	flag = 0;
	while (path[++i])
	{
		if (path[i] == '/')
			flag = 1;
	}
	if (flag == 0)
		return (path);
	while (path[--i] != '/')
		;
	return (&(path[++i]));
}

void	ft_ls(char *options, char **args, int ac, int flag)
{
	struct stat		st;
	int				tot_block;
	char			**elems_to_show;
	char			*path;
	int				i;
	int				nb_elem;
	DIR				*directory;

	path = args[0];
	nb_elem = 0;
	if (lstat(args[0], &st) == -1)
	{
		perror("stat in ft_ls");
		exit(1);
	}
	if ((!flag || ac > 1) && ft_is_dir(path))
	{
		ft_putstr(path);
		ft_putendl(":");
	}
	directory = opendir(path);
	if (directory == NULL && ft_is_dir(path))
	{
		ft_putstr("ft_ls: ");
		perror(get_dir_name_from_full_path(path));
	}
	else
	{
		if (directory)
			closedir(directory);
		if (ft_is_dir(path) && path[ft_strlen(path) - 1] != '/')
			path = create_str_suffix(path, "/");
		if (ft_is_dir(path) && ft_strchr(options, 'l'))
			tot_block = compute_blocks(path, options);
		elems_to_show = get_elems_to_display(options, args[0], &nb_elem);
		if (lstat(path, &st) == -1)
		{
			perror("ft_ls");
		}
		else if (nb_elem > 0)
		{
			elems_to_show = sort_elems(options, elems_to_show, path);
			if (ft_strchr(options, 'l'))
				option_lil_l(path, elems_to_show, tot_block, nb_elem);
			else
			{
				i = -1;
				while (elems_to_show && elems_to_show[++i] && elems_to_show[i][0])
					ft_putendl(elems_to_show[i]);
			}
			if (ft_strchr(options, 'R') && ft_is_dir(path))
				option_big_r(path, options);
		}
	}
	if (--ac > 0)
	{
		ft_putstr("\n");
		ft_ls(options, ++args, ac, 0);
	}
	return ;
}

char	**sort_files_and_dir(char **args, int nb_args)
{
	char	**newArgs;
	int		count;
	int		index;

	count = -1;
	index = -1;
	newArgs = (char **)malloc(sizeof(char *) * (nb_args + 1));
	while (++count < nb_args)
	{
		if (!ft_is_dir(args[count]))
			newArgs[++index] = duplicate_str(args[count]);
	}
	count = -1;
	while (++count < nb_args)
	{
		if (ft_is_dir(args[count]))
			newArgs[++index] = duplicate_str(args[count]);
	}
	newArgs[++index] = duplicate_str("\0");
	return (newArgs);
}

int		main(int argc, char **argv)
{
	char	*options;
	int		index;
	char	**args;

	index = 0;

	options = get_options(argc, argv, &index);

	args = get_args(argc, argv, index);
	if (args == NULL)
	{
		args = (char **)malloc(sizeof(char *) * 2);
		args[0] = duplicate_str("./\0");
		args[1] = duplicate_str("\0");
		++argc;
		if (index == 0)
			++index;
	}
	if (argc - index > 1)
	{
		args = sort_in_ascii(args, argc - index);
		if (options && ft_strchr(options, 't'))
			args = sort_option_lil_t(args, NULL, argc - index);
		if (options && ft_strchr(options, 'r'))
			args = sort_option_lil_r(args, NULL, argc - index);
		args = sort_files_and_dir(args, argc - index);
	}
	ft_ls(options, args, argc - index, 1);
	return (0);
}




































