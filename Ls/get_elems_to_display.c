/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_elems_to_display.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afollin <afollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/18 14:19:51 by afollin           #+#    #+#             */
/*   Updated: 2015/03/18 14:19:52 by afollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

static char		**i_love_the_norminette(char *name, int *nb_elem, char **ret)
{
	if (!ft_is_dir(name))
	{
		*nb_elem = 1;
		ret = (char **)malloc(sizeof(char *) * 2);
		ret[0] = duplicate_str(name);
		ret[1] = duplicate_str("\0");
		return (ret);
	}
	*nb_elem = 0;
	ret = (char **)malloc(sizeof(char *) * 1);
	ret[0] = duplicate_str("\0");
	return (ret);
}

char			**get_elems_to_display(char *options, char *name, int *nb_elem)
{
	char			**elem_sorted;
	DIR				*directory;
	struct dirent	*drnt;
	char			*path_name;
	int				i;

	elem_sorted = NULL;
	directory = opendir(name);
	if (directory == NULL)
		return (i_love_the_norminette(name, nb_elem, elem_sorted));
	i = 0;
	while ((drnt = readdir(directory)) != NULL)
	{
		path_name = (char *)malloc(sizeof(char) * (ft_strlen(name)
			+ ft_strlen(drnt->d_name) + 1));
		ft_bzero(path_name, ft_strlen(path_name));
		ft_strcat(path_name, name);
		ft_strcat(path_name, drnt->d_name);
		elem_sorted = sort_option_a(options, drnt->d_name, elem_sorted, &i);
	}
	*nb_elem = i;
	closedir(directory);
	return (elem_sorted);
}
