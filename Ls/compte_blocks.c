/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compte_blocks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afollin <afollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/05 17:52:04 by afollin           #+#    #+#             */
/*   Updated: 2015/03/05 17:52:05 by afollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

int				compute_blocks(char *path, char *options)
{
	DIR				*directory;
	struct dirent	*drnt;
	struct stat		sa;
	char			*path_name;
	int				tot_block;

	tot_block = 0;
	directory = opendir(path);
	while (directory != NULL && (drnt = readdir(directory)) != NULL)
	{
		if (!ft_strchr(options, 'a') && drnt->d_name[0] == '.')
			continue ;
		path_name = duplicate_str(path);
		path_name = create_str_suffix(path_name, drnt->d_name);
		if (lstat(path_name, &sa) == -1)
		{
			perror("stat in compute_blocks");
			exit(EXIT_SUCCESS);
		}
		tot_block += sa.st_blocks;
	}
	if (directory)
		closedir(directory);
	return (tot_block);
}
