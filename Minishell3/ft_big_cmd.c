/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afollin <afollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/26 18:42:53 by afollin           #+#    #+#             */
/*   Updated: 2014/02/07 18:48:34 by afollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <dirent.h>
#include "ft_minishell3.h"
#include "libft.h"

int			ft_is_exec(char *line, char **env)
{
	pid_t			father;
	char			**split;
	struct stat		*buf;

	buf = (struct stat *)malloc(sizeof(struct stat));
	split = ft_strsplit(line, ' ');
	if (lstat(split[0], buf) != -1)
	{
		father = fork();
		if (father > 0)
		{
			wait(&father);
			return (1);
		}
		if (father == 0)
		{
			execve(split[0], split, env);
			exit(0);
		}
	}
	return (0);
}

int			ft_check_known_cmd(char *line, char **env)
{
	pid_t			father;
	char			**tmp;
	char			**path;
	struct stat		*buf;
	char			*join;

	buf = (struct stat *)malloc(sizeof(struct stat));
	path = ft_strsplit("/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sb\
			in:/opt/X11/bin:/usr/texbin", ':');
	tmp = ft_strsplit(line, ' ');
	join = ft_strjoin(ft_strjoin(*path, "/"), tmp[0]);
	while (*path++ && lstat(join, buf) == -1)
		join = (*path ? ft_strjoin(ft_strjoin(*path, "/"), tmp[0]) : join);
	if (lstat(join, buf) == -1)
		return (0);
	if ((father = fork()) > 0)
	{
		wait(&father);
		return (1);
	}
	if (father == 0)
	{
		execve(join, tmp, env);
		exit(0);
	}
	return (0);
}

char		*ft_what_cmd(char *line)
{
	int			i;
	char		*dup;

	dup = ft_strdup(line);
	i = 0;
	while (dup[i] != '>' && dup[i])
		i++;
	dup[i] = '\0';
	return (ft_strtrim(dup));
}
