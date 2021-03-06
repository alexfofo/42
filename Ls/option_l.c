/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_l.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afollin <afollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/05 14:55:43 by afollin           #+#    #+#             */
/*   Updated: 2015/03/05 14:55:44 by afollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

static void		just_for_norme_1(struct stat sb)
{
	if (S_ISDIR(sb.st_mode))
		ft_putstr("d");
	else if (S_ISLNK(sb.st_mode))
		ft_putstr("l");
	else if (S_ISSOCK(sb.st_mode))
		ft_putstr("s");
	else if (S_ISBLK(sb.st_mode))
		ft_putstr("b");
	else if (S_ISCHR(sb.st_mode))
		ft_putstr("c");
	else if (S_ISFIFO(sb.st_mode))
		ft_putstr("p");
	else
		ft_putstr("-");
	ft_putstr((sb.st_mode & S_IRUSR) ? "r" : "-");
	ft_putstr((sb.st_mode & S_IWUSR) ? "w" : "-");
	ft_putstr((sb.st_mode & S_IXUSR) ? "x" : "-");
	ft_putstr((sb.st_mode & S_IRGRP) ? "r" : "-");
	ft_putstr((sb.st_mode & S_IWGRP) ? "w" : "-");
	ft_putstr((sb.st_mode & S_IXGRP) ? "x" : "-");
	ft_putstr((sb.st_mode & S_IROTH) ? "r" : "-");
	return ;
}

static void		just_for_norme_2(struct stat sb, char *name, char *path)
{
	char			buf[1024];
	ssize_t			len;

	print_last_modif_time(sb.st_mtime);
	ft_putstr("\t");
	ft_putstr(name);
	if (S_ISLNK(sb.st_mode))
	{
		len = readlink(path, buf, sizeof(buf) - 1);
		if (len != -1)
		{
			buf[len] = '\0';
			ft_putstr(" -> ");
			ft_putstr(buf);
		}
		else
			ft_putstr("Error in -> symbolic link stuff");
	}
	return ;
}

static void		print_option_l(char *path, char *name)
{
	struct stat		sb;

	if (ft_is_dir(path) == 1)
		path = create_str_suffix(path, name);
	if (lstat(path, &sb) == -1)
	{
		perror("stat in printOptionL");
		return ;
	}
	just_for_norme_1(sb);
	ft_putstr((sb.st_mode & S_IWOTH) ? "w" : "-");
	ft_putstr((sb.st_mode & S_IXOTH) ? "x" : "-");
	ft_putstr(" ");
	ft_putnbr(sb.st_nlink);
	ft_putstr("\t");
	ft_putstr((getpwuid(sb.st_uid))->pw_name);
	ft_putstr("  ");
	ft_putstr((getgrgid(sb.st_gid))->gr_name);
	ft_putstr("\t");
	ft_putnbr(sb.st_size);
	ft_putstr("\t");
	just_for_norme_2(sb, name, path);
	ft_putstr("\n");
	return ;
}

void			option_lil_l(char *path, char **to_show, int tot, int nb_elem)
{
	struct stat		sb;
	int				i;

	i = -1;
	if (ft_is_dir(path) == 1)
	{
		ft_putstr("total ");
		ft_putnbr(tot);
		ft_putstr("\n");
	}
	i = -1;
	if (path[ft_strlen(path) - 1] != '/' && lstat(path, &sb) != -1)
	{
		if (S_ISLNK(sb.st_mode))
		{
			print_option_l(path, path);
			return ;
		}
	}
	while (++i < nb_elem)
	{
		print_option_l(path, to_show[i]);
	}
}
