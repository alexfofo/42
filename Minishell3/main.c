/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afollin <afollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/21 16:13:13 by afollin           #+#    #+#             */
/*   Updated: 2014/02/07 18:30:36 by afollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <term.h>
#include <termios.h>
#include <termcap.h>
#include <sys/stat.h>
#include <dirent.h>
#include "ft_minishell3.h"
#include "libft.h"

int			main(int ac, char **av, char **env)
{
	char	**cp_env;
	char	**split;
	char	**splipe;

	ac = 0;
	av = NULL;
	cp_env = env;
	ft_init_terminal_mode();
	ft_launch(cp_env, split, splipe);
	return (0);
}

void		ft_check_ft(char *line, char **env)
{
	int			chev;

	chev = ft_ischevron(line);
	if (chev == 1)
	{
		if (ft_create_files(line))
			return ;
		ft_fill_files(line, env);
	}
	else if (*line == '\0')
		;
	else if (ft_strncmp(line, "cd", 2) == 0)
		ft_cd(line + 3, line, env);
	else if (ft_strncmp(line, "env", 3) == 0)
		ft_env(env);
	else if (ft_strncmp(line, "setenv", 6) == 0)
		ft_setenv(line, env);
	else if (ft_strncmp(line, "unsetenv", 8) == 0)
		ft_unsetenv(line, env);
	else if (ft_check_known_cmd(line, env))
		;
	else if (ft_is_exec(line, env))
		;
	else
		ft_else(line);
}

void		ft_else(char *line)
{
	ft_putstr("Command not found: ");
	ft_putendl(line);
}

void		ft_pipe(char **splipe, char *ret, char **env)
{
	int			fildes[2];
	pid_t		father;

	if (splipe[0] && splipe[1] && splipe[2])
	{
		ft_putstr_fd("sorry, only one pipe handled\n", 2);
		return ;
	}
	if (ret == NULL)
	{
		ret = (char *)malloc(sizeof(char) * 2);
		ret[0] = ' ';
		ret[1] = '\0';
	}
	else
		splipe[0] = ft_strjoin(splipe[0], ret);
	father = fork();
	if (father > 0)
		wait(&father);
	else if (father == 0)
	{
		ft_son(fildes, father, splipe, env);
		exit(0);
	}
}

void		ft_son(int *fildes, int father, char **splipe, char **env)
{
	if (pipe(fildes) == -1)
	{
		perror("bug on pipe:");
		return ;
	}
	father = fork();
	if (father > 0)
	{
		wait(&father);
		dup2(fildes[0], 0);
		close(fildes[1]);
		splipe++;
		ft_check_ft(*splipe, env);
		close(fildes[0]);
	}
	else if (father == 0)
	{
		close(fildes[0]);
		dup2(fildes[1], 1);
		ft_check_ft(ft_strtrim(splipe[0]), env);
		close(fildes[1]);
	}
}
