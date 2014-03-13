/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chevron.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afollin <afollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/26 18:32:59 by afollin           #+#    #+#             */
/*   Updated: 2014/02/06 18:16:30 by afollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell3.h"
#include "libft.h"

int			ft_ischevron(char *line)
{
	while (*line)
	{
		if (*line == '>')
			return (1);
		line++;
	}
	return (0);
}

void		ft_fill_files(char *line, char **env)
{
	pid_t		father;
	char		*cmd;
	int			i;

	i = 1;
	cmd = ft_what_cmd(line);
	while (*line)
	{
		if (*line == '>')
		{
			if (*(++line) == '>')
			{
				i = 2;
				line++;
			}
			father = fork();
			if (father > 0)
				wait(&father);
			else
				ft_son_of_fill_files(line, i, cmd, env);
		}
		line++;
	}
}

void		ft_son_of_fill_files(char *line, int i, char *cmd, char **env)
{
	int			fd;

	fd = ft_open(ft_what_cmd(line), i);
	dup2(fd, 1);
	ft_check_ft(cmd, env);
	close(fd);
	exit(0);
}

int			ft_open(char *file, int i)
{
	int			fd;

	if (i == 1)
		fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU);
	else if (i == 2)
		fd = open(file, O_WRONLY | O_CREAT | O_APPEND, S_IRWXU);
	return (fd);
}

int			ft_create_files(char *line)
{
	char		*file;
	int			chev;

	chev = 0;
	while (*line)
	{
		if (chev != 0)
		{
			file = ft_what_cmd(line);
			close(ft_open(file, chev));
			chev = 0;
		}
		while (*line == '>')
		{
			chev++;
			line++;
		}
		if (chev > 2)
		{
			ft_putstr_fd("unknown: >>>...\n", 2);
			return (1);
		}
		line++;
	}
	return (0);
}
