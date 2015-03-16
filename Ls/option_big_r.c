/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_big_r.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afollin <afollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/05 14:56:19 by afollin           #+#    #+#             */
/*   Updated: 2015/03/05 14:56:21 by afollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

static void		norme_big_r_1(DIR **d, char *path, char *options, char ***tmp)
{
	struct dirent	*drnt;
	char			*tmp_suffix;

	while ((drnt = readdir(*d)) != NULL)
	{
		tmp_suffix = create_str_suffix(path, drnt->d_name);
		if (ft_is_dir(tmp_suffix) && ft_strcmp(drnt->d_name, ".")
			&& ft_strcmp(drnt->d_name, ".."))
		{
			if ((!ft_strchr(options, 'a') && (drnt->d_name)[0] != '.')
				|| ft_strchr(options, 'a'))
				*tmp = extend_tab_str(*tmp, tmp_suffix);
		}
	}
	return ;
}

static int		get_size_tab_str(char **str)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (str && str[i] && str[i][0])
	{
		++i;
		++count;
	}
	return (count);
}

void			option_big_r(char *path, char *options, int count)
{
	DIR				*directory;
	struct stat		st;
	char			**tmp;

	directory = opendir(path);
	tmp = NULL;
	if (directory == NULL)
	{
		perror("el problemo ");
		return ;
	}
	norme_big_r_1(&directory, path, options, &tmp);
	closedir(directory);
	count = get_size_tab_str(tmp);
	if (tmp == NULL)
		return ;
	tmp = sort_in_ascii(tmp, count);
	if (options && ft_strchr(options, 't'))
		tmp = sort_option_lil_t(tmp, NULL, count);
	if (options && ft_strchr(options, 'r'))
		tmp = sort_option_lil_r(tmp, NULL, count);
	ft_putstr("\n");
	ft_ls(options, tmp, count, 0);
	return ;
}
