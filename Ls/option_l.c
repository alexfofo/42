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
#include <unistd.h>

static void		print_last_modif_time(time_t mtime)
{
	time_t		cur_time;
	struct tm	*time_info;
	char		buffer[80];

	time(&cur_time);
	time_info = localtime(&mtime);
	if ((mtime + 15778463) < cur_time || (mtime - 3600) > cur_time)
		strftime(buffer, 80, "%b %d %Y", time_info);
	else
		strftime(buffer, 80, "%b %d %H:%M", time_info);
	ft_putstr(buffer);
	return ;
}

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
		{
			ft_putstr("Error in -> symbolic link stuff");
		}
	}
	return ;
}

static void		print_option_l(char *path, char *name)
{
	struct stat		sb;

	if (ft_is_dir(path))
		path = create_str_suffix(path, name);
	if (lstat(path, &sb) == -1)
	{
		perror("stat in printOptionL");
		return ;
		exit(EXIT_SUCCESS);
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
	int				i;

	i = -1;
	ft_putstr("total ");
	ft_putnbr(tot);
	ft_putstr("\n");
	i = -1;
	while (++i < nb_elem)
	{
		print_option_l(path, to_show[i]);
	}
}
