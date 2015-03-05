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

// static char		**norme_big_r_1()
// {
// 	char			**tmp;
// 	return ;
// }

void	option_big_r(char *path, char *options)
{
	DIR				*directory;
	struct dirent	*drnt;
	struct stat		st;
	char			**tmp;
	char			*tmp_suffix;
	int				count;

	count = 0;
	directory = opendir(path);
	tmp = NULL;
	if (directory == NULL)
	{
		perror("el problemo ");
		return ;
	}
	while ((drnt = readdir(directory)) != NULL)
	{
		tmp_suffix = create_str_suffix(path, drnt->d_name);
		if (lstat(tmp_suffix, &st) == -1)
		{
			perror("stat in BigR");
			exit(1);
		}
		if (ft_is_dir(tmp_suffix) && ft_strcmp(drnt->d_name, ".")
			&& ft_strcmp(drnt->d_name, ".."))
		{
			tmp = extend_tab_str(tmp, tmp_suffix);
			++count;
		}
	}
	closedir(directory);
	if (tmp == NULL)
		return ;
	tmp = sort_in_ascii(tmp, NULL, count);
	if (options && ft_strchr(options, 't'))
		tmp = sort_option_lil_t(tmp, NULL, count);
	if (options && ft_strchr(options, 'r'))
		tmp = sort_option_lil_r(tmp, NULL, count);
	ft_putstr("\n");
	ft_ls(options, tmp, count, path);
	return ;
}
