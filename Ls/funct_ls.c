/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funct_ls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afollin <afollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/18 14:15:52 by afollin           #+#    #+#             */
/*   Updated: 2015/03/18 14:15:53 by afollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

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

static void		ls_fking_norme(char *path, char *options, char **args)
{
	int				i;
	char			**elems_to_show;
	int				nb_elem;
	int				tot_block;

	nb_elem = 0;
	if (ft_is_dir(path) == 1 && ft_strchr(options, 'l'))
		tot_block = compute_blocks(path, options);
	elems_to_show = get_elems_to_display(options, args[0], &nb_elem);
	if (nb_elem > 0)
	{
		elems_to_show = sort_elems(options, elems_to_show, path);
		if (ft_strchr(options, 'l'))
			option_lil_l(path, elems_to_show, tot_block, nb_elem);
		else
		{
			i = -1;
			while (elems_to_show && elems_to_show[++i]
				&& elems_to_show[i][0])
				ft_putendl(elems_to_show[i]);
		}
		if (ft_strchr(options, 'R') && ft_is_dir(path) == 1)
			option_big_r(path, options, 0);
	}
	return ;
}

static void		ls_fking_norme_mother(char *path, char *options, char **args)
{
	DIR				*directory;

	directory = opendir(path);
	if (directory == NULL && ft_is_dir(path) == 1)
	{
		ft_putstr_fd("ft_ls: ", 2);
		perror(get_dir_name_from_full_path(path));
	}
	else
	{
		if (directory)
			closedir(directory);
		if (ft_is_dir(path) == 1 && path[ft_strlen(path) - 1] != '/')
			path = create_str_suffix(path, "/");
		ls_fking_norme(path, options, args);
	}
	return ;
}

void			ft_ls(char *options, char **args, int ac, int flag)
{
	struct stat		st;
	char			*path;

	path = args[0];
	if (lstat(path, &st) == -1)
	{
		ft_putstr_fd("ft_ls: ", 2);
		perror(path);
		if (--ac > 0)
			ft_ls(options, ++args, ac, 0);
		return ;
	}
	if ((!flag || ac > 1) && ft_is_dir(path) == 1)
	{
		ft_putstr(path);
		ft_putendl(":");
	}
	ls_fking_norme_mother(path, options, args);
	if (--ac > 0)
	{
		ft_putstr("\n");
		ft_ls(options, ++args, ac, 0);
	}
	return ;
}
